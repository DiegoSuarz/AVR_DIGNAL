/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */


#ifndef XC_ADC_H
#define	XC_ADC_H

#define VREF 5.0
#define RES 1024.0

void ADC_init(void);
unsigned int ADC_convert();
float convert_volt();

#endif	/* XC_ADC_H */

