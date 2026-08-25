/* 
 * File:   servo.h
 * Author: Kosimin
 *
 * Created on 25 August, 2026, 11:13 PM
 */

#ifndef SERVO_H
#define	SERVO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <stdint.h>

typedef enum {
    RB0_pin = 0,RB1_pin = 1,num_servos
} servo_pin_t;
    
#define IO_RB0 TRISBbits.RB0
#define RB0_value LATBbits.LATB0

#define IO_RB1 TRISBbits.RB1
#define RB1_value LATBbits.LATB1

void servo_init(void);
void servo_set_angle(servo_pin_t pin,int16_t angle);
void servo_interrupt(void);
#ifdef	__cplusplus
}
#endif

#endif	/* SERVO_H */

