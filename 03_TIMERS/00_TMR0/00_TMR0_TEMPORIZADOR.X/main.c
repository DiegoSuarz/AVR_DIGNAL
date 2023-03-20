
#include <avr/io.h>

/*
 TCNT0 = 256 - ((tiempo x FCLK)/pree)
 */
int main(void) {
    
    DDRB |= (1<<DDRB5);
    TCCR0B |= (1<<CS00)|(1<<CS02);
    TCNT0 = 99;
    
    unsigned char contador;
    while(1)
    {
        if(TCNT0 == 250)
        {
            contador++;
            if(contador == 100)
            {
                PORTB ^= (1<<PORTB5);
                contador = 0;
            }
            TCNT0 = 99;
        }
    }
    return 0;
}


