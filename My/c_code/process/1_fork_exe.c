#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //chiamate a sistema per fork

int main(){
    pid_t pid = fork(); 
    //pid_t sostanzialmente è un intero
    // il valore di pid dipende dal processo in exe

    if(pid == -1){
        perror("fork"); 
        exit(EXIT_FAILURE);
    }
    if(pid == 0){
        printf("processo figlio, ogni figlio si considera indipendente\n");     
    }
    else{
        //pid del padre assume valore reale, non ha un numero prestabilito
        printf("processo padre, pid: %d\n", pid);
    }
    return EXIT_SUCCESS; 
}