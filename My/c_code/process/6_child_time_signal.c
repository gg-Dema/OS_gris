#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define LIMIT 100000
#define USEC_LIMIT 100

int main(int argc, char const *argv[])
{
    
    pid_t first_child, pid = fork(); 
#ifdef DEBUG
    if(pid==-1){
        perror("fork, first_child"); 
        exit(EXIT_FAILURE);
    }
#endif

    if(pid==0){//child
        first_child = getpid(); 
        int i=0; 
        for(; i<LIMIT; i++){
            //free run
        }
        _exit(EXIT_SUCCESS); 

    }
    else{//parent: 
        pid_t pid_2 = fork(); 

        if(pid_2==0){//child 2 |--> pid=pid padre
            //alarm manda a se stesso un SIGALRM
            //il gestore deve stare qua
            struct sigaction act = {0}; 
            act.sa_handler = 0; // DEFINIRE --> printa l'errore, killa tutti i figli
            int gest = sigaction(SIGALRM, &act, NULL); 

#ifdef DEBUG
            if(gest == -1){
                perror("GESTORE NON ISTALLATO"); 
            }
#endif
            ualarm(USEC_LIMIT, 0);
        }
        else{
            //parent
            int status_1, status_2; 
            wait(&status_1); 
            wait(&status_2);
            //voglio un gestore per il padre??
        }

    }
    return EXIT_SUCCESS;
}
