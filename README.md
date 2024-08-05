# Multiplexing 7-Segment 0 to 20 Counter

This project demonstrates a multiplexing technique using a 7-segment display to count from 0 to 20. The project utilizes a microcontroller to control two 7-segment displays, efficiently switching between them at a frequency unnoticeable to the human eye.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Hardware](#hardware)
- [Software](#software)
- [Setup](#setup)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Overview

Multiplexing allows the control of multiple 7-segment displays using the same microcontroller pins, significantly reducing the number of required I/O pins. In this project, two displays are used to count from 0 to 20, cycling back to 0. The project demonstrates the practical application of multiplexing in embedded systems.

## Features
- **Efficient Multiplexing**: Controls two 7-segment displays using shared microcontroller pins.
- **Scalable**: The design can be extended to control more displays.
- **Real-Time Counting**: Displays count from 0 to 20 continuously.

## Hardware

The hardware components used in this project include:
- **Microcontroller**: Pic18f4620
- **7-Segment Displays**: Common Anode type
- **Resistors**: For current limiting

### Schematic

A detailed schematic diagram can be found in the `Design/Design.pdsprj` file in the repository.

## Software

The software is written in C and compiled using Atmel Studio 6.0. The main functionalities include:
- **Initialization**: Setting up the microcontroller and display.
- **Display Control**: Multiplexing logic to control the 7-segment displays.
- **Counting Logic**: Incrementing the displayed number from 0 to 20.

## Setup

1. Clone the repository:
   ```bash
   git clone https://github.com/Abdrlrahman-Mansour/Multiplexing_7seg_0_to_20_counter.git
