#include <avr/io.h>
#include <stdbool.h>
#include "GPIO.h"

void pinMode(volatile unsigned char *register_port, unsigned char pin, PIN_MODE state)
{
    if(state == INPUT)
    {
        *register_port &= ~(1<<pin); //el pin de register port como entrada
    }
    else if(state == OUTPUT)
    {
        *register_port |= (1<<pin);
    }
}

void digitalWrite(volatile unsigned char *register_port, unsigned char pin, PIN_STATE state)
{
    if(state == LOW)
    {
        *register_port &= ~(1<<pin);
    }
    else if(state == HIGH)
    {
        *register_port |= (1<<pin);
    }
}

PIN_STATE digitalRead(volatile unsigned char *register_port, unsigned char pin)
{
    bool pinState;
    pinState = (*register_port & (1<<pin));
    if(pinState == true)
        return HIGH;
    else
        return LOW;
    
    //return((*register_port & (1<<pin)) ? HIGH : LOW)
}