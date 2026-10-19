# High-Speed Digital Measurement Labs

**Course:** ECEN 5534 - HSDE Measurement, Simulation, Analysis, and Presentation Skills  
**Instructors:** Prof. Eric Bogatin and Prof. Tim Swettlen  
**Date:** Fall 2026 (in progress)  

This directory contains the lab presentations from a graduate signal
integrity measurement course at CU Boulder. Each lab is built around a
real measurement on real hardware, a model or simulation of the same
structure, and a direct comparison between the two with the uncertainty
stated.

## Overview

Every lab follows the same workflow:

- Measure the structure with an oscilloscope, TDR, or VNA
- Build an equivalent circuit or field-solver model of it
- Correlate measurement to simulation and quantify the agreement
- Report the uncertainty in every number, not just the value
- Close with the "so what": what the result means for a real design

The work is presented as a short technical talk to the class, so each
folder contains the slide deck as a PDF along with key figures.

## Areas of Study

### Time-Domain Measurement
- Source impedance extraction from loaded and unloaded measurements
- Reflections, ringing, and termination effects on coax interconnects
- Propagation delay and time of flight
- Scope bandwidth and rise time limits

### TDR and Impedance
- Virtual TDR built in Keysight ADS from measured VNA S-parameters
- Calibration reference planes and SOLT calibration
- Usable impedance range of a 1-port reflection measurement
- Characteristic impedance of PCB microstrip traces
- Parasitic inductance of resistive terminations

### Modeling and Correlation
- Importing scope waveforms into ADS as dataset sources
- Fitting transmission-line models to measured ringing
- Online calculators vs 2D field solvers (HyperLynx, Ansys Q2D)
- Sensitivity analysis of Z0 to geometry and Dk tolerances
- Fitting R, L, C models of terminations to measured S11

## Labs

| Lab | Topic | Key Result |
|---|---|---|
| [1.1](lab-1.1-cable-ringing-scope-terminations/) | Ringing in cables and scope terminations | Thevenin source model extracted for three source settings; first ringing peaks predicted within 0.2 V |
| [1.2](lab-1.2-coax-time-of-flight/) | Time of flight in coax cables | 1.58 ns/ft measured on RG58, Dk extracted as 2.42 |
| [1.3](lab-1.3-ringing-model-fitting/) | Hacking ringing reflections | Fitted line model cut RMS error from 1.13 V to 0.21 V |
| [2.1](lab-2.1-vna-tdr-impedance-range/) | TDR from VNA measurements | 1-port VNA TDR within 5% from 10 Ω to 1 kΩ; limit traced to ρ resolution |
| [2.2](lab-2.2-pcb-trace-z0-ptfe/) | Z0 of PCB traces on PTFE | Measured 25.9, 50.1, and 74.9 Ω (±0.4 Ω or better) and compared against six tools |
| [2.3](lab-2.3-resistive-termination-modeling/) | TDR hacking resistive terminations | Fitted loop inductance from 2.59 to 8.98 nH; model valid to 1.8 to 2.5 GHz |

## Tools and Instrumentation

- Keysight DSOX4024A oscilloscope (200 MHz, 5 GSa/s)
- NanoVNA-F V3 (1-port, up to 6 GHz)
- Keysight ADS (transient, virtual TDR, dataset sources)
- Siemens HyperLynx and Ansys Q2D 2D field solvers
- Excel for data reduction and curve fitting
- RG58 coax, SMA and BNC fixtures, CU HSDE test boards

## Documentation Standards

Every presentation includes:

- The question the lab answers
- Setup and equivalent circuit used to interpret the data
- Measurement uncertainty and its sources
- Measurement-to-simulation comparison
- A "so what" conclusion tied to practical design

---

For earlier ADS-based simulation studies, see the
[High-Speed Digital labs](../labs/) in this repository.
