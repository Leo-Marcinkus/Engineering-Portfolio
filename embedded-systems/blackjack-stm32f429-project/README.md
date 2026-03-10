# STM32F429 Blackjack Touchscreen Game

**Project Type:** Embedded Systems Final Project  
**Platform:** STM32F429DISC-1  
**Language:** C  
**Environment:** STM32CubeIDE / HAL Drivers  
**Display:** ILI9341 LCD + STMPE811 Touch Controller  
**Date:** Fall 2025  

## Overview

This project is a touchscreen-based Blackjack game developed on the
STM32F429DISC-1 platform as a final project for embedded systems coursework.

The system uses the onboard LCD and touch interface to create a complete
interactive game experience, including graphical rendering, touch-based input,
game-state management, and persistent user interaction through a custom
embedded firmware architecture.

The project emphasizes real-time embedded programming, interrupt-driven input,
modular software design, and hardware/software integration on an ARM Cortex-M
microcontroller platform.

## Objectives

- Develop a fully functional interactive Blackjack game on embedded hardware
- Implement a responsive touchscreen user interface using the onboard LCD
- Structure firmware into modular, reusable software components
- Integrate game logic, graphics, and user input into a reliable real-time system
- Practice debugging and validation of a multi-module embedded application

## System Architecture

The application was built around the STM32F429DISC-1 development board and
organized into software modules responsible for display rendering, touch input,
game logic, and application control.

### Hardware Platform
- STM32F429ZI ARM Cortex-M4 microcontroller
- ILI9341 TFT LCD
- STMPE811 touchscreen controller
- Onboard timers, GPIO, and interrupts

### Software Structure
- **Display driver layer** for LCD drawing and screen updates
- **Touch input layer** for touchscreen event detection
- **Game logic layer** for Blackjack rules, scoring, and turn sequencing
- **Application control layer** for menu flow, user interaction, and state transitions

## Key Features

- Interactive touchscreen Blackjack gameplay
- Graphical card display and game-state visualization
- Embedded menu and user input handling
- Modular game logic implementation
- Real-time screen updates on STM32 hardware
- Interrupt- and event-driven interaction flow

## Technical Contributions

- Developed embedded application firmware in C using STM32CubeIDE
- Integrated LCD graphics and touchscreen input on the STM32F429DISC-1
- Implemented Blackjack rules, score handling, and state-based game progression
- Organized source code into modular components for maintainability and debugging
- Validated responsiveness and functional correctness across gameplay scenarios

## Firmware Organization

Typical application logic is organized across the following components:

- `Core/Src/` and `Core/Inc/` – main application logic and headers
- Display and touchscreen interface modules
- Blackjack/game-state implementation modules
- Driver and hardware abstraction files generated/configured through STM32CubeIDE

## Validation and Testing

Testing focused on confirming both functional gameplay behavior and reliable
hardware interaction.

Validation included:
- Touchscreen input verification
- LCD rendering and screen update behavior
- Game-state transition testing
- Score and rule correctness checks
- Multi-round interaction stability
- General firmware debugging and integration testing

## Results

- Successfully implemented a playable touchscreen Blackjack game
- Achieved stable touchscreen and LCD interaction on STM32 hardware
- Demonstrated modular embedded firmware architecture
- Validated reliable game-state handling and user interaction flow
- Strengthened experience in ARM-based embedded development and debugging

## Key Takeaways

- Interactive embedded applications require careful coordination between
  graphics, input handling, and application state
- Modular firmware design makes debugging and feature development much easier
- Hardware/software integration is just as important as application logic
- Event-driven embedded systems benefit from disciplined state management

## Files

- `firmware/blackjack-stm32f429` - STM32CubeIDE project source files

---

This project reflects hands-on experience in embedded firmware development,
real-time interaction design, and ARM-based system integration on a
resource-constrained hardware platform.