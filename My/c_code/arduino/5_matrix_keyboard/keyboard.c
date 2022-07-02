#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include "../avr_common/uart.h"

/* 
*    tastiera a matrice 4x4, connessa sulla porta A (pins 71-78)
*    primi bit : outpt || ultimi bit : input
*/

//struct con esempio di bitField ---> i campi fatti da 1 bit e 7 bit (Status 1, key 7)
typedef struct{
    uint8_t status : 1;  //primo bit:    1=pressed, 0=released
    uint8_t key : 7;     //ultimi sette: key number [0 - 16]
} KeyEvent;              //le operazioni matematiche sono date dall'uint8_t

uint16_t key_status; //1 bit per key, stato generale tastiera

uint8_t keyScan(KeyEvent* events){
    uint16_t new_status=0; 
    int num_events=0; 
    uint8_t key_num=0;

    for(int r=0; r<4; ++r){
        uint8_t row_mask = ~(1<<(r+4)); //--> sta shiftando un uno di r+4 pos.
                                        //    sto negando per rendere piu naturale la lettura: 1=evento, 0=nada
                                        //    (r) è il numero di riga
                                        /*    exe: 00001000; 
                                                   00010000;
                                                   00100000;
                                                   01000000;
                                                   10000000; 
                                        */
        PORTA = row_mask; 
        _delay_us(100);
        uint8_t row = ~(0x0F & PINA); 
        for(int c=0; c<4; ++c){
            uint16_t key_mask = 1 << key_num;  //maschera tasto evento precedente (AUTO INCREMENTO)
            uint16_t col_mask = 1 << c;  //iteratore per i tasti della riga (muovo un 1 per ogni pos) (MASCHERA)

            uint8_t cs=(row & col_mask)!=0; //key pressed 
            if (cs){
                new_status |= key_mask; 
            }
            //confronto stato precedente e corrente (se era premuto in entrambi i casi --> no evento)
            uint8_t ps = (key_mask&key_status)!=0; 

            if(cs!=ps){ //stati diversi, fare aggiornamento evento
                KeyEvent e; 
                e.key = key_num; 
                e.status = cs; 
                events[num_events]=e; 
                ++num_events; 
            }
            ++key_num;
        }
        row_mask = row_mask << 1;
    } 
    key_status=new_status; 
    return num_events; 
}

#define MAX_EVENTS 16

int main(void){
    printf_init(); 

    //config porta A:
    DDRA=0xF0; //primi quattro out, ultimi 4 in
    PORTA=0x0F; //pull up on inputs buts

    KeyEvent events[MAX_EVENTS]; 

    while(1){
        uint8_t num_events=keyScan(events); 
        for(uint8_t k=0; k<num_events; ++k){
            KeyEvent e=events[k]; 
            printf("e:[%d %d]\n", (int)e.status, (int)e.key); 
        }
    }
}