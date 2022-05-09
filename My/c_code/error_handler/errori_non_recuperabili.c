#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


void handler(){
    printf("speravi di killarmi cosi, eh?");
}

int main(int argc, char const *argv[])
{
    assert(2>3);
    atexit(handler);
    return 0;
}
//se esiste un assert non verificato non si può andare avanti.
