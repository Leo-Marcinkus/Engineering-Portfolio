# Golden Arduino - Custom Arduino-Compatible Development Board

**Course:** ECEN 3730 - PCB Design and Manufacture  
**Date:** Fall 2025  

## Overview

The Golden Arduino is a custom-designed, fully functional Arduino-compatible
development board based on the ATmega328 microcontroller. The board was
engineered to support standard Arduino Uno R3 shields, USB programming,
and direct compatibility with the Arduino IDE.

The project involved complete schematic design, PCB layout, assembly,
firmware configuration, and electrical validation. Every layout decision
intended to improve noise performance was verified by direct oscilloscope
comparison against an official Arduino Uno reference board rather than
being assumed correct.

## Technical Objectives

- Design an Arduino-compatible PCB using discrete components
- Implement USB-to-serial communication for programming
- Support bootloader flashing and IDE-based development
- Integrate onboard power regulation and reset circuitry
- Maintain mechanical compatibility with Arduino shields
- Improve power distribution and switching noise relative to the reference
  design
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
active devices. Local decoupling was placed directly at the supply pins
rather than routed around, shortening the high-frequency current loop that
supplies switching charge. Signal traces were kept over continuous
reference so return current follows directly underneath, and via stitching
was added around the switching sections to reduce loop area.

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
official Arduino Uno reference board. Both boards were driven with the
same switching stimulus and probed at equivalent points, with the stock
board used as the baseline for every comparison. Rising and falling edges
were recorded separately because they load the power distribution network
differently.

Testing included:
- Switching noise and ground-bounce measurements
- On-die supply rail noise analysis
- Board-as-aggressor coupling measurements
- Near-field emissions measurements
- Current consumption characterization
- Functional firmware verification

## Results

Measured improvement over the stock reference board:

- Ground bounce and switching noise: 1.66x better on the rising edge and
  1.71x better on the falling edge, attributed to local decoupling
  capacitor placement and tighter return paths
- On-die noise isolation: 1.88x better rising and 1.59x better falling,
  showing the PDN better protects the ATmega328 internal VDD rail from its
  own switching
- Board-as-aggressor coupling: 2.19x better rising and 2.00x better
  falling, indicating improved high-frequency isolation when external loads
  switch
- Near-field emissions: 4.14x better, attributed to tighter current loops
  and via stitching

Functional results:
- Successful bootloader installation and IDE integration
- Full compatibility with Arduino Uno shields
- Reliable programming and execution of sketches
- Stable power regulation and reset behavior

## Lessons Learned

- Importance of PDN design and decoupling placement
- Impact of layout on switching noise and ground bounce
- Loop area drives radiated emissions more strongly than it drives
  conducted noise, which is why the near-field result improved by a larger
  factor than the conducted measurements
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
