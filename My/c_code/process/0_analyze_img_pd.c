#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int i[10000000], j=10; //var global
int main(int argc, char* argv[]){
    static char *k = "hello";
    int *p = malloc(sizeof(int)); 
    free(p); 
    printf("&i=%p | &j=%p | &main=%p | &argc=%p |\n", &i, &j, &main, &argc);
    printf("&k=%p | k=%p  |  &p=%p   | p=%p\n", &k, k, &p, p); 
    //pause() questo serve a bloccare il programma e poter usare ps -e | grep mem
    return 0; 
}

/*
i -> .bss           (inizializzato a 0)
j = .data,          (inizializzato diverso da 0)
main = .text        (indirizzo codice macchina)
argc, argv = stack  (parametri passati al main)
k = data            (var loc statica con indirizzo str (init diverso 0))
*k = data           (caratteri stringa (init diverso da 0))
p = stack           (chiamata by malloc)
*p = heap           (blocco in heap, puntato da p (array))

*/