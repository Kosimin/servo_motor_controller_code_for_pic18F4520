/*
 * File:   main.c
 * Author: Kosimin
 *
 * Created on 15 August, 2026, 10:45 AM
 */


#include "config.h"
#include "servo.h"

void __interrupt() ISR(void)
{
    servo_interrupt();
}

void main(void) 
{
    OSCCONbits.IRCF = 0b111;
    
    servo_init();
    
    while(1)
    {
        // Using your preferred syntax:
        servo_set_angle(RB0_pin, -90);
        servo_set_angle(RB1_pin, 90);
        __delay_ms(1000);
        
        servo_set_angle(RB0_pin, 0);
        servo_set_angle(RB1_pin, 0);
        __delay_ms(1000);
    }
}
