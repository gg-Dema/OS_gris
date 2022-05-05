#include "lib_0.h"
#include <stdio.h>

int main(int argc, char const *argv[]){
    test t; 
    printf("in main: t.x = %d\n", t.x);
    t.x = 0; 
    plus_one(&t);
    printf("in main: t.x = %d\n", t.x);
}