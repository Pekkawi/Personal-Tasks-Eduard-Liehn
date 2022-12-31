#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include "usart.h"
#include <stdbool.h>

void setup_motor(){
DDRD = DDRD|(1<<6); //ENA
DDRD = DDRD|(1<<7);//IN1
DDRB = DDRB |(1<<1); //IN2
TCCR0A = 0xA3; 
TCCR0B |= 0x05;
PORTB |= (1<<1);//IN2 5V
}


int main(){
io_redirect();
uart_init();
setup_motor();
int motor=255/5;
while(1){
OCR0A=motor;
}


}