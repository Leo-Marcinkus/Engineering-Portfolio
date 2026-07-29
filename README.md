# Leo Marcinkus - Electrical Engineering Portfolio

This repository holds various curated engineering projects, lab reports,
and technical papers I've completed during my undergraduate and accelerated
master's studies in Electrical Engineering here at the University of Colorado Boulder.

I primarily focus on hardware design, signal integrity, and
semiconductor devices, with a large emphasis on hands-on learning,
measurement analysis, and troubleshooting.

Currently a Software Test Intern on the HyperLynx QA team at Siemens EDA in
Boulder, working on signal integrity and power integrity workflow validation.

▶️ Download Resume (PDF)
📄 [Leo Marcinkus - Resume](Leo-Marcinkus-Resume.pdf)

---

# Featured Project

## :bulb: [Retro Glass Fuse Wireless Lamp – Battery-Powered ESP32 Lighting System](retro-fuse-lamp/)

<p align="center">
  <img src="retro-fuse-lamp/retro-fuse-lamp-demo.gif" width="550">
</p>

A battery-powered embedded lighting system built using ESP32 microcontrollers
and wireless ESP-NOW communication. The system integrates Li-ion battery
charging, power regulation, and MOSFET LED switching into a compact hardware
prototype with wireless control.

This project combines embedded firmware development, power electronics design,
and wireless debugging while emphasizing power efficiency and safe battery
management.

📂 Project Folder
`retro-fuse-lamp/`

---

## More Featured Projects :star:

### :star: [Digitally Tuned AM Radio Receiver](rf-analog/digitally-tuned-am-radio/)
**RF and Analog Design, Measurement Characterization, Independent Study**

An AM receiver front end that replaces the mechanical variable capacitor with a
7-bit switched capacitor bank under Arduino control. Characterized end to end
with a Digilent AD3: resonance measured from 297 kHz to 561 kHz across the
tuning range, 154 pF of breadboard stray capacitance extracted from a baseline
sweep, and AM audio recovered out to roughly 10 kHz. Independent study under
Prof. Eric Bogatin, Spring 2026.

📂 Project Folder
`rf-analog/digitally-tuned-am-radio/`

---

### :star: [1T-1C DRAM Cell with Cross-Coupled CMOS Sense Amplifier](vlsi/dram-1t1c-sense-amplifier/)
**VLSI, Custom IC Design, Siemens Tanner**

A 13-transistor two-cell DRAM array designed, simulated, and laid out in Siemens
Tanner S-Edit, T-Spice, and L-Edit on a Generic 250 nm process at 2.5 V.
Measured a 57 mV pre-latch sense margin against a 50 mV target, with the latch
amplifying that to a 1.5 V resolved differential in about 300 ps. Full read
sequence verified including precharge, charge sharing, latching, and partial
refresh. ECEN 4012, Spring 2026.

📂 Project Folder
`vlsi/dram-1t1c-sense-amplifier/`

---

### :star: [Golden Arduino - Custom Arduino-Compatible Board](pcb-design/boards/board3/)
**PCB Design, Altium, Embedded Hardware**

<p align="center">
  <img src="pcb-design/boards/board3/images/SolderedBoard.jpg" width="400">
</p>

Designed and assembled a custom Arduino-compatible development board with
optimized power distribution, bootloader integration, and full IDE compatibility.
Measured against a stock reference board with an oscilloscope: up to 1.7x lower
ground bounce, 1.9x better on-die supply isolation, 2.2x better isolation from
external switching aggressors, and 4.1x lower near-field emissions.

📂 Project Folder
`pcb-design/boards/board3/`

---

### :star: [Instrument Droid - Measurement and Test Shield](pcb-design/boards/board4/)
**Mixed-Signal Design, System Integration**

<p align="center">
  <img src="pcb-design/boards/board4/images/SolderedFunctioning2.jpg" width="400">
</p>

Multi-function instrumentation shield integrating DAC, ADC, programmable load,
and OLED interface for Thevenin equivalent measurement and system validation.

📂 Project Folder
`pcb-design/boards/board4/`

---

### :star: [GAA Nanosheet FET Scaling Analysis](semiconductor-devices/research-reports/final-gaa-nanosheet)
**Semiconductor Devices, Research Analysis**
Technical research paper analyzing gate-all-around nanosheet transistor
architectures for advanced CMOS scaling beyond FinFET technology.

📂 Project Folder
`semiconductor-devices/research-reports/final-gaa-nanosheet/`

---

### :star: [STM32F429 Blackjack Touchscreen Game](embedded-systems/blackjack-stm32f429-project)
**Embedded Systems, C, HAL Drivers, Touch UI**
Custom embedded application developed on the STM32F429DISC-1 platform featuring
a touchscreen-based Blackjack game, interrupt-driven input, and modular firmware
architecture.

📂 Project Folder
`embedded-systems/blackjack-stm32f429-project/`

---

## Project Areas

### [RF and Analog Design](rf-analog/)
Receiver front ends, tuned circuits, and measurement-driven analog
characterization.
`rf-analog/`

### [VLSI and Custom IC Design](vlsi/)
Transistor-level circuit design, SPICE simulation, and physical layout in
Siemens Tanner.
`vlsi/`

### [PCB Design and Hardware](pcb-design/)
Multi-layer PCB design, fabrication, and validation projects emphasizing
signal integrity and power integrity.
`pcb-design/`

### [High-Speed Digital & Signal Integrity](high-speed-digital/)
Time- and frequency-domain analysis of interconnects, decoupling networks,
and multi-GHz digital systems.
`high-speed-digital/`

### [Semiconductor Devices](semiconductor-devices/)
Device characterization experiments and research papers covering diodes,
MOSFETs, photonics, and advanced CMOS architectures.
`semiconductor-devices/`

### [Electromagnetics, Waves, and Fields](electromagnetics-waves-fields)
Applied electromagnetic modeling and simulation projects.
`electromagnetics-waves-fields/`

### [Embedded Systems](embedded-systems/)
STM32 and microcontroller-based projects involving real-time firmware,
peripheral drivers, and user interfaces.
`embedded-systems/`

---

## Tools and Technologies

- Programming/Analysis: C/C++, Python, MicroPython, SystemVerilog, MATLab
- Embedded Platforms: STM32, Arduino, ARM Cortex-M, ESP32
- EDA and Layout: Altium Designer, Siemens Tanner (S-Edit, T-Spice, L-Edit), Cadence Virtuoso
- Simulation: LTSpice, SIMetrix, Keysight ADS
- Measurement: Oscilloscopes, network analyzer sweeps, SMUs, Logic Analyzers
- Softwares: ADS, HyperLynx, Altium Designer

---

## Contact

- Email: leomarcinkus@gmail.com, leo.marcinkus@colorado.edu
- Phone: (630) 864-8802
- Handshake: https://boulder.joinhandshake.com/profiles/leomarcinkus
- GitHub: https://github.com/Leo-Marcinkus

---
