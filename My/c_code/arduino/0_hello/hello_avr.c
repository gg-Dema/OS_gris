#include <util/delay.h>
#include <stdio.h>
#include "../avr_common/uart.h"
#include <avr/io.h>

int main(void){
    printf_init(); 
    int k=0; 
    while(1){
        printf("hello %d\n", ++k); 
        _delay_ms(100); 
    }
}