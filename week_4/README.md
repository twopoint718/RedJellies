# Week 4, Make Blinky

> On your final project board, make blinky for yourself. Then add a button to turn the LED on and off. Bonus points for making the button cause an interrupt. Triple bonus points for debouncing the button signal.

## Questions

> What are the hardware registers that cause the LED to turn on and off? (From the processor manual, don’t worry about initialization.)

LED1 is mapped to PA_5.
And that's in GPIO Port A.
According to the manual, each GPIO port has an associated GPIO port _output data register_ (`GPIOx_ODR`).

> What are the button registers that you read?

The board has a built-in `USER` button that I'm reading.
That is GPIO `PC_13`.

> Can you read that memory directly and see the button change in a debugger or by printing out the associated memory?

Yes, I did some `printf` debugging here.
