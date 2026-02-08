# Board 1 - 555 Timer Signal Generation and Validation Platform

**Course:** ECEN 3730 - PCB Design and Manufacture  
**Date:** Fall 2025  

## Overview

Board 1 is a foundational PCB project focused on designing, assembling,
and validating a stable signal-generation platform using a 555 timer
integrated circuit.

The board generates a controlled square-wave output and drives multiple
LED loads, enabling detailed analysis of timing behavior, loading
effects, and power integrity.

This project established core practices in schematic design, layout,
assembly, and electrical validation.

## Technical Objectives

- Design a 555 timer-based square-wave generator
- Implement selectable LED loads with varying resistances
- Integrate power and signal isolation switches
- Provide accessible test points for measurement
- Validate electrical performance against theoretical predictions

## Hardware Architecture

- 555 timer configured for astable operation  
- Multiple LED loads with selectable resistances  
- Power and signal isolation switches  
- Dedicated test points for probing  
- Onboard power indicator LED  
- Two-layer PCB layout  

## Design and Implementation

### Schematic Development
The schematic was designed in Altium Designer using modular functional
blocks for timing generation, output loading, and power management.
Component values were selected based on analytical calculations and
reference data.

### PCB Layout
The PCB layout emphasized clean routing, logical component placement,
and accessibility for probing and debugging. Trace widths and spacing
were selected to ensure reliable operation and ease of assembly.

### Assembly
All components were manually soldered and inspected. Initial power-up
testing was performed under controlled conditions to verify correct
operation.

## Measurement and Validation

Electrical validation was performed using oscilloscopes and digital
multimeters.

Measurements included:
- Output frequency and duty cycle
- Rise and fall time characterization
- Peak-to-peak voltage analysis
- Load-dependent voltage variation
- Power rail noise evaluation

Experimental results were compared against analytical predictions and
simulation estimates.

## Results

- Output frequency and duty cycle matched design targets
- Stable square-wave generation under varying load conditions
- Predictable voltage drop across LED loads
- Verified switching behavior and timing performance
- Identified moderate power rail noise for later optimization

## Lessons Learned

- Importance of validating theoretical calculations experimentally
- Effects of load impedance on timing circuits
- Value of accessible test-point placement
- Early exposure to signal integrity considerations
- Best practices for systematic debugging

## Files

- `board1-555-timer-platform.pdf` - Full design and measurement report  
- `images/` - Assembly photos and oscilloscope captures  

---

For advanced PCB and system-integration projects, see Boards 2, 3, and 4
in this repository.
