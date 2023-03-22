/* 
 * File:   GPIO.h
 * Author: dg_su
 *
 * Created on 22 de marzo de 2023, 04:13 PM
 */

#ifndef GPIO_H
#define	GPIO_H

#include <avr/io.h>

typedef struct DDBbits_t
{
    unsigned  pinb0 : 1;
    unsigned  pinb1 : 1;
    unsigned  pinb2 : 1;
    unsigned  pinb3 : 1;
    unsigned  pinb4 : 1;
    unsigned  pinb5 : 1;
    unsigned  pinb6 : 1;
    unsigned  pinb7 : 1;
}volatile *DDBbits;

typedef struct PORTBBbits_t
{
    unsigned  portb0 : 1;
    unsigned  portb1 : 1;
    unsigned  portb2 : 1;
    unsigned  portb3 : 1;
    unsigned  portb4 : 1;
    unsigned  portb5 : 1;
    unsigned  portb6 : 1;
    unsigned  portb7 : 1;
}volatile *PORTBBbits;

#define DDRBbits  (*(DDBbits)_SFR_MEM_ADDR(DDRB))
#define PORTBbits (*(PORTBBbits)_SFR_MEM_ADDR(PORTB))

#endif	/* GPIO_H */

