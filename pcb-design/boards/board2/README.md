# Board 2 - PCB Layout Practices and Switching Noise Analysis

**Course:** ECEN 3730 - PCB Design and Manufacture  
**Date:** Fall 2025  

## Overview

Board 2 is a controlled experimental PCB designed to demonstrate how
layout and power distribution network (PDN) choices directly impact
switching noise, signal integrity, and overall system stability.

The board implements parallel digital circuits using both recommended
and intentionally poor design practices to enable direct performance
comparison under identical operating conditions.

## Technical Objectives

- Compare good and bad PCB layout practices on a single platform
- Evaluate the impact of grounding and decoupling placement
- Quantify power rail collapse and switching noise
- Analyze regulator filtering effectiveness
- Apply oscilloscope-based validation techniques

## Hardware Architecture

- Dual hex-inverter circuits (good vs. bad layout domains)  
- 555 timer clock source  
- 5V to 3.3V low-dropout regulator (LDO)  
- Selectable signal routing and power domains  
- Dedicated test points for noise and timing analysis  
- Two-layer PCB with segmented layout regions  

## Design and Implementation

### Schematic Design
The schematic was structured to isolate the two inverter domains while
maintaining identical functional behavior. This enabled direct
comparison of layout-dependent effects without confounding variables.

### PCB Layout
One half of the PCB implemented recommended practices including:
- Continuous return plane
- Close-placement decoupling capacitors
- Short current return paths

The opposing half intentionally violated these practices using:
- Fragmented ground routing
- Remote decoupling
- Extended return paths

This layout strategy created a controlled experimental platform.

### Assembly
All components were manually soldered and visually inspected. Continuity
and power integrity checks were performed prior to full operation.

## Measurement and Analysis

Electrical validation was conducted using high-bandwidth oscilloscopes
and differential measurement techniques.

Measurements included:
- Rise and fall time characterization
- Voltage rail collapse during switching
- Ground bounce evaluation
- Power rail noise analysis
- LDO output filtering comparison

Oscilloscope math functions were used to extract differential noise and
timing metrics.

## Results

Key findings included:
- Reduced rail collapse and noise in the optimized layout domain
- Improved rise/fall symmetry with proper grounding
- Lower switching noise with close decoupling placement
- Significant degradation in poorly routed domains
- Improved regulator stability with output filtering

Optimized layouts demonstrated up to multi-fold improvements in noise
and rail stability relative to poor layouts.

## Lessons Learned

- Layout decisions strongly influence digital performance
- Return path continuity is critical for noise control
- Decoupling placement is more important than capacitance value alone
- Regulator filtering improves supply stability
- Measurement methodology affects interpretation accuracy

## Files

- `report.pdf` — Full experimental analysis and results  
- `images/` — Board photos and oscilloscope captures  
- `schematic.pdf` — Altium schematic  
- `layout.pdf` — PCB layout files  
- `measurement-data/` — Processed scope measurements (if applicable)

---

For system-level integration projects, see the Golden Arduino (Board 3)
and Instrument Droid (Board 4) projects.
