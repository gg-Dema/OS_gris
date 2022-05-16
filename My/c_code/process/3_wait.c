#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



int main(){

    pid_t pid = fork(); 
    if(pid==-1) {
        perror("fork"); 
        exit(EXIT_FAILURE); 
    }
    if(pid==0){
        printf("Processo figlio, restituisce 25");
        _exit(25);
    }

    int status; 
    pid = wait(&status); //pid ora contiene il pid del figlio terminato
    if (pid == -1){
        perror("errore in wait");  //print error 
        exit(EXIT_FAILURE); 
    }
    if(WIFEXITED(status)){
        printf("il figlio ha restituito %d\n", WEXITSTATUS(status)); 
    }
    return EXIT_SUCCESS; 
}