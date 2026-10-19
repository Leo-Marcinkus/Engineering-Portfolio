# Leo Marcinkus - Electrical Engineering Portfolio

<div class="intro" markdown="1">

Curated engineering projects, lab reports, and technical papers from my
undergraduate and accelerated master's studies in Electrical Engineering
at the University of Colorado Boulder. I focus on signal and power
integrity, hardware design, and custom IC design, with a large emphasis
on hands-on measurement, measurement-to-simulation correlation, and
troubleshooting.

<div class="now" markdown="1">

**Now:** Software Test Intern on the HyperLynx QA team at Siemens EDA in
Boulder, validating signal and power integrity workflows, and Research
Assistant in Prof. Kelvin Wagner's photonic neuromorphic systems group,
working on in-pixel mixed-signal circuits.

</div>

<a class="btn primary" href="Leo-Marcinkus-Resume.pdf" target="_blank" rel="noopener">Download Resume (PDF)</a>

</div>

## Current Research

<div class="card research" markdown="1">

<span class="badge">In progress</span>

### In-Pixel Phase Detector and Liquid-Crystal Driver
**Mixed-Signal IC Design, X-FAB XS018 180 nm, Prof. Kelvin Wagner**

Research Assistant in a photonic neuromorphic systems group developing an
in-pixel CMOS circuit for a 25 x 25 µm pixel array on the X-FAB XS018
180 nm image-sensor process. Each pixel uses a dual-tap pinned photodiode
and an auto-zeroed comparator to detect the phase of modulated light, then
drives a liquid-crystal pad above the pixel.

- Designing the 1.8 V to 3.3 V level shifter and latch that holds each
  pixel's decision for a 1 ms frame and drives the 3.3 V XOR pad driver
- Set up the Siemens EDA custom IC flow (Custom IC, Calibre DRC/LVS) and
  licensing on a Rocky Linux VM for the group

Design files will be added as the work progresses.

</div>

## Featured Projects

<div class="card hero" markdown="1">

### [Golden Arduino - Custom Arduino-Compatible Board](pcb-design/boards/board3/)
**PCB Design, Signal and Power Integrity, Altium**

<p align="center">
  <img class="cover" src="pcb-design/boards/board3/images/SolderedBoard.jpg" width="450">
</p>

A custom multi-layer ATmega328 board designed in Altium and benchmarked
against a stock Arduino Uno with an oscilloscope. Every layout decision was
verified by measurement: up to 1.7x lower ground bounce, 1.9x better on-die
supply isolation, 2.2x better isolation from external switching aggressors,
and 4.1x lower near-field emissions, from local decoupling placement,
tighter return paths, and via stitching.

</div>

<div class="grid" markdown="1">

<div class="card" markdown="1">

### [High-Speed Digital Measurement Labs](high-speed-digital/measurement-labs/)
**Signal Integrity, TDR, VNA, Keysight ADS**

<p align="center">
  <img src="high-speed-digital/measurement-labs/lab-2.3-resistive-termination-modeling/images/tdr-inductive-bumps.png" width="550">
</p>

Six graduate labs (ECEN 5534) pairing real scope, TDR, and VNA
measurements with ADS and field-solver models: a virtual TDR verified
within 5% from 10 Ω to 1 kΩ, microstrip Z0 measured to ±0.4 Ω against six
tools, and termination loop inductance growing from 2.6 to 9.0 nH with
via distance. Fall 2026.

</div>

<div class="card" markdown="1">

### [1T-1C DRAM Cell with Cross-Coupled Sense Amplifier](vlsi/dram-1t1c-sense-amplifier/)
**VLSI, Custom IC Design, Siemens Tanner**

<p align="center">
  <img src="vlsi/dram-1t1c-sense-amplifier/images/dram-schematic.png" width="500">
</p>

A 13-transistor two-cell DRAM array designed, simulated, and laid out in
Tanner on a Generic 250 nm process at 2.5 V. 57 mV pre-latch sense margin
against a 50 mV target, latched to a 1.5 V differential in about 300 ps,
with the full read and partial refresh sequence verified. ECEN 4012,
Spring 2026.

</div>

<div class="card" markdown="1">

### [Retro Glass Fuse Wireless Lamp](retro-fuse-lamp/)
**Embedded Systems, ESP32, Power Electronics**

<p align="center">
  <img class="cover" src="retro-fuse-lamp/retro-fuse-lamp-demo-web.gif" width="400">
</p>

A battery-powered lighting system built on ESP32 microcontrollers with
ESP-NOW wireless control, integrating Li-ion charging, power regulation,
and MOSFET LED switching into a compact hardware prototype.

</div>

<div class="card" markdown="1">

### [Mixed-Signal VGA/AGC](vlsi/vga-agc-mixed-signal/)
**Mixed-Signal IC Design, Cadence Virtuoso, sky130**

<p align="center">
  <img src="vlsi/vga-agc-mixed-signal/images/full-circuit-schematic.jpg" width="500">
</p>

A variable gain amplifier with automatic gain control on sky130: custom
3-bit flash ADCs digitize the signal, its amplitude, and a volume
setting, a Verilog-A core computes the gain, and a DAC and filter
reconstruct the output. Simulated end to end in Spectre. ECEN 4012,
Spring 2026.

</div>

<div class="card" markdown="1">

### [Instrument Droid - Measurement and Test Shield](pcb-design/boards/board4/)
**Mixed-Signal Design, System Integration**

<p align="center">
  <img class="cover" src="pcb-design/boards/board4/images/SolderedFunctioning2.jpg" width="400">
</p>

Multi-function instrumentation shield integrating DAC, ADC, programmable
load, and OLED interface for Thevenin equivalent measurement and system
validation.

</div>

<div class="card" markdown="1">

### [Labyrinth - FreeRTOS Tilt Maze](embedded-systems/rtos-labyrinth-stm32/)
**Real-Time Embedded Systems, FreeRTOS, STM32F429**

<p align="center">
  <img src="embedded-systems/rtos-labyrinth-stm32/images/systemview-baseline.png" width="500">
</p>

A six-task FreeRTOS game with gyro-driven physics, mutex- and
event-flag-coordinated tasks, and SEGGER SystemView profiling (60% idle
headroom under worst-case load), including root-causing a PendSV hard
fault to an FPU-context stack overflow. ECEN 3753, Spring 2026.

</div>

</div>

<div class="grid compact" markdown="1">

<div class="card" markdown="1">

### [Digitally Tuned AM Radio Receiver](rf-analog/digitally-tuned-am-radio/)
**RF and Analog, Independent Study**

AM front end with a 7-bit switched capacitor bank under Arduino control,
tuned from 297 to 561 kHz and characterized with a Digilent AD3.
Independent study under Prof. Eric Bogatin, Spring 2026.

</div>

<div class="card" markdown="1">

### [GAA Nanosheet FET Scaling Analysis](semiconductor-devices/research-reports/final-gaa-nanosheet/)
**Semiconductor Devices, Research**

Research paper analyzing gate-all-around nanosheet transistor
architectures for CMOS scaling beyond FinFET technology.

</div>

<div class="card" markdown="1">

### [STM32F429 Blackjack Touchscreen Game](embedded-systems/blackjack-stm32f429-project/)
**Embedded C, HAL Drivers, Touch UI**

Touchscreen Blackjack on the STM32F429DISC-1 with interrupt-driven input
and modular firmware architecture.

</div>

</div>

## Project Areas

<div class="grid" markdown="1">

<div class="tile" markdown="1">

### [RF and Analog Design](rf-analog/)

Receiver front ends, tuned circuits, and measurement-driven analog
characterization.

</div>

<div class="tile" markdown="1">

### [VLSI and Custom IC Design](vlsi/)

Full-custom design in Siemens Tanner and Cadence Virtuoso, mixed-signal
systems, and RTL-to-layout with Genus and Innovus.

</div>

<div class="tile" markdown="1">

### [PCB Design and Hardware](pcb-design/)

Multi-layer PCB design, fabrication, and validation emphasizing signal
and power integrity.

</div>

<div class="tile" markdown="1">

### [High-Speed Digital and Signal Integrity](high-speed-digital/)

Scope, TDR, and VNA measurement, HyperLynx eye diagrams, and SerDes
channel loss and FFE equalization.

</div>

<div class="tile" markdown="1">

### [Semiconductor Devices](semiconductor-devices/)

Characterization of diodes, MOSFETs, and photonic devices, plus research
on advanced CMOS architectures.

</div>

<div class="tile" markdown="1">

### [Electromagnetics, Waves, and Fields](electromagnetics-waves-fields/)

Applied electromagnetic modeling and simulation projects.

</div>

<div class="tile" markdown="1">

### [Embedded Systems](embedded-systems/)

STM32 projects, including a six-task FreeRTOS game profiled with
SystemView.

</div>

</div>

## Tools and Technologies

<div class="tools" markdown="1">

- **Programming and Analysis** C/C++, Python, MicroPython, SystemVerilog, Verilog-A, Tcl, MATLAB
- **Embedded Platforms** STM32, Arduino, ARM Cortex-M, ESP32
- **PCB and IC Design** Altium Designer, KiCad, Siemens Tanner (S-Edit, T-Spice, L-Edit), Siemens Custom IC, Calibre, Cadence Virtuoso, Spectre, Genus, Innovus
- **Signal and Power Integrity** HyperLynx (SI, PI, AMS, Advanced Solvers), Keysight ADS, Ansys Q2D
- **Simulation** LTspice, SIMetrix, SerDes Designer
- **Measurement** Oscilloscopes, TDR, VNA, SMUs, logic analyzers
- **Platforms** Linux (Debian, Arch, Rocky), Git

</div>

## Contact

<div class="contact" markdown="1">

- <a href="mailto:leomarcinkus@gmail.com" target="_blank" rel="noopener">leomarcinkus@gmail.com</a>
- <a href="mailto:leo.marcinkus@colorado.edu" target="_blank" rel="noopener">leo.marcinkus@colorado.edu</a>
- (630) 864-8802
- <a href="https://linkedin.com/in/leo-marcinkus-a18062340" target="_blank" rel="noopener">LinkedIn</a>
- <a href="https://boulder.joinhandshake.com/profiles/leomarcinkus" target="_blank" rel="noopener">Handshake</a>
- <a href="https://github.com/Leo-Marcinkus" target="_blank" rel="noopener">GitHub</a>

</div>
