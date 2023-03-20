#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void contador1(void);
void contador2(void);
void contador3(void);
int main(void) {
    
    DDRB    = 0b00100000; //DDRB |= (1<<DDRB5);
    DDRD    = 0b1111;
    while(1)
    {
//        contador1();
//        contador2();
        contador3();
    }
    
     return 0;
}


void contador1(void){
    unsigned char contador; 
    while(1){
        for(contador=0;contador<=15;contador++)
        {
            PORTD = contador;
            _delay_ms(500);
        }
    }
    contador = 0;
}

void contador2(void){
    unsigned char contador;
    while(contador<16)
    {
        PORTD = contador;
        contador++;
        _delay_ms(500);
    }
}

void contador3(void)
{
    unsigned char contador; 
    while(1){
        for(contador=0;contador<=15;contador++)
        {
            PORTD = contador;
            while((PINB & (1<<PINB7)) != 0); //esperamos a que se presione el boton RB7
            _delay_ms(150); //delay anti-rebote
            
            while((PINB & (1<<PINB7)) == 0); //esperar a que se feje de presionar el botosn
            _delay_ms(150); //delay anti-rebote
        }
    }
    contador = 0;
}
