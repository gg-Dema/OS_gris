#include <stdio.h>
#include <stdlib.h> //contiene atexit

void handler_1(){
    printf("uscita felice1\n");
}

void handler_2(){
    printf("uscita felice2\n");
}
 
void handelr_funct(){
    printf("hai interrotto il programma alla da dentro la funzione funct\n");
}

void funct(void (*handelr) (void)){
    atexit(handelr);
    return;
}

int main(){


    funct(handelr_funct);
    atexit(handler_1);
    atexit(handler_2);
    return 0; 
}

/*
print prima handler 2, poi handler 1, infine handler funct
io dichiaro prima funct, poi 1 e poi 2.
OGNI HANDLER é INVOCATO IN ORDINE INVERSO RISPETTO LA DICHIARAZIONE
*/