# Lychee

Lychee is a HAB (high-altitude balloon) which serves two main purposes:
- An induction project for new members looking to get hands-on building and launching a HAB.
- A test bed for prototype Martlet IV electronics.

## Motivation
After many years stuck in development hell, Project Strix (Martlet IV's avionics system) was ready for
hardware prototyping and flight testing. But flight testing avionics is difficult, especially on a budget;
so we decided to return to the society's roots and bring back our dormant HAB program.

With rough designs already complete for Martlet IV's eventual launch, we decided to port the flight
computer into a less modular form factor and consolidate modules, to create an extensible dual-board
architecture that allows us to test both fundamental system hardware and prototype future modules through
an expansion slot.

## Aims
The launch aims to test several key features and subsystems of the design ahead of construction of
final Project Strix flight hardware. In summary, these are:
- understand the embedded systems prototyping and development process for the STM32 + ChibiOS/RT stack
- perform real-time altimetry through a combination of
  - 2x redudant barometers
  - 1x 6-DoF IMU
  - 1x GPS
- relay telemetry through our custom ISM-band radio system
- verify the electrical performance of our 'blackbox' flight data recorder

## Using This Repository
This repository contains the electrical and software design files for the project. PCB designs were created
in KiCad 6, and the software was written for ChibiOS/RT. To install the dependency submodules, run
`git submodule update --init` from the root directory.
