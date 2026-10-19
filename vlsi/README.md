# VLSI and Custom IC Design

Transistor-level and mixed-signal IC design from ECEN 4012 (Design of
VLSI Circuits, Spring 2026), covering full-custom schematic and layout,
mixed-signal system simulation, and the RTL-to-layout pushbutton flow.

## [1T-1C DRAM Cell with Cross-Coupled CMOS Sense Amplifier](dram-1t1c-sense-amplifier/)
**Full-Custom Design, Siemens Tanner, Generic 250 nm**

<p align="center">
  <img src="dram-1t1c-sense-amplifier/images/dram-schematic.png" width="450">
</p>

A 13-transistor two-cell DRAM array designed, simulated, and laid out in
Tanner S-Edit, T-Spice, and L-Edit at 2.5 V. Measured a 57 mV pre-latch
sense margin against a 50 mV target, amplified to a 1.5 V resolved
differential, with destructive read and partial refresh verified on both
cells.

📂 Project Folder
`vlsi/dram-1t1c-sense-amplifier/`

---

## [Mixed-Signal VGA/AGC](vga-agc-mixed-signal/)
**Mixed-Signal Design, Cadence Virtuoso, sky130**

A variable gain amplifier with automatic gain control built from custom
3-bit flash ADCs, a self-mix amplitude estimator, a Verilog-A gain core,
and a DAC, simulated end to end in Spectre. The output amplitude steps
down as the measured input amplitude rises, with resolution limits
documented.

📂 Project Folder
`vlsi/vga-agc-mixed-signal/`

---

## [Cadence sky130 Tool Flow Labs](cadence-sky130-labs/)
**Virtuoso, Genus, Innovus**

Full-custom inverter and common-source amplifier schematic, layout, and
extracted-view simulation, plus a 16 x 16 multiplier taken from
SystemVerilog through Genus synthesis (513 standard cells) and Innovus
place and route.

📂 Project Folder
`vlsi/cadence-sky130-labs/`
