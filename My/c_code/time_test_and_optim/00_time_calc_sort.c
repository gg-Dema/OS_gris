#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h> //for clock_gettime

#define NUM 5000 //prova ad eseguirlo con 5

double get_real_time_msec(){
    struct timespec ts; 
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec*1E03 + ts.tv_nsec*1E-06; 
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
    
    double start = get_real_time_msec(); 
    sort(v, NUM); 
    double elapsed = get_real_time_msec() - start;

    printf("tempo richiesto al sort : %f msec\n", elapsed );
    return EXIT_SUCCESS;
}
