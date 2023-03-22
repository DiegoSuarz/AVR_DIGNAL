#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd_lib.h"

/*
 RS  -> 
 */
int main(void) {
    
    LCDinit();
    LCDGotoXY(0,0);
    LCDstring("Hola Mundo",10); //10 numero de bytes del mensaje
    
    LCDGotoXY(0,1);
    LCDstring("Microchip",9);
    
    
      
    while(1){
        for(uint8_t i=0;i<15;i++)
        {
            LCDshiftRight(1);
            _delay_ms(1000);
        }
        
           for(uint8_t i=0;i<15;i++)
        {
            LCDshiftLeft(1);
            _delay_ms(1000);
        }
    }
    return 0;
}

