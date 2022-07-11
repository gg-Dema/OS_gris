/*
    cambiamento stato su pin: 21 ---> INT0_vect
    (nel datasheet ci sta la dicitura int0)
*
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdio.h>

#include "../avr_common/uart.h"

volatile uint8_t interrupt_occurred = 0; 
uint16_t int_count = 0; 

ISR(INT0_vect){
    //devo passare a ISR la posizione che 
    //voglio occupare nell'interrupt vector
    interrupt_occurred=1; 
    int_count++; 
}

int main(void){
    printf_init();
    printf("interrupt vector pos: %x \n", INT0_vect); 
    DDRD = 0x0;  //all pin port D as input
    PORTD = 0x1; //pull up

    //enable interrupt 0; 
    EIMSK |= 1 << INT0; //-->external interrupt mask
    //trigger int0 on rising edge (segnale da 0 a 1)
    EICRA = 1<<ISC01 | 1<<ISC00; 
    sei(); 
    while(1){
        while(!interrupt_occurred); 
        interrupt_occurred=0; 
        printf("int %u\n", int_count); 
    }
}