#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork(); 
    if (pid == -1){ //parent with errors
        perror("fork error"); 
        exit(EXIT_FAILURE);
    }
    if (pid == 0){ //child, lancio ls -l
        char* argv[] = {"ls", "-l", NULL}; 
        execvp("ls", argv); 
        _exit(1); 
    }

    pid = wait(NULL); //parent aspetta che almeno uno dei child termini
    //non mi interessa salvare lo stato dei processi figli, quindi passo NULL
    //al posto del puntatore ad int del buffer
    if(pid == -1){
        perror("wait error"); 
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS; 
}