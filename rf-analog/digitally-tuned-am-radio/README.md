# Digitally Tuned AM Radio - Capacitor Switching Receiver Front End

**Course:** Independent Study - RF Receiver Design  
**Advisor:** Prof. Eric Bogatin  
**Date:** January - May 2026  

## Overview

This project is an AM receiver front end that replaces the mechanical
variable capacitor with a 7-bit switched capacitor bank under Arduino
control. A rotary encoder steps through capacitor combinations, changing
the total capacitance presented to the LC tank and moving the resonant
frequency of the receiver.

The objective was to determine whether switched-capacitor tuning is a
viable alternative to both mechanical tuning and modern digital synthesis,
and to quantify what the approach costs in tank Q and tuning accuracy.

The project involved schematic design, capacitor bank sizing, firmware
development, breadboard prototyping, and full frequency-domain and
time-domain characterization. A two-layer PCB was designed in Altium and
submitted for fabrication but was not received before the project deadline,
so all measurements reported here are from the working breadboard build.

## Technical Objectives

- Replace mechanical tuning with digitally selected capacitance
- Implement a 7-bit capacitor bank giving 128 selectable combinations
- Drive capacitor selection from a rotary encoder through an Arduino
- Recover AM audio through envelope detection and audio amplification
- Characterize resonant frequency against theoretical prediction at each
  setting
- Quantify parasitic effects and their impact on usable tuning range

## Hardware Architecture

- Microcontroller: Arduino Uno  
- Analog Switches: Two SN74LV4066APWR quad SPST, approximately 100 ohm Ron  
- Capacitor Bank: 2, 4.7, 8, 16, 39, 82, and 150 pF, 301.7 pF total  
- Inductor and Antenna: 525 uH ferrite loopstick, serves as both  
- Detector: 1N5711WS-7-F Schottky diode envelope detector  
- Preamplifier: MCP6002-I/SN dual rail-to-rail op-amp, single 5 V supply  
- Audio Amplifier: LM386MX-1 driving an 8 ohm speaker  
- User Interface: PEC11R-4215F-S0024 rotary encoder with push-button  

Signal flow runs from the loopstick antenna to the tuned LC tank, then to
the Schottky detector, the MCP6002 preamplifier, the LM386 amplifier, and
finally the speaker.

## Design and Implementation

### Schematic Design
The schematic was developed in Altium Designer and organized into
functional regions covering Arduino header connections, the rotary encoder,
VREF biasing, the inductor and speaker connectors, two capacitor switching
blocks, the op-amp stage, and the LM386 amplifier with its detector
network.

### Capacitor Bank and Switching
Each capacitor connects from the TANK node to the A pin of its assigned
analog switch, with the B pin tied to ground, forming a switched shunt
branch across the tank. Closing a switch adds that capacitance in parallel
with the tank. Seven independent binary switches give 128 combinations
spanning roughly 0 pF to 301.7 pF. The unused channel on the second switch
IC has its control pin held low and both analog pins grounded to keep a
floating node from injecting noise.

### Analog Signal Chain
The MCP6002 is configured as a single-supply AC-coupled amplifier with a
gain of approximately 11, biased around a mid-rail VREF of 2.5 V generated
by a 100 kohm divider. The second op-amp is wired as a unity-gain buffer
with its input tied to VREF to prevent oscillation from a floating input.
The detector network uses a 47 kohm load and 1 nF filter capacitor for a
47 us time constant.

### PCB Layout
A two-layer PCB was laid out in Altium with decoupling capacitors placed
directly adjacent to IC supply pins, the TANK node kept as a short isolated
trace connecting only the inductor connector, capacitor switch outputs, and
diode anode, and analog and digital traces separated across the board. The
layout was submitted for fabrication but not received before the deadline.

## Firmware and Configuration

- Encoder position maintained as a 7-bit integer where each bit maps to one
  capacitor
- Falling-edge detection on encoder channel A with channel B sampled at the
  edge to determine direction
- 5 ms debounce delay applied after each step, with wraparound at 0 and 127
- Active capacitors and computed total capacitance printed to serial at
  115200 baud on each change

## Validation and Testing

All characterization was performed on the breadboard prototype using a
Digilent Analog Discovery 3 as both signal source and instrument. The
Wavegen output was injected into the TANK node through a small series
coupling capacitor so the source would not load the tank.

Testing included:
- Network Analyzer sweeps from approximately 100 kHz to 1.5 MHz to locate
  the resonant peak directly at each capacitor setting
- Impedance measurement of the loopstick to extract inductance and
  self-resonant frequency in isolation and installed in circuit
- Time-domain capture of the TANK and DET nodes with a synthetic AM carrier
  at 600 kHz, 1 kHz audio, and 50 percent modulation depth
- Audio bandwidth sweep to find the maximum recoverable modulation
  frequency

## Results

Tuning performance:
- Measured resonance from 297.1 kHz with all capacitors switched in to
  560.6 kHz with all switches open
- Measured values fall consistently below both the ideal prediction and the
  stray-corrected prediction, attributed to capacitor tolerance on the
  82 pF and 150 pF parts and to loading from the diode and op-amp input on
  the TANK node
- Digital tuning confirmed functional, with increasing switched capacitance
  lowering resonant frequency predictably across all 128 settings

Parasitic characterization:
- Breadboard stray capacitance extracted at approximately 154 pF from the
  all-switches-open baseline sweep
- Loopstick self-resonant frequency measured at 1.925 MHz in isolation,
  dropping to 914 kHz installed on the breadboard, which is what kept the
  prototype below the AM broadcast band
- Tank Q calculated at approximately 8.8 with switch Ron near 150 ohms at
  400 kHz, against 50 to 100 for a mechanical variable capacitor

Detection performance:
- AM envelope detection confirmed in the time domain, with individual
  carrier cycles visible inside the recovered envelope
- Audio recovered cleanly to 5 kHz, marginally detectable at 10 kHz, and
  not detectable above 10 kHz, which is adequate for the 5 to 8 kHz
  occupied by AM broadcast audio
- Strongest detected signal obtained at the 26 pF setting with a 600 kHz
  carrier

## Lessons Learned

- Parasitic capacitance dominates a high-impedance tank node. The 154 pF of
  breadboard stray exceeded half the switchable range, which is why the
  tuning band sat below the AM broadcast band instead of inside it.
- Switch on-resistance sets a hard ceiling on tank Q in a switched-capacitor
  design. Any future revision has to address Ron and Coff before anything
  else.
- Measuring the inductor in isolation and in circuit told two different
  stories. Characterizing the part on the bench instead of trusting the
  datasheet value was the single most useful debugging step in the project.
- Substituting an injected synthetic carrier for a live broadcast made the
  measurements repeatable and separated tuning behavior from antenna and
  sensitivity questions.

## Future Work

- Fabricate and assemble the Altium PCB. Shorter traces and a controlled
  dielectric environment should reduce stray capacitance and push the
  tuning range toward the 535 to 1705 kHz broadcast band.
- Add an RF preamplifier between the antenna and tank to improve
  sensitivity for live broadcast reception.
- Evaluate lower-Coff analog switches such as the Vishay DG611A, or
  logic-level MOSFETs, in place of the 4066.
- Characterize PCB stray capacitance with the same baseline technique and
  fold the offset into firmware for a calibrated frequency readout.

## Files

- `AM_Radio.pdf` - Full technical report and
  measurements  
---

For related work, see the PCB laboratory reports and the High Speed Digital
Design signal integrity projects in this repository.
