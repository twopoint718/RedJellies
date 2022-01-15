# Application Description

This final project is a [Pomodoro timer](https://francescocirillo.com/pages/pomodoro-technique).
It consists of a triangular-shaped digital desktop timer that has some allowances for using the pomodoro technique.
The timer is orientation sensitive, allowing you to select a duration by how you place it down on the desk.
Using the accelerometer, the timer determines if you've selected a _Pomodoro_ (25 minutes), a _short break_ (5 minutes), or a _long break_ (15 minutes).
These correspond to the typical durations used the Pomodoro Technique.

The technique, briefly:

1. Start a 25 minute timer.
   During this time focus entirely on the task at hand.
   Postpone any interruptions until the timer has expired.
2. Take a short, 5 minute break.
3. Repeat 1 & 2 three more times.
4. After the fourth pomodoro, take a longer break (15 minutes).
5. Repeat 1 through 4 as needed to accomplish your tasks.

The timer will keep track of the total number of pomodoros that you've accomplished.
There is a reset button to clear the accumulated count of pomodoros.
Good work today!

# Hardware description

The main component parts are listed here and then discussed breifly below:

- STM32L4 Discovery kit (B-L475E-IOT01A)
- Philips PCD8544 48 × 84 pixels matrix LCD
- ST LSM6DSL, 3D accelerometer and 3D gyroscope (on-board)
- Buzzer

The main piece of hardware is an STM32L4 Discovery kit (B-L475E-IOT01A).

There is an external LCD screen, a Philips PCD8544 (aka the old Nokia )
- SPI

The 3D accelerometer
- I2C

# Software description
- Describe the code in general
- Describe the parts you wrote in some detail (maybe 3-5 sentences per module)
- Describe code you re-used from other sources, including the licenses for those

# Diagram(s) of the architecture

# Build instructions
- How to build the system (including the toolchain(s))
  - Hardware
  - Software
- How you debugged and tested the system

# Future
To make this prototype more usable as a production device, I'd first look at its power requirements.
I'd expect something like this to have a pretty extensive battery life.
I would have investigate

- How would you extend this project to do something more? Are there other
features you’d like? How would you go about adding them?

The main missing feature is to _IoT-it-up!_
This timer is just _asking_ for a phone app to automatically accumulate and categorize pomodoros.
The board has both Wi-Fi as well as Bluetooth so I'd have my choice of connectivity.
I have done lots of web application development but very little native app development.
Initially then, I'd lead toward using web technologies.
The timer could automatically upload to a website for tracking time.
It could also be possible to control the timer by sending GET and POST HTTP requests in order to configure the timer.

# Grading
- Self assessment of the project: for each criteria, choose a score (1, 2, 3) and explain your reason for the score in 1-2 sentences.
- Have you gone beyond the base requirements? How so?
