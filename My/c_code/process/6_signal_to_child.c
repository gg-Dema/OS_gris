#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Esercizio inventato da me:
    2 processi, padre e figlio, il padre manda due segnali
    al figlio (sigursr1, sigterm)
    il figlio installa dei gestori, per il momento ignora il msg
    e termina se stesso con il kill

    lo sleep del padre serve a permettere al figlio di installare 
    correttamente i gestori.
    i gestori devono restare attivi per tutta la durata del processo
    la funct pause() mette il processo chiamante in pausa finche non arriva un segnale generale

*/

//handler function 
void msg_handler(int signum){
    char const msg[] = "F:\tricevo il segnale e lo ignoro\n";
    write(STDOUT_FILENO, msg, sizeof msg -1); 
}

void kill_handler(int signum){
    char const msg[] = "F:\tsarò ucciso presto\n";
    write(STDOUT_FILENO, msg, sizeof msg -1); 
    _exit(EXIT_SUCCESS); 
}


int main(int argc, char const *argv[])
{
    pid_t pid = fork(); 
    if(pid==0){ //child
        //definisco gestore errori
        struct sigaction act_msg = {0}; 
        act_msg.sa_handler = &msg_handler; 
        int ret = sigaction(SIGUSR1, &act_msg, NULL); 


        struct sigaction act_kill = {0}; 
        act_kill.sa_handler = &kill_handler; 
        int ret_2 = sigaction(SIGTERM, &act_kill, NULL);

        printf("F:\n\tfiglio pid %d, figlio vede pid_val: %d\n", getpid(), pid);
        //dopo aver definito la struct aspetto infinito finche il padre non manda il sig
        pause(); //aspetto il primo segnale
        pause(); //aspetto il secondo segnale
    }
    else{ //parent, pid contiene il valore del figlio
        printf("P:\n\tpadre ha pid %d, padre vede pid_val: %d (figlio)\n", getpid(), pid); 
        //mando segnale al figlio (pid)
        sleep(3);
        kill(pid, SIGUSR1); //segnale usabile come messaggio 
        kill(pid, SIGTERM);
        wait(NULL);
    }
    return EXIT_SUCCESS;
}
