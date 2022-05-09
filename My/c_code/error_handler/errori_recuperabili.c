//errore non fondamentale (magari basta pulire memoria CLEANUP)

#include <stdlib.h>
#include <stdio.h>
#include <errno.h> //contiene var globlae, con cod errore

int my_funct(){
    int res, *buffer = NULL;

    buffer = malloc(/*...*/ sizeof(int));
    if(buffer==NULL) goto cleanup; //errore nella chiamata
    //...
    res = chiamata(/*...*/);
    if(res != 0) goto cleanup;
    //...
    free(buffer);
    return 0;
    cleanup:
    //...
    if (buffer != NULL) free(buffer); //deallocazione da errore
    return -1; 
    //general il GOTO va evitato, non rende il codice leggibile
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
