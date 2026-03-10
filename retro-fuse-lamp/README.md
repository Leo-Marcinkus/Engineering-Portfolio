# ESP-NOW Wireless Lamp – Battery-Powered ESP32 Lighting System

**Project Type:** Personal Project - Hardware Design  
**Date:** March 2026  

## Overview

This floating frame LED lamp is a battery-powered LED lighting system
controlled wirelessly using ESP-NOW communication between two ESP32
microcontrollers. One ESP32 acts as a transmitter that sends commands,
while the receiver ESP32 controls the LED output through a MOSFET driver.

I used glass fuse casings with LED Edison bulbs soldered inside for a warm 
retro-like glow.

The system integrates Li-ion battery charging, power regulation, wireless
communication, and LED switching into a compact embedded hardware prototype.
The goal of the project was to design a fully self-contained lighting system
that could be remotely controlled while operating entirely from a rechargeable
battery.

The project involved power electronics design, embedded firmware
development, wireless communication debugging, and hardware prototyping while 
emphasizing power efficiency, safe battery management, and compact embedded integration.

### System Demonstration

![Retro Fuse Lamp Demo](retro-fuse-lamp-demo.gif)

### Hardware Overview

![Lamp Angle 1](lamp-angle1.jpg)
![Lamp Angle 2](lamp-angle2.jpg)
![Lamp Angle 3](lamp-angle3.jpg)

## Technical Objectives

- Implement wireless lamp control using ESP-NOW communication
- Design a battery-powered embedded lighting system
- Integrate Li-ion charging and battery protection circuitry
- Control LED power using a MOSFET switching stage
- Ensure stable operation under varying battery voltage
- Implement persistent lamp state storage across reboots
- Prototype a compact hardware architecture suitable for portable systems

## Hardware Architecture

- Receiver Microcontroller: ESP32-C3 SuperMini  
- Transmitter Microcontroller: ESP32 DevKit V1  
- Communication Protocol: ESP-NOW peer-to-peer wireless  
- Power Source: Single-cell Li-ion battery (18650 / 10440 compatible)  
- Charging Module: USB-C Li-ion charging board  
- Voltage Regulation: 3.3V regulation (prototype LDO, future buck-boost supply)  
- LED Driver: Logic-level N-channel MOSFET switching stage  
- LED Load: High-efficiency LED with series current-limiting resistor  
- Mechanical Frame: Copper/brass structural wiring prototype  

## Design and Implementation

### Power System Design
The lamp is powered from a single Li-ion battery cell. The battery connects
to a charging module that allows the device to be recharged through a USB-C
connector. The charging circuit manages battery charging using the standard
constant-current / constant-voltage Li-ion charging profile.

The system power architecture follows:

Battery → Charging Module → Voltage Regulation → ESP32 + LED Driver

Initial prototypes used a linear regulator to generate a 3.3V rail for the
ESP32. Testing revealed that regulator dropout occurred as battery voltage
decreased during discharge. Future revisions will implement a buck-boost
regulator to maintain a stable 3.3V supply across the entire battery voltage
range.

### LED Driver Stage
The LED is controlled using a logic-level N-channel MOSFET configured as a
low-side switch. The ESP32 controls the MOSFET gate through a GPIO pin,
allowing the microcontroller to enable or disable current flow through
the LED load.

The switching configuration is:

3.3V → LED Resistor → LED → MOSFET → Ground

A gate resistor and pulldown resistor are used to ensure stable switching
behavior and prevent unintended LED activation during microcontroller boot.

### Wireless Communication
Communication between the transmitter and receiver is implemented using
ESP-NOW. This protocol enables low-latency device-to-device communication
without requiring a Wi-Fi network or router.

The transmitter sends simple command packets that instruct the receiver
to toggle the lamp state. The receiver continuously listens for incoming
ESP-NOW packets and updates the LED driver accordingly.

### Persistent Lamp State
To ensure consistent behavior after power loss or reboot, the receiver
stores the lamp state in non-volatile flash memory using the ESP32
Preferences (NVS) storage system.

During startup the firmware retrieves the previously stored lamp state
and restores the LED driver to the correct condition.

This allows the lamp to remember whether it was on or off before power
was interrupted.

## Firmware and Configuration

- Firmware developed using the Arduino IDE and ESP32 toolchain  
- ESP-NOW configured for direct peer-to-peer communication  
- Receiver firmware handles command parsing and LED control  
- Preferences (NVS) used for persistent lamp state storage  
- GPIO-driven MOSFET switching controls LED output  

## Validation and Testing

Electrical and functional validation were performed throughout development.

Testing included:

- Battery voltage measurements during operation
- Regulator behavior under varying load conditions
- MOSFET switching verification
- LED current and brightness testing
- ESP-NOW communication reliability testing
- Persistent memory validation across power cycles

The system was tested under both USB power and battery-powered operation
to ensure stable performance under realistic conditions.

## Results

- Successful wireless control of the lamp using ESP-NOW
- Reliable MOSFET switching of LED load
- Stable firmware operation with persistent state memory
- Functional battery charging via USB-C charging module
- Portable battery-powered operation demonstrated

The prototype successfully demonstrates a compact embedded wireless
lighting system controlled by ESP32 microcontrollers.

## Lessons Learned

- Linear regulators are poorly suited for Li-ion powered ESP32 systems
  due to dropout limitations
- Buck-boost regulators are preferable for single-cell battery designs
- MOSFET leakage currents can produce visible LED glow at microamp levels
- ESP-NOW requires careful configuration of MAC addresses and channels
- Power system design is critical in battery-powered embedded devices

## Files

- `receiver.ino` - ESP32-C3 receiver firmware  
- `transmitter.ino` - ESP32 transmitter firmware   

---