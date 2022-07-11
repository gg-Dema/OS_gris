#include <stdint.h>
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "../avr_common/uart.h"

int main(void){
    printf_init();

    //choosen timer 4:
    TCCR4A = 0; //disables all PWM and interrupts

    TCCR4B = (1 << CS42) | (1 << CS40); 
    while(1){
        uint16_t timer_val = TCNT4; 
        printf("count %u\n", timer_val); 
        _delay_ms(1000); 
    } 
}
