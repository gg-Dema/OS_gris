//programma per testare i gestori d'errore all'interno 
//dei processi

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

//gestori errori: 
void handler_for_child(){
    printf("sto gestendo le risorse del figlio\n");
}
void handler_for_parent(){
    printf("sto gestendo le risorse del padre\n");
}

//il gestore non viene invocato quando si esce con _exit()

int main(int argc, char const *argv[])
{
    pid_t pid = fork(); 


    if(pid==0){//child
        atexit(handler_for_child);
        _exit(1); //non dovrebbe eseguire il gestore risorse
        //exit(1); //gestisce le risorse del figlio 
        //in generale non si dovrebbe usare exit() --> è una funct C che esegue pulizie varie
        //exit() chiama _exit(), piu altre routine (EXE svuota buffer etc)
        //rischio di distruggere il buffer del padre (CREDO)
    }
    else{//parent
        atexit(handler_for_parent);
        exit(1);
    }   
    return 0;
}
