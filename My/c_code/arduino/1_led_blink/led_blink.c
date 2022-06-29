#include <util/delay.h>
#include <stdio.h>
#include<stdint.h>
#include <avr/io.h>
#include "../avr_common/uart.h"

int main(void){

    printf_init(); 

    //led is connected to pin 13 -->by datasheet
    //è il 7 bit della porta b (PB7)
    //semantica: 0 ingresso, 1 in uscita.
    //configuro una maschera
    const uint8_t mask = (1<<7); 
    //operazione di shift ---> ">>"
    //configuro i pin come output
    DDRB |= mask; // OR EQUAL --> se era 0 mettilo a 1, else previous
    int k = 0; 
    while(1){
        printf("led %d\n", (k&1)); //stampo stato led
        //k è pari o dispari a seconda dell'ultimo bit ---> and binario
        if(k&1)
            PORTB=mask; 
        else
            PORTB=0; 
        _delay_ms(1000); //wait 1 sec
        ++k; 
    }

    return 0; 

}