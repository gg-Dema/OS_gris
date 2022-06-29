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

    while(1){
        uint8_t my_value = PINB & encoder_mask;  
        printf("Value on PIN B (B1| B3) %x\n", (int) my_value); //printa 10---> in esadecimale
        _delay_ms(100);
    }
}