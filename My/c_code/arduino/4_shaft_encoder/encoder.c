#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include "../avr_common/uart.h"


/*ingresso: selezionare i pin d'input
  guardando datasheet scelgo pb --> pin 53 : pb0 
                                    pin 52 : pb1
*/                                    
const uint8_t encoder_mask = 0x03; //numero esadecimale con ultimi 2 bit a 1

int main(){
    printf_init();
    DDRB &= ~encoder_mask; 

    //prendo encoder mask (tutto 0 tranne ultimi 2)
    //mask:     00000011
    //nego l'encoder mask  ~ -> not bitAbit
    //mask:     11111100
    //facendo l'and con questa roba posso azzerare gli ultimi bit

    //metto a pullUp i pin in input: 
    //metto a 1 gli ultimi bit di portB 
    PORTB |= encoder_mask; // OR binario
    while(1){
        //leggo gli ultimi bit della porta b, vedo se hanno senso
        uint8_t last_two_bits = PINB & encoder_mask; 
        printf("%x\n", (int)last_two_bits); 
        _delay_ms(100);
    }

}