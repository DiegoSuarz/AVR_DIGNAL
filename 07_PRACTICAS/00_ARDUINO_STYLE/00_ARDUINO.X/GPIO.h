
#ifndef GPIO_H
#define	GPIO_H


typedef enum
{
    INPUT,
    OUTPUT
}PIN_MODE;

typedef enum
{
    LOW,
    HIGH
}PIN_STATE;

void pinMode(volatile unsigned char *register_port, unsigned char pin, PIN_MODE state);
void digitalWrite(volatile unsigned char *register_port, unsigned char pin, PIN_STATE state);
#endif	/* GPIO_H */

