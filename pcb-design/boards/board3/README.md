# Golden Arduino - Custom Arduino-Compatible Development Board

**Course:** ECEN 3730 - PCB Design and Manufacture  
**Date:** Fall 2025  

## Overview

The Golden Arduino is a custom-designed, fully functional Arduino-compatible
development board based on the ATmega328 microcontroller. The board was
engineered to support standard Arduino Uno R3 shields, USB programming,
and direct compatibility with the Arduino IDE.

The project involved complete schematic design, PCB layout, assembly,
firmware configuration, and electrical validation.

## Technical Objectives

- Design an Arduino-compatible PCB using discrete components
- Implement USB-to-serial communication for programming
- Support bootloader flashing and IDE-based development
- Integrate onboard power regulation and reset circuitry
- Maintain mechanical compatibility with Arduino shields
- Apply industry-standard debugging and validation practices

## Hardware Architecture

- Microcontroller: ATmega328P  
- USB Interface: CH340 USB-to-Serial Converter  
- Power Regulation: Onboard 5V and 3.3V regulation  
- Clocking: External crystal oscillator  
- Debugging: Test points, isolation switches, status LEDs  
- Headers: Arduino Uno R3-compatible layout  

## Design and Implementation

### Schematic Design
The schematic was developed in Altium Designer and organized into functional
blocks including power management, microcontroller core, USB interface,
and I/O headers. Datasheets and reference designs were analyzed to ensure
correct electrical behavior and timing requirements.

### PCB Layout
The PCB was routed with attention to signal integrity, power distribution,
and manufacturability. High-current and sensitive analog paths were
separated where possible, and decoupling capacitors were placed close to
active devices.

### Assembly
All surface-mount and through-hole components were manually soldered.
Post-assembly inspection and continuity testing were performed prior
to powering the board.

## Firmware and Configuration

- Bootloader programmed using an external Arduino programmer
- Verified USB serial communication
- Tested with multiple Arduino IDE sketches
- Validated GPIO, PWM, ADC, and serial functionality

## Validation and Testing

Electrical validation was performed through comparative analysis with an
official Arduino Uno reference board.

Testing included:
- Switching noise and ground-bounce measurements
- Power rail noise analysis
- Current consumption characterization
- Functional firmware verification

The custom board demonstrated reduced on-die noise and improved switching
performance relative to the reference design.

## Results

- Successful bootloader installation and IDE integration
- Full compatibility with Arduino Uno shields
- Reliable programming and execution of sketches
- Improved noise performance under dynamic load
- Stable power regulation and reset behavior

## Lessons Learned

- Importance of PDN design and decoupling placement
- Impact of layout on switching noise and ground bounce
- Value of modular schematic organization
- Best practices for test-point placement and debugging
- Design-for-assembly considerations

## Files

- `board3-golden-arduino.pdf` - Full technical report and measurements  
- `images/` - Board photos and oscilloscope captures  
- `schematic.pdf` - Altium schematic  

---

For related projects, see the Instrument Droid (Board 4) and PCB laboratory
reports in this repository.
