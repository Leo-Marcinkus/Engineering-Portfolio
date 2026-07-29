# 1T-1C DRAM Cell with Cross-Coupled CMOS Sense Amplifier

**Course:** ECEN 4012 - Design of VLSI Circuits  
**Date:** Spring 2026  

## Overview

This project is a two-cell 1T-1C DRAM array with a cross-coupled CMOS sense
amplifier, designed, simulated, and laid out in Siemens Tanner using the
Generic 250 nm process at a 2.5 V supply. The final circuit contains
thirteen transistors.

The design demonstrates the complete DRAM read sequence: precharge to
VDD/2, charge sharing from a storage node onto the bitline, sense amplifier
activation and latching, and partial refresh of the storage node through
the access transistor.

The project involved schematic entry in S-Edit, transient simulation and
timing analysis in T-Spice, and physical layout in L-Edit, covering the
full custom IC design flow from specification through layout.

## Technical Objectives

- Implement two 1T-1C DRAM cells sharing a common bitline pair
- Design a cross-coupled CMOS sense amplifier with PMOS and NMOS latches
- Add a sense amplifier enable circuit to isolate the latch during
  precharge
- Precharge both bitlines to VDD/2 so either stored state produces a
  detectable differential
- Achieve a pre-latch sense margin above 50 mV
- Verify destructive read and refresh behavior for both logic states
- Produce a complete physical layout with correct sizing and net labeling

## Circuit Architecture

- Cell 0: Mn4 access transistor, Mn5 gate-oxide storage device, logic 1  
- Cell 1: Mn6 access transistor, Mn7 gate-oxide storage device, logic 0  
- Precharge Block: Mp1 and Mp2 pull BL and BLB to VDD/2, Mn1 equalizes  
- Sense Amplifier: Mp3 and Mp4 PMOS latch, Mn2 and Mn3 NMOS latch  
- Enable Circuit: Mp5 gates the PMOS latch to VDD, Mn8 gates the NMOS
  latch to GND  
- Supplies: 2.5 V main rail and a dedicated 1.25 V precharge rail  

Both cells connect to the same BL and BLB lines through separate wordlines
and are initialized to opposite values, so a single transient simulation
exercises both a logic 1 and a logic 0 read.

## Design and Implementation

### Schematic Design
The schematic was entered in Siemens Tanner S-Edit with the two DRAM cells
at the lower left, the cross-coupled sense amplifier at the center, the
enable transistors gating the latch to the supply rails, and the precharge
block at the top. Supply voltage was set to 2.5 V to match the rated
operating voltage of the NMOS25 and PMOS25 devices in the Generic 250 nm
process.

### Transistor Sizing
All devices use a 250 nm channel length. Access transistors are kept at
minimum width to limit charge injection onto the storage node, while the
storage devices are maximized at 10 um to increase gate-source capacitance
and therefore sense margin. Latch devices are matched in pairs for
symmetric differential response. The enable transistors are deliberately
oversized, Mn8 at 5 um to hold the virtual ground close to true GND and
Mp5 at 8 um so the PMOS latch devices do not starve during the sense event.

### Precharge and Control
The precharge control was split into two separate signals. PRE drives only
the equalizer, while PREB drives the precharge PMOS devices. A dedicated
1.25 V source drives the precharge PMOS sources rather than relying on
natural equalization through charge sharing, which guarantees a precise
midpoint regardless of bitline parasitic mismatch.

### Physical Layout
The layout was completed in L-Edit using PDK-provided parameterized nmos25
and pmos25 cells with widths and lengths matching the schematic. The
floorplan follows a top-to-bottom organization: VDD rail, precharge block,
PMOS latch and enable, NMOS latch and enable, GND rail, and the two DRAM
cells at the bottom. Metal1 routing connects the major blocks with net
labels annotating all connections.

## Simulation Setup and Timing

- T-Spice 2023.2 using the Generic 250 nm TT_AMS process corner
- 100 ns transient analysis with method=BDF for latch convergence
- Initial conditions set with SPICE .ic statements, storage0 at 2.5 V and
  storage1 at 0 V
- 40 ns read cycle with an 8 ns precharge window
- WL0 asserts at 10 ns and WL1 at 30 ns, confirmed non-overlapping
- SAE fires at 12.1 ns for the logic 1 cell and 30.3 ns for the logic 0
  cell, driven by VPWL sources because two enable windows per period cannot
  be expressed as a single VPULSE

## Validation and Testing

Verification was performed through transient simulation with waveform
measurement at each stage of the read cycle.

Testing included:
- Wordline and precharge control timing verification across the full 100 ns
  simulation
- Bitline behavior through precharge, charge sharing, and latch resolution
- Zoomed sense margin measurement at the moment of sense amplifier
  activation
- Storage node tracking through destructive read and refresh for both cells
- Layout inspection for correct sizing, floorplan, and net labeling

## Results

- Supply voltage: 2.5 V, matching the NMOS25 and PMOS25 device rating
- Precharge level: approximately 1.3 V against a 1.25 V target
- Sense margin: 57.2 mV at sense amplifier activation, against a 50 mV
  project target
- Post-latch bitlines: approximately 1.75 V and 0 V, a resolved
  differential of roughly 1.5 V amplified from the 57 mV input
- Cell 0 read: BL high and BLB low, correct for logic 1
- Cell 1 read: BL low and BLB high, correct for logic 0
- Storage refresh: storage0 partially restored to approximately 1.7 V,
  storage1 discharged to approximately 0.25 V
- Physical layout: all thirteen transistors placed and routed in L-Edit

An earlier single-cell version measured 169 mV of sense margin, but that
circuit tied the latch sources directly to the rails with no enable
transistors. Adding the enable devices puts real impedance in the current
path, so the virtual ground node rises slightly during the sense event and
source degeneration reduces the pre-latch differential. The 57 mV figure
comes from the more complete and more realistic circuit model and still
clears the target.

## Known Limitations

- The storage node restores to approximately 1.7 V rather than the full
  2.5 V rail. The sense amplifier drives through the access transistor and
  the 7 ns overlap window is not long enough for full restoration.
  Production DRAM uses a dedicated write-back driver.
- Initial data was established with SPICE initial conditions rather than a
  physical write cycle. The 1T-1C topology supports writes through the same
  access transistor, but implementing and verifying a write was out of
  scope.
- DRC and LVS were not run because of a Calibre license server
  configuration issue. The layout has correct sizing, floorplan, and net
  labeling but is not sign-off verified.

## Lessons Learned

- Precharge must be to VDD/2 rather than the full rail. With a full-rail
  precharge, a stored logic 1 produces no differential because the storage
  node and bitline sit at the same voltage.
- Sense amplifier enable timing determines whether the read works at all.
  Firing too early means the differential has not developed, firing too
  late means it has already started recovering toward the midpoint. The
  logic 1 cell needed a 2 ns delay after wordline assertion while the logic
  0 cell needed only 0.3 ns.
- Separating PRE from PREB allows independent control of the equalizer and
  the precharge devices and prevents them from fighting during transitions.
- Adding realistic circuit elements can appear to degrade a metric while
  actually improving the quality of the measurement, as with the sense
  margin change after the enable transistors were added.

## Files

- `FinalReport_LeoMarcinkus.pdf` - Full technical report and measurements  
- `DRAM_Presentation_LeoMarcinkus.pdf` - Project presentation   

PDK files from the Generic 250 nm process library are not included in this
repository.

---

For related work, see the VLSI coursework and mixed-signal simulation
projects in this repository.
