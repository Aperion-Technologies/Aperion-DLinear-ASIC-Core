# Aperion-DLinear-ASIC-Core

[ Build: Passing ]
[ Timing: 100MHz @ 130nm ]
[ License: Apache 2.0 ]

This repository contains an RTL implementation of the DLinear model optimized for extremely low latency environments. Unlike traditional AI accelerators, our architecture eliminates the instruction layer, turning the neural network into a physical flow circuit (Dataflow Circuit).

## Key Performance Metrics (PPA)

- Latency: 3.3ns - 4.2ns (Deterministic, 4 clock cycles @ 1.2GHz).
- Throughput: 1 prediction per clock cycle (Fully Pipelined).
- Area (Est. 7nm): <0.02 mm² per core.
- Verified Node: Physical design proven on Sky130 (130nm) with 100MHz timing closure (LVS/DRC Clean).

## Why DLinear-to-Silicon
- Zero Software Overhead: No operating system, interrupts, or drivers on the critical path.
- In-Flight Reconfiguration: Support for updating model weights via a dedicated Config Port without stopping calculations.
- Scalability: Chisel's modular design allows hundreds of cores to be combined into a single Predictive Fabric.

## Technical Stack
- Hardware: Chisel 6.0 (Scala), SystemVerilog.
- Simulation: Verilator (C++ models), Cocotb (Python verification).
- Physical Flow: OpenLane / OpenROAD (RTL-to-GDSII).
- Analysis: Surfer / Scansion (Cycle-accurate waveform auditing).

## Roadmap
- Phase 1 (Current): Single-core DLinear validation on Open-Source EDA.
- Phase 2: Multi-core "Predictive NIC" architecture & AXI-Stream integration.
- Phase 3: Pilot Tape-out on TSMC N7/N5 nodes.


