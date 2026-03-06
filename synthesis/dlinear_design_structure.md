# OpenLane Design Structure

## Design Statistics
- Module: DLinearTop
- Window Size: 64 ticks
- Data Width: 8-bit (Int8)
- Weight Width: 8-bit (Int8)
- Accumulator: 24-bit (Int24)
- Pipeline Depth: 4 cycles
- Parallel MACs: 128 (64 trend + 64 seasonal)

## Configuration Parameters (config.json)

| Parameter | Value | Rationale |
|-----------|-------|-----------|
| `CLOCK_PERIOD` | 2.0 ns | 500 MHz target (conservative start) |
| `DIE_AREA` | 1000x1000 µm² | 1mm² die for 128 MACs + logic |
| `FP_CORE_UTIL` | 40% | Low density for routing margin |
| `PL_TARGET_DENSITY` | 0.45 | Balanced placement density |
| `SYNTH_STRATEGY` | AREA 0 | Area optimization (minimize transistors) |
| `SYNTH_MAX_FANOUT` | 8 | Limited fanout for timing |

## Target Specs
- Frequency: 500 MHz (can push to 1 GHz if timing passes)
- Die Size: 1 mm²
- Technology: Sky130 (130nm)
- Standard Cells: sky130_fd_sc_hd
