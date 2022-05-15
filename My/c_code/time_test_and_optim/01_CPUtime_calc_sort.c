#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <assert.h>
#define NUM 500

double get_user_time_msec(){
    struct rusage ru; //r_usage AKA resource usage
    getrusage(RUSAGE_SELF, &ru); 
    return ru.ru_utime.tv_sec*1E03 + ru.ru_utime.tv_usec*1E-3; 
}

double get_system_time_msec(){
    struct rusage ru; 
    getrusage(RUSAGE_SELF, &ru); 
    return ru.ru_stime.tv_sec*1E03 + ru.ru_stime.tv_usec*10E-3; 
}

void sort(int *v, int n) {
    int i, j;
    for (i=0; i<n; ++i)
        for (j=1; j<n; ++j)
            if (v[j-1] > v[j]) {
                int tmp = v[j-1];
                v[j-1] = v[j];
                v[j] = tmp;
            }
}




int main(int argc, char const *argv[])
{
    int i, *v = malloc(NUM*sizeof(int)); 
    assert (v != NULL); 

    for(i=0; i<NUM; i++)
        v[i] = NUM -i -1; 
    
    double start_user = get_user_time_msec(); 
    double start_system = get_system_time_msec();
    sort(v, NUM); 
    double elapsed_user = get_user_time_msec() - start_user;
    double elapsed_system = get_system_time_msec() - start_system;

    printf("tempo richiesto al sort :\n%f msec per l'user\n%f msec per il system\n", elapsed_user, elapsed_system);
    return EXIT_SUCCESS;
}
