# verification/synthesis/Makefile
# Synthesis and gate-level simulation for DLinear ASIC
#
# Prerequisites:
#   brew install yosys
#   brew install verilator  (or use existing)
#
# Usage:
#   make synth        # Synthesize RTL to gate-level
#   make gate-sim     # Run gate-level simulation
#   make timing       # Generate timing report
#   make all          # Full flow

.PHONY: all synth gate-sim timing clean check-deps

# Paths
RTL_DIR = ../../hardware/generated
SYNTH_OUT = dlinear_synth.v
TEST_DIR = ../tests

# =============================================================================
# Default target
# =============================================================================
all: synth gate-sim

# =============================================================================
# Check dependencies
# =============================================================================
check-deps:
	@which yosys > /dev/null || (echo "ERROR: yosys not found" && exit 1)
	@echo "Dependencies OK"

# =============================================================================
# Synthesis
# =============================================================================
synth: check-deps
	@echo "=========================================="
	@echo "Synthesizing DLinear to gate-level..."
	@echo "=========================================="
	yosys -s synth.ys 2>&1 | tee synth.log
	@echo ""
	@if [ -f $(SYNTH_OUT) ]; then \
		echo "SUCCESS: Gate-level netlist: $(SYNTH_OUT)"; \
		wc -l $(SYNTH_OUT); \
	else \
		echo "ERROR: Synthesis failed"; \
		exit 1; \
	fi

# =============================================================================
# Gate-level simulation
# =============================================================================
gate-sim: synth
	@echo "=========================================="
	@echo "Running gate-level simulation..."
	@echo "=========================================="
	@# Create simulation directory
	mkdir -p gate_sim_build
	@# Copy netlist and cell models
	cp $(SYNTH_OUT) gate_sim_build/
	cp cells_sim.v gate_sim_build/ 2>/dev/null || echo "Note: cells_sim.v not found, using Yosys built-in cells"
	@# Run Cocotb with gate-level netlist
	cd gate_sim_build && \
	VERILOG_SOURCES="$(SYNTH_OUT)" \
	SIM=verilator \
	TOPLEVEL=DLinearTop \
	MODULE=tests.test_dlinear \
	PYTHONPATH=../.. \
	make -f $$(cocotb-config --makefiles)/Makefile.sim
	@echo ""
	@echo "Gate-level simulation complete."

# =============================================================================
# Quick gate-level test (functional only, no timing)
# =============================================================================
gate-quick: synth
	@echo "=========================================="
	@echo "Quick gate-level functional check..."
	@echo "=========================================="
	mkdir -p gate_sim_build
	cd gate_sim_build && \
	verilator --cc --exe --build -j 0 \
		-Wno-fatal \
		--top-module DLinearTop \
		../$(SYNTH_OUT) \
		--trace \
		-o Vdlinear_gate
	@echo "Gate-level model built successfully."

# =============================================================================
# Timing analysis
# =============================================================================
timing: synth
	@echo "=========================================="
	@echo "Timing Analysis (estimated)..."
	@echo "=========================================="
	@echo ""
	@# Extract timing from synthesis log
	@grep -E "(Delay|slack|path|timing)" synth.log 2>/dev/null || true
	@echo ""
	@echo "Gate count summary:"
	@cat dlinear_stats.txt 2>/dev/null || echo "Run 'make synth' first"
	@echo ""
	@echo "For accurate timing, use OpenSTA with proper liberty file:"
	@echo "  sta -exit timing.tcl"

# =============================================================================
# Generate timing constraints (SDC)
# =============================================================================
timing.sdc:
	@echo "# DLinear timing constraints" > timing.sdc
	@echo "# Target: 1 GHz (1ns period)" >> timing.sdc
	@echo "" >> timing.sdc
	@echo "create_clock -name clk -period 1.0 [get_ports clock]" >> timing.sdc
	@echo "set_input_delay -clock clk 0.2 [all_inputs]" >> timing.sdc
	@echo "set_output_delay -clock clk 0.2 [all_outputs]" >> timing.sdc
	@echo "" >> timing.sdc
	@echo "Generated timing.sdc"

# =============================================================================
# Area report
# =============================================================================
area: synth
	@echo "=========================================="
	@echo "Area Report"
	@echo "=========================================="
	@cat dlinear_stats.txt

# =============================================================================
# View synthesized design
# =============================================================================
view: synth
	@echo "Opening synthesized design in yosys show..."
	yosys -p "read_verilog $(SYNTH_OUT); show -format svg -prefix dlinear_gate DLinearTop"
	@echo "Generated dlinear_gate.svg"

# =============================================================================
# Clean
# =============================================================================
clean:
	rm -rf gate_sim_build
	rm -f $(SYNTH_OUT) dlinear_synth.json dlinear_stats.txt
	rm -f synth.log timing.sdc
	rm -f *.svg

# =============================================================================
# Help
# =============================================================================
help:
	@echo "DLinear ASIC Synthesis & Gate-Level Simulation"
	@echo ""
	@echo "Targets:"
	@echo "  make synth      - Synthesize RTL to gate-level netlist"
	@echo "  make gate-sim   - Run full gate-level simulation"
	@echo "  make gate-quick - Quick gate-level build check"
	@echo "  make timing     - Show timing analysis"
	@echo "  make area       - Show area report"
	@echo "  make view       - Visualize gate-level design"
	@echo "  make clean      - Remove generated files"
