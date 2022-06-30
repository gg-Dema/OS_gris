#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "../avr_common/uart.h"
 
/*
  nella prima versione di questo programma, copiata dal prof, avevo scelto altre pin d'input
  Successivamente è stato utile costruire una tabella e il meccanismo d'accesso a tale tabella si basava sui 
  pin 0 e 1 di una generica porta. Per questo motivo ho rinunciato all'uso dei pin 50 e 52, corrispondenti a PB0 e PB3 
 */
//il prof sceglie altri pin (pb0 pb1) ---> input: 00000011 AKA 0x03
const uint8_t encoder_mask = 0b0000011;
static const int8_t transition_table []=
  {
      0,  //0000
      1,  //0001
     -1,  //0010
      0,  //0011
     -1,  //0100
      0,  //0101
      0,  //0110
      1,  //0111
      1,  //1000
      0,  //1001
      0,  //1010
     -1,  //1011
      0,  //1100
     -1,  //1101
      1,  //1110
      0   //1111
   
};

int main(){
    printf_init();
    DDRB &= ~encoder_mask; 
    PORTB |= encoder_mask;
    
    uint16_t counter = 0x0; 
    uint8_t previous_state = 0x0; 

    while(1){
        uint8_t current_state = PINB & encoder_mask;  
        if(current_state != previous_state){
            //opt 1: ---> swicht case 
            //opt 2: ---> look up table a 4 bit come chiave
            uint8_t idx = (previous_state<<2 | current_state);
            counter += transition_table[idx];
            //--> prev state: 000000xy. current state: 000000zk ---> voglio 0000xyzk (sposto di 2 xy e mando in OR bitForBit)
            printf("CHANGE :\n\t Value on PIN B (B1| B3) %x"\
                    "\n\tprevious status: %x"\
                    "\n\tcounter: %d",
                  (int) current_state, 
                  (int) previous_state, 
                  (int) counter); 
        }
        previous_state = current_state;
        _delay_ms(100);
    }
} 