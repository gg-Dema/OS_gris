#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdio.h>
#include <util/delay.h>

#include "../avr_common/uart.h"

#define PIN_MASK 0X0F //ultimi 4 bit porta B (50-53)

volatile uint8_t previous_pins;
volatile uint8_t current_pins;

volatile uint8_t int_occurred=0; 
volatile uint16_t int_count=0; 

ISR(PCINT0_vect){
    previous_pins=current_pins; 
    current_pins = PINB & PIN_MASK;
    int_occurred = 1;
    int_count ++;  
}

int main(void){
    printf_init(); 
    DDRB &= ~PIN_MASK; //pin_mask as input
    PORTB |= PIN_MASK; //pull up
    PCICR |= (1<<PCIE0); //set interrupt on change FOR ALL PINS, looking up pcmsko
    PCMSK0 |= PIN_MASK; //indico che mi frega dei cambiamenti solo sugli ultimi pin

    sei(); 
    while(1){
        while(!int_occurred); 
        int_occurred = 0; 
        printf("int %u, p:%x, c:%x\n", int_count, previous_pins, current_pins); 
    }
}