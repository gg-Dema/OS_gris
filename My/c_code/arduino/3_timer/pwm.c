#include <stdint.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include "../avr_common/uart.h"
/*  
    modulando l'intensità della pwm generata,   
    mando l'output sul pin 7 porta B (contiene il led)
    senza cutecom non brilla : aprire cutecom per vedere il led brillare

    il timer scelto è il primo (16 bit) ---> lo sto configuarando a 8 bit
*/

//config timer : waveGeneration Mode,  WGM 
//              COM ---> il tipo di pwm da generare (pos, neg),
//              CS  ---> scaling
#define TCCRA_MASK (1<<WGM10)|(1<<COM1C0)|(1<<COM1C1)
#define TCCRB_MASK ((1<<WGM12) | (1 << CS10))

int main(void){
    printf_init(); 

    //using timer 1
    TCCR1A = TCCRA_MASK;
    TCCR1B = TCCRB_MASK;

    //OUTPUT COMPARE REGISTER ---> 1 timer ha 3 ocr register
    OCR1AH = 0;
    OCR1BH = 0;
    OCR1CH = 0;
    OCR1CL = 1;
 
    const uint8_t mask = (1<<7); 
    DDRB |= mask; 
    uint8_t intensity = 0;
    while(1){
        OCR1CL = intensity; 
        printf("v %u\n", (int)OCR1CL); 
        _delay_ms(100); 
        intensity += 8; 
    }
}