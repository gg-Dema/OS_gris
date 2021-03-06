#include <stdint.h>
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "../avr_common/uart.h"

/*
    interrupt handler, per ogni interrupt si aumenta il counter
    utilizzo la macro ISR : direttiva del compilatore che conclude una funct con un return form interrupt
    + extra overhead interrupt table
*/



volatile uint8_t interrupt_occurred=0; //--> volatile non ottimizza la variabile, evita di renderla una costante automatica
volatile uint16_t int_count=0;

//ISR AKA INTERRUPT SERVICE ROUTINE
ISR(TIMER5_COMPA_vect){         //---> by avr interrupt for each micro machine 
    interrupt_occurred = 1;     //---> TIMER5_COMPA_vect è un numero, idx della interrupt table
    int_count ++;               //---> COMPA è il compare register A
} 
                        
int main(void){
    printf_init(); 
    const int timer_duration_ms = 100; 

    //configure time: set prescaler to 1024
    TCCR5A = 0;
    TCCR5B = (1<<WGM52) | (1 << CS50) | (1 << CS52); 

    uint16_t output_compare_register_value = (uint16_t)(15.62*timer_duration_ms); 
    OCR5A = output_compare_register_value; 

    cli(); //disable system interrupt
    TIMSK5 |= (1<<OCIE5A); //enable timer interrupt 
    sei(); //enable system interrupt
    while(1){
        while (!interrupt_occurred); 
        interrupt_occurred=0; 
        printf("int: %u\n", int_count); 
        }
        
}