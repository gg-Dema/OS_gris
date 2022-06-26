#include <util/delay.h>
#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>
#include "../../c_code/arduino/avr_common/uart.h"

//lettura su porta
//porta H3 ---> pin 6
int main(){
    printf_init(); 
    const uint8_t mask = (1<<3);
    DDRH &= ~mask; //setto a 0 il pin che voglio leggere-->INPUT
    //stampo sulla seriale cosa ho letto

    //qui sto mettendo a pull up: carico il valore alto sul pin come default
    //cosi se ci scrivo non cambia nulla
    //metto un 
    PORTH |= mask; 
    while(1){
        //pin AKA registro lettura
        //mandare la porta in and con la maschera equivale a controllare i valori =1 della maschera
        //per funzionare collegare il pin a massa (gnd) 
        //  passo da pullUp a 0 ---> cambiamento stato
        int key=(PINH & mask) == 0; 
        printf("switch %02x, %d\n", (int) PORTH, key);
        //il numero post switch corrisponde al valore hex della porta
        _delay_ms(500);
    }
    
}