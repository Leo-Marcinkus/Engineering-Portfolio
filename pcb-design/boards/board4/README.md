# Instrument Droid - Multi-Function Measurement and Test Shield

**Course:** ECEN 3730 - PCB Design and Manufacture  
**Date:** Fall 2025  

## Overview

The Instrument Droid is a custom-designed, multi-function measurement and
test shield developed for use with the Golden Arduino (Board 3) platform.
The system functions as a programmable electronic instrument capable of
characterizing voltage sources and measuring Thevenin equivalent
parameters.

This project integrates analog, digital, and embedded subsystems into a
single validated hardware platform.

## Technical Objectives

- Design an Arduino-compatible instrumentation shield
- Implement programmable current sourcing and voltage measurement
- Integrate DAC and ADC subsystems
- Support multiple input power sources
- Provide real-time user feedback and visualization
- Validate performance against a breadboard reference prototype

## Hardware Architecture

- Host Platform: Golden Arduino (ATmega328P)  
- Digital-to-Analog Converter (DAC) for current control  
- Analog-to-Digital Converter (ADC) for voltage and current sensing  
- MOSFET-based programmable load stage  
- Precision current-sense resistors (multi-range selection)  
- OLED display for data visualization  
- RGB status LEDs and audible buzzer  
- Terminal block, barrel jack, and USB input interfaces  

## System Design and Implementation

### Schematic Development
The schematic was organized into modular functional blocks including
current regulation, measurement front-end, user interface, and power
distribution. Reference designs and datasheets were analyzed to ensure
stability, accuracy, and reliability.

### PCB Layout
The multi-layer PCB layout emphasized clean routing of sensitive analog
signals, controlled current paths, and isolation between high-current and
low-noise domains. Grounding and decoupling strategies were applied to
minimize coupling and measurement error.

### Assembly and Integration
All components were manually assembled and inspected. Subsystems were
tested incrementally prior to full system integration.

## Firmware and Data Processing

Custom Arduino firmware was developed to coordinate measurement,
control, and visualization tasks.

Key features include:
- Programmable load stepping
- Automated data acquisition
- Real-time display updates
- Serial data logging
- Audible and visual status indicators

Measurement algorithms compute:
- Load current
- Load voltage
- Thevenin voltage
- Thevenin resistance

## Validation and Testing

System validation was performed using multiple voltage sources and
operating modes.

Testing included:
- DAC and op-amp output verification
- ADC calibration and linearity checks
- Constant-current regulation validation
- Multi-range current sensing evaluation
- Comparison with breadboard prototype data

Measured results closely matched reference measurements, confirming
correct system operation.

## Results

- Accurate Thevenin resistance measurement across multiple sources
- Stable closed-loop current regulation
- Reliable multi-range sensing operation
- Functional user interface and feedback
- Consistent agreement with prototype data

A minor mechanical layout issue (mirrored OLED header orientation) was
identified and documented for future revision.

## Lessons Learned

- Importance of analog/digital isolation in mixed-signal systems
- Tradeoffs between layout density and assembly reliability
- Benefits of incremental firmware validation
- Value of early prototype correlation
- Design-for-test and design-for-debug practices

## Files

- `board4-instrument-droid.pdf` - Full system design and validation report  
- `images/` - Assembly photos and measurement screenshots  
- `schematic.pdf` - Altium schematic  

---

For related hardware platforms, see the Golden Arduino (Board 3) project
and supporting PCB laboratory reports.
