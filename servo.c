/*
 * File:   servo.c
 * Author: Kosimin
 *
 * Created on 25 August, 2026, 11:28 PM
 */


#include "servo.h"

volatile uint16_t count = 0; // for 1.5 ms 3 counts and for 18.5 ms 37 counts
static volatile uint16_t pulse_width[num_servos];

void servo_init(void)
{
    // Setting all default pulse widths to 0 degrees
    for(uint8_t i = 0; i < num_servos; i++) {
        pulse_width[i] = 30;
    }

    IO_RB0 = 0;
    RB0_value = 1;
    IO_RB1 = 0;
    RB1_value = 1;

    T1CONbits.TMR1ON = 0;
    T1CONbits.RD16 = 1;
    T1CONbits.TMR1CS = 0;
    T1CONbits.T1CKPS = 0b00;
    TMR1H = 0xFF;
    TMR1L = 0xAD;

    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.TMR1IE = 1;
    PIR1bits.TMR1IF = 0;

    T1CONbits.TMR1ON = 1;
}

void servo_set_angle(servo_pin_t pin, int16_t angle)
{
    if (angle>90)
    {
        angle = 90;
    }
    if (angle<-90)
    {
        angle = -90;
    }
    if (pin >= num_servos)
    {
        return;
    }
    pulse_width[pin] = 30 + (angle / 9);
}

void servo_interrupt()
{
    if (PIR1bits.TMR1IF)
    {
        PIR1bits.TMR1IF = 0;
        TMR1H = 0xFF;
        TMR1L = 0xAD;
        count++;
        if (count>=400)
        {
            RB0_value = 1;
            RB1_value = 1;
            count = 0;
        }
        else
        {
            if (count >= pulse_width[RB0])
            {RB0_value = 0;
            }
            if (count >= pulse_width[RB1]) 
            {RB1_value = 0;
            }
        }
    }
}

