#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/delay.h>

int main(void) {
    
    DDRB    = 0b00100000; //DDRB |= (1<<DDRB5);
    DDRD    = 0b1111;
    while(1){
        /*
        Lectura en PB7
         * 1= cuando no esta presionado el SW
         * 0= cuando está presionado es SW 
        */
        
        //if((PINB & (1<<PINB7) == 0){ 
        if((PINB & 0b10000000) == 0){ //pull up
            PORTB |= (1<<PORTB5);
        }
        else
        {
            PORTB &= ~(1<<PORTB5);
        }
    }
    
     return 0;
}

