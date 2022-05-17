#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    struct sigaction act = { 0 };             //preprazione struttura
    act.sa_handler = SIG_IGN;                 // segnale ignorato
    int ret = sigaction(SIGINT, &act, NULL);  //installo gestore

    //act diversa da null --> 
    //      nuova struct che definisce il comportamento
    //oact (old act) uguale a null -->
    //      l'attuale struttura che definisce il compo viene caricata qua


    /*
    parametri della struttura sigaction: 
        void( *sa_handler) (int signum): ---> 
                gestore, ha uno dei tre valori:
                    SIG_IGN
                    SIG_DFL (default)
                    codice utente della forma void handler(int signum)

        int sa_flags: 
            SA_RESTART: restart function dopo la gestione del segnale
            SA_SIGINFO: se non imposto, la gestione viene seguita da sa_handler, vedere grisetti

    */

    if (ret == -1){
        perror("gestore sigaction non installato"); 
        exit(EXIT_FAILURE); 
    }

    unsigned i = 0; //per ciclo
    while(i++ >= 0){
        if (i % 10000000000 == 0)
            printf("0XDEADBEEF ___ \n"); 
    }

    return EXIT_SUCCESS; 
    //la struct act è ancora visibile --> è necessario che rimanga in vita
    //deve essere nello stesso scope del segnale da gestire
    //se lo imposto tramite funzione vado in out_of_scope
    
}