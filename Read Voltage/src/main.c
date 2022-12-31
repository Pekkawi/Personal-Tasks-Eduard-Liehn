#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include "usart.h"


void setup_adc0(){
ADMUX = ADMUX | 0x40;
ADCSRB=ADCSRB & (0xF8);
ADCSRA = ADCSRA | 0xE7; 
 }


 int main(){
 io_redirect();
 uart_init();
 setup_adc0();

 while(1){

 unsigned int adclow = ADCL;
adclow = (adclow + ((ADCH & 0x03) << 8));
float vm = ((adclow*1.0)/1023.0)*5.0;

printf("%f\n",vm);
_delay_ms(1000);
 }

 }