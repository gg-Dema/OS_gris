#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include "../avr_common/uart.h"

int main(){

    printf_init();

    //we connect pin 12, is 6 bit of port b (B6)
    const uint8_t mask = (1<<6); 
    DDRB &= ~mask;  // configuer pin as input, clearing the 6 bit
                    // input aka 0 
    PORTB |= mask;  // OR logico, "pullup resistor"

    while(1){
        int key=(PINB&mask)==0; //extract value of the 6th bit
        printf("switch %02x, %d\n", (int) PORTB, key); 
        _delay_ms(500); 
    }
    return 0;
}
