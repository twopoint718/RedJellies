# Week 5, Final Project Planning

> Start putting together a plan for your final project. Given the
> chapter, the main goal is to put together state machine
> documentation. This can be a flowchart or (preferably) a state
> table. You may also need to create the diagrams from Lesson 2 to
> flesh out the design. Note: this design planning, thinking through
> the system, what you have and what you need. Keep in mind that these
> will not be the final version!

## High-level Description

This final project is a [Pomodoro timer](https://francescocirillo.com/pages/pomodoro-technique).
It consists of a triangular-shaped digital desktop timer that has some allowances for using the pomodoro technique.
The timer is orientation sensitive, allowing you to select a duration.
Using the accelerometer, the timer knows if you've selected a _Pomodoro (25 minutes)_, a _short break_ (5 minutes), or a _long break (15 minutes)_.
These correspond to the chunks of time used by the technique.

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

## Technical Details

Features/techniques used:

- E-ink display
- Custom graphics
- PWM buzzer
- Accelerometer
- System timers

## Architecture Diagrams

TODO

## State Diagram

![](img/state_diagram.png)

## State Table

| State                | Event                    | Next                 | state State var: pomodoros |
|----------------------|--------------------------|----------------------|----------------------------|
| START                | [NONE]                   | SHOW_STATS           | pomodoros = 0              |
| SHOW\_STATS          | orientation: pomodoro    | TIMING\_POMODORO     |                            |
| SHOW\_STATS          | orientation: short break | TIMING\_SHORT\_BREAK |                            |
| SHOW\_STATS          | orientation: long break  | TIMING\_LONG\_BREAK  |                            |
| TIMING\_POMODORO     | timeout (25 min)         | SHOW\_STATS          | pomodoros++                |
| TIMING\_SHORT\_BREAK | timeout (5 min)          | SHOW\_STATS          |                            |
| TIMING\_LONG\_BREAK  | timeout (15 min)         | SHOW\_STATS          |                            |
| TIMING\_LONG\_BREAK  | timeout (15 min)         | SHOW\_STATS          |                            |
| [ANY]                | reset button             | SHOW\_STATS          | pomodoros = 0              |
