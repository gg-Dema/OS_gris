#include <stdio.h>
#include <stdlib.h> //contiene atexit

void handler_1(){
    printf("uscita felice1\n");
}

void handler_2(){
    printf("uscita felice2\n");
}

int main(){
    atexit(handler_1);
    atexit(handler_2);
    return 0; 
}

/*
print prima handler 2, poi handler 1
gli handler sono invocati in ordine inverso rispetto alla dichiarazione
*/