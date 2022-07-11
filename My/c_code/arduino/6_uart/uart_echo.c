#include <stdint.h>
#include <avr/io.h>

#define BAUD 19600
#define MYUBBR (F_CPU/16/BAUD-1)

void UART_init(void){
    //regolo velocità di lettura
    UBRR0H = (uint8_t) (MYUBBR>>8);
    UBRR0L = (uint8_t) MYUBBR; 

    //---> UCSR uart control status register {a|b|c} ---> a aka ho finito di scrivere/leggere
    //sto indicando quanti bit devo leggere per volta
    UCSR0C = (1<<UCSZ01) | (1 << UCSZ00); 

    //ENABLE RX(read) TX(scrittura)
    UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0); 
}

void UART_putChar(uint8_t c){
    while ( !(UCSR0A & (1<<UDRE0))); //busy waiting 
    UDR0 = c; //uart data register
}

uint8_t UART_getChar(void){
    while( !(UCSR0A & (1<<RXC0))); //busy waiting
    return UDR0; 
}

//STRING VERSION: 
uint8_t UART_getString(uint8_t* buf){
    uint8_t* b0 = buf; //beginning of buffer
    while(1){
        uint8_t c = UART_getChar(); 
        *buf = c; 
        ++buf; 
        if(c==0) return buf - b0; //lunghezza buffer
        if(c=='\n' || c=='\r'){
            *buf = 0; 
            ++buf; 
            return buf-b0;
        }
    }
}

void UART_putString(uint8_t* buf){
    while(*buf){
        UART_putChar(*buf); 
        ++buf; 
    }
}

//MAIN TEST: 
#define MAX_BUF 256
int main(void){
    UART_init(); 
    UART_putString( (uint8_t*) "write somethings, i'll repeat it\n"); 
    uint8_t buffer[MAX_BUF]; 
    while(1){
        UART_getString(buffer); 
        UART_putString( (uint8_t*) "ok, ripeto:"); 
        UART_putString(buffer);
    }
}
