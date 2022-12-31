#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include "usart.h"
#include <stdbool.h>

void setup_octocoupler(){
TCCR1A = 0x00;
TCCR1B = 0xC5; 
DDRB &= ~0x01;
PORTB |= 0x01; //enable pull-up
TCNT1=0;
}

int main(){
 io_redirect();
 uart_init();
setup_octocoupler();

while(1){
unsigned int time=0;
while( (!(TIFR1 & (1<<ICF1)))){}
TIFR1 = TIFR1|(1<<ICF1);
time = ICR1;
TCNT1=0;
time/=(15.625);
printf("%u\n",time);//time in milliseconds
_delay_ms(1000);
}

}