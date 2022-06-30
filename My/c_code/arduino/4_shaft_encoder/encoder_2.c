#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "../avr_common/uart.h"
 


//my pin: PB1(52) e PB3(50)
//il prof sceglie altri pin (pb0 pb1) ---> input: 00000011 AKA 0x03
const uint8_t encoder_mask = 0b00001010;
// ~ =  0xA;
int main(){
    printf_init();
    DDRB &= ~encoder_mask; 
    PORTB |= encoder_mask;

    uint8_t previous_state = 0xA; 

    while(1){
        uint8_t current_state = PINB & encoder_mask;  
        if(current_state != previous_state){
            printf("CHANGE : Value on PIN B (B1| B3) %x\n", (int) current_state); //printa 10---> in esadecimale (se connetto tutti i pin)
                                                                    // se connetto qualche pin a ground il valore scende (8, 2, 0)
        }
        previous_state = current_state;
        _delay_ms(100);
    }
} 