//implementazione del metodo +1
#include "lib_0.h"
#include <stdio.h>

void plus_one(test* t){
    printf("origin: %d", t->x );
    t->x++;
    printf(" new_one: %d\n", t->x);
}
