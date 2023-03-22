
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "usart.h"
#include <stdio.h>

#define RANURAS 15

uint16_t pulsos; //variable para llevar el conteo de pulsos del encoder
uint16_t rps; //revoluciones por segundo
uint16_t rpm; //revoluciones por segundo



void INT1_init()
{
    EICRA |= (1<<ISC10) | (1<<ISC11); //INT1 rising edge
    EIMSK |= (1<<INT1); //habilitar INT1
}

void TMR1_init()
{
    //valor de carga para 1s
    TCCR1B |= (1<<CS12); //Timer clk interno, prescaler 256
    TIMSK1 |= (1<<TOIE1); //Hablilitamos interrupcion TMR1 OVF
    TCNT1 = 3036;

}
int main(void) {
    uint8_t str_lcd[30];
    DDRB |= (1<<DDRB5);
    TMR1_init();
    INT1_init();
    init_uart();
    sei();
    while(1)
    {
        PORTB ^= (1<<PORTB5);
        _delay_ms(1);
        
        sprintf((char*)str_lcd,"RPS: %u | RPM: %u \n",rps,rpm);
        send_string(str_lcd);
    }
    return 0;
}

ISR(TIMER1_OVF_vect)
{
    TCNT1 = 3036;
    rps = pulsos / RANURAS;
    rpm = rps * 60;
    pulsos = 0;
}

ISR(INT1_vect)
{
    /*la variable pulsos se incrementa en 1 cada vez
    que recibe un flanco de subida por parte del
     sensor encoder*/
    pulsos++;


}