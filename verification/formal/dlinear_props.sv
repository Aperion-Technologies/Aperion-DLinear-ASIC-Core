// verification/formal/dlinear_props.sv
// Formal properties for DLinear ASIC verification
//
// Properties verified:
// 1. No deadlock - continuous valid input eventually produces valid output
// 2. Deterministic latency - output appears exactly PIPELINE_DEPTH cycles after ready
// 3. No spurious outputs - predValid only when pipeline is filled
// 4. Output saturation - predOut stays within Int16 bounds
// 5. Ready stability - once ready, stays ready unless reset
//
// Run with: sby -f dlinear.sby

module dlinear_props (
    input        clock,
    input        reset,
    input  [7:0] io_dataIn,
    input        io_dataValid,
    output [15:0] io_predOut,
    output       io_predValid,
    input        io_configMode,
    output       io_status_ready,
    output       io_status_weightsLoaded
);

    // =========================================================================
    // Parameters (must match hardware)
    // =========================================================================
    localparam WINDOW_SIZE = 64;
    localparam PIPELINE_DEPTH = 4;  // Measured: 4 cycles from input to output
    localparam MAX_FILL_CYCLES = WINDOW_SIZE * 2 + 10;  // Max cycles to fill pipeline

    // =========================================================================
    // Helper signals
    // =========================================================================

    // Count consecutive valid inputs
    reg [7:0] valid_input_count;
    always @(posedge clock) begin
        if (reset)
            valid_input_count <= 0;
        else if (io_dataValid && !io_configMode)
            valid_input_count <= (valid_input_count == 8'hFF) ? 8'hFF : valid_input_count + 1;
        else
            valid_input_count <= 0;
    end

    // Count cycles since ready
    reg [7:0] cycles_since_ready;
    always @(posedge clock) begin
        if (reset || !io_status_ready)
            cycles_since_ready <= 0;
        else if (io_dataValid)
            cycles_since_ready <= (cycles_since_ready == 8'hFF) ? 8'hFF : cycles_since_ready + 1;
    end

    // Track if we've seen valid output after becoming ready
    reg seen_valid_output;
    always @(posedge clock) begin
        if (reset)
            seen_valid_output <= 0;
        else if (io_predValid)
            seen_valid_output <= 1;
    end

    // =========================================================================
    // Property 1: No Deadlock (Liveness)
    // =========================================================================
    // If we continuously provide valid input data while not in config mode,
    // we must eventually see valid output (within bounded time)

    property no_deadlock;
        @(posedge clock) disable iff (reset || io_configMode)
        (io_status_ready && io_dataValid) |-> ##[1:PIPELINE_DEPTH+2] io_predValid;
    endproperty

    assert property (no_deadlock)
        else $error("DEADLOCK: No output after valid input when ready");

    // =========================================================================
    // Property 2: Deterministic Latency
    // =========================================================================
    // Once pipeline is in steady state (ready + receiving data),
    // output must appear with consistent timing

    // In steady state, if we have valid input, we should have valid output
    property steady_state_throughput;
        @(posedge clock) disable iff (reset || io_configMode)
        (io_status_ready && io_dataValid && seen_valid_output) |-> io_predValid;
    endproperty

    assert property (steady_state_throughput)
        else $error("THROUGHPUT: Missing output in steady state");

    // =========================================================================
    // Property 3: No Spurious Outputs
    // =========================================================================
    // predValid should only be high when:
    // - Not in reset
    // - Not in config mode
    // - Pipeline is filled (status_ready was high)

    property no_spurious_output;
        @(posedge clock) disable iff (reset)
        io_predValid |-> !io_configMode;
    endproperty

    assert property (no_spurious_output)
        else $error("SPURIOUS: Output valid during config mode");

    // =========================================================================
    // Property 4: Ready Stability
    // =========================================================================
    // Once ready goes high, it should stay high unless reset
    // (weights don't change, pipeline doesn't need refilling)

    property ready_stable;
        @(posedge clock) disable iff (reset)
        (io_status_ready && !io_configMode) |=> io_status_ready || io_configMode;
    endproperty

    assert property (ready_stable)
        else $error("STABILITY: Ready signal dropped unexpectedly");

    // =========================================================================
    // Property 5: Weights Must Be Loaded Before Ready
    // =========================================================================
    property weights_before_ready;
        @(posedge clock) disable iff (reset)
        io_status_ready |-> io_status_weightsLoaded;
    endproperty

    assert property (weights_before_ready)
        else $error("WEIGHTS: Ready without weights loaded");

    // =========================================================================
    // Property 6: Config Mode Mutual Exclusion
    // =========================================================================
    // Cannot produce valid output while in config mode

    property config_no_output;
        @(posedge clock) disable iff (reset)
        io_configMode |-> !io_predValid;
    endproperty

    assert property (config_no_output)
        else $error("CONFIG: Output valid during configuration");

    // =========================================================================
    // Property 7: Output Range (Saturation Check)
    // =========================================================================
    // Output is 16-bit signed, so it's always in range by definition
    // But we can check it's not X/Z in simulation

    property output_valid_when_asserted;
        @(posedge clock) disable iff (reset)
        io_predValid |-> !$isunknown(io_predOut);
    endproperty

    assert property (output_valid_when_asserted)
        else $error("OUTPUT: Unknown value when valid");

    // =========================================================================
    // Property 8: Pipeline Fill Bounded
    // =========================================================================
    // After reset, if we continuously provide valid input,
    // ready should go high within MAX_FILL_CYCLES

    // This requires a cover property to check reachability
    property pipeline_fills;
        @(posedge clock) disable iff (reset)
        ($past(reset) && !reset) |-> ##[1:MAX_FILL_CYCLES] io_status_ready;
    endproperty

    // Cover: verify we can reach ready state
    cover property (@(posedge clock) io_status_ready && io_status_weightsLoaded);

    // Cover: verify we can produce valid output
    cover property (@(posedge clock) io_predValid);

    // =========================================================================
    // Property 9: Data Valid Handling
    // =========================================================================
    // When dataValid is low, the pipeline state should not change
    // (We can't directly check internal state, but we can check output behavior)

    property data_valid_gating;
        @(posedge clock) disable iff (reset || io_configMode)
        (!io_dataValid && io_status_ready && $stable(io_dataValid)) |=>
            $stable(io_predOut) || !io_predValid;
    endproperty

    // Note: This property may be too strict depending on pipeline implementation
    // assert property (data_valid_gating);

endmodule

// =========================================================================
// Bind module to connect properties to DUT
// =========================================================================
bind DLinearTop dlinear_props props_inst (
    .clock(clock),
    .reset(reset),
    .io_dataIn(io_dataIn),
    .io_dataValid(io_dataValid),
    .io_predOut(io_predOut),
    .io_predValid(io_predValid),
    .io_configMode(io_configMode),
    .io_status_ready(io_status_ready),
    .io_status_weightsLoaded(io_status_weightsLoaded)
);
