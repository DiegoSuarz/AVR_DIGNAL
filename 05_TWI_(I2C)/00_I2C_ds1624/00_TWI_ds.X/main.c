#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "i2c_master.h"
#include "ds1624.h"
#include "usart.h"
#include <stdio.h>

int main(void) {
    
    unsigned int temp;
    unsigned char buffer_str_int[3];
    unsigned char buffer_str_decimal[5];
    init_uart();
    i2c_init();
    init_DS1624();
    while(1)
    {
        temp = read_temp();
        sprintf((char*)buffer_str_int,"%d",(unsigned char)((temp & 0xFF00)>>8));
        send_string(buffer_str_int);
        sprintf((char*)buffer_str_decimal,".%u C\n",(unsigned char)((temp & 0x00FF)));
        send_string(buffer_str_decimal);
    
    }
    return 0;
}


