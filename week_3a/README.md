# Week 3A, Investigate project board: B-L475E-IOT01A

Description: *STM32L4 Discovery kit IoT node, low-power wireless, BLE, NFC, SubGHz, Wi-Fi*

## Hardware Block Diagram

TODO

## Questions

- What kind of processor is it?
  - Arm Cortex-M4 with FPU
- How much Flash and RAM does it have? Any other memory types?
  - 1 MB flash
  - 128 KB SRAM
  - 64 Mbit QSPI flash (on board)
- Does it have any special peripherals? (List 3-5 that you noted as being interesting.)
  - 3D accelerometer and gyroscope
  - WiFi
  - 12-bit DAC
  - omnidirectional microphone
- Does it have a floating point unit?
  - Yes.
- If it has an ADC, what are the features?
  - High-speed: 5 Msps
  - Low-power: 200 μA/Msps

## Application Note

I looked at the note *Using the DAC to generate a sine waveform*.
This is something that I've worked on as hobby project.
In the other project I was using a low-pass filtered PWM signal because that MCU (Cortex-M0+) doesn't have a DAC.
