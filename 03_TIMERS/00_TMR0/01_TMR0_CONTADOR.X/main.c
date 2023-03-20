#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

unsigned char str_buffer[20];

void init_uart(void)
{
    DDRD |= (1<<DDRD1); //tx ccomo salida
    
    UCSR0B |= (1<<TXEN0); //habilitamos transmisor USART0
    UCSR0C |= (1<<UCSZ00) | (1<<UCSZ01); //configuramos el dato a 8 bits
    UBRR0 = 103; //USART a 9600 baudios a 16Mhz

}

void send_char(unsigned char c)
{
    while((UCSR0A & (1<<UDRE0)) == 0);  //while(!(UCSR0A & (1<<UDRE0)));
    UDR0 = c;  //enviar caracter por uart
    
}

void send_string(const unsigned char *pStr)
{
    while(*pStr != 0) // 0 = '\0'
    {
        send_char(*pStr);
        pStr++; //avanza a la siguiente direccion de la cadena
    }
}


int main(void) {
    
    DDRB |= (1<<DDRB5);
    TCNT0 = 0;
    TCCR0B |= (1<<CS00)|(1<<CS01)|(1<<CS02); //clock externo
    
    init_uart();
   
    while(1)
    {
        PORTB^=(1<<PORTB5);
        _delay_ms(500);
        sprintf(str_buffer,"Contador: &u\n",TCNT0);
        send_string(str_buffer);
    }
    return 0;
}

