# Week 10, Power Use Worksheet

> The worksheet describing Wordy’s power use is demonstrated in the
> lecture. Make one for your system (either design or engineering
> version).
>
> Estimates are ok in place of real numbers. If you have
> many components, limit it to the top 5-8 most likely to consume
> power. Even if you have a USB or wall powered system, identify the
> largest consumers of power and how you might reduce power
> consumption.

| 1. What are the different states the device can be in?  |
|---------------------------------------------------------|
| The timer can be off, it can actively timing, or it can |
| be idle (on but not timing).                            |

| 2. How much will your device be in each state?                              |
|-----------------------------------------------------------------------------|
| It doesn't really seem avoidable to be anything other than "always on" when |
| actively timing. The LCD is going to be showing the current time remaning   |
| and this will have to updated frequently. Otherwise, it will idle or off.   |
| It can remain in these states for potentially long periods of time. The     |
| Timing states are 5, 15, and 25 minutes long.                               |

| 3. How much current is used in each state? | mA   |
|--------------------------------------------|------|
| Active state:                              | -    |
| CPU (100 uA/MHz @ 80 MHz)                  | 8    |
| Accelerometer                              | 0.65 |
| LCD  (with backlight)                      | 87   |
| LCD (w/o backlight)                        | 7    |

| 4. How long will the device last given a 40mAh battery? | Minutes |
|---------------------------------------------------------|---------|
| Backlight on                                            | 25      |
| Backlight off                                           | 150     |
