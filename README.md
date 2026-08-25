# Servo controller for PIC18F4520

The code uses software generated PWM instead of using hardware PWM,
The PWM is interrupt driven.
## Features
* **Multiple Servo motor Control:** Control multiple servos simultaneously using a single hardware timer.
* **Easy allocating pins:** Use servo motors with any standard output pin.
* **Non-blocking:** Runs completely in the background via interrupts so leaving space for more components in the while loop.

## Hardware Requirements
* **Microcontroller:** PIC MCU (Code is styled for PIC18 using XC8 compiler, but easily adaptable).
* **Clock Speed:** The timer math in this driver assumes an instruction clock generated from an **8 MHz** oscillator.
* **Timer:** Timer1 (16-bit).

---

## How to use the code in Your Project

1. Copy `servo.h` and `servo.c` into your project folder.
2. Add both the files to your MPLAB X / XC8 project folder.
3. make sure that your `config.h` or main file defines the system clock: `#define _XTAL_FREQ 8000000`

---

## Configuration - servo.h

Before compiling the code you wrote, configure which pins you want to connect your servos using the below procedure.

**1. Define your pins in the enumerator:**
This is for controlling the servos individually

typedef enum {
    RB0_pin = 0,RB1_pin = 1,num_servos
} servo_pin_t;

**2. 2. Define the hardware control registers::**
#define IO_RB0 TRISBbits.RB0
#define RB0_value LATBbits.LATB0

#define IO_RB1 TRISBbits.RB1
#define RB1_value LATBbits.LATB1

See the main.c code for more reference
