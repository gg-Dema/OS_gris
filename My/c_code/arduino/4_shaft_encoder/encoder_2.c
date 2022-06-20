#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include "../avr_common/uart.h"


/*ingresso: selezionare i pin d'input
  guardando datasheet scelgo pb --> pin 53 : pb0 
                                    pin 52 : pb1
*/       
static const int8_t _transition_table[] = {
    //trick per capire tutto : 
    //indice = numero binario ma tradotto, sto solo contando in binario

    //notare che gli stati non sono altro che un incremento/decremento (00 to 01)
    0,  // 00 -> 00 
    +1, // 00 -> 01
    -1, // 00 -> 10
    0,  // 00 -> 11 // è come perdere transizione (nel dubbio non faccio nulla)
    //nuovo stato: 01
    -1,  //0100
    0,  //0101
    0,  //0110
    1,  //0111
     //nuovo stato 10
    1,  //1000
    0,  //1001
    0,  //1010
    -1,  //1011
    //nuovo stato 11
    0,  //1100
    -1,  //1101
    1,  //1110
    0   //1111
    };

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


    uint16_t counter=0x0;
    uint8_t previous_state = 0x0;

    while(1){
        //leggo gli ultimi bit della porta b, vedo se hanno senso
        uint8_t current_state = PINB & encoder_mask; 
        if(current_state != previous_state){
            //crezione lookUp table in 4 bit (contengono stato precedente e stato successore)
            /*
            vedendo macchina a stati della slide: 
            le coppie stato prec/succ --> sono 4 bit
                entry 0001 contiene +1 : passaggio da 00 a 01 = +1
            creo indice di un vettore (1, -1, 0) 
           
            compongo numero binario per indice lookUp table
            prev shift di 2 a sx + OR con current state
            prev = 00 next = 01 ---> voglio costruire 0001
            prendo 00, shifto a sx e mando in or il nuovo
            */
           //INDICE TAB: 
            uint8_t idx = previous_state << 2 | current_state; 
            counter += _transition_table[idx];
            printf("state change %x --> %x, value: %u\n",
                    (int)previous_state, 
                    (int)current_state,
                    (int)counter); 
        }
        previous_state=current_state; 
        _delay_ms(1);
    }

}