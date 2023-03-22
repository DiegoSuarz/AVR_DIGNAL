
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

  
#ifndef XC_USART_H
#define	XC_USART_H

#include <xc.h> // include processor files - each processor file is guarded.  

void init_uart(void);
void send_char(unsigned char c);
void send_string(const unsigned char *pStr);

#endif	/* XC_HEADER_TEMPLATE_H */

