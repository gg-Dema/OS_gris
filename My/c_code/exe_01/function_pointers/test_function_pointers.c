#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "functions.h"

int main(int argc, char const *argv[])
{
    printf("test_function_pointers | start\n");

    while(1){
        int input; 
        printf("test_function_pointers | enter a value in hex form -es \"ff\"\n");
        scanf("%x", &input); // %x int in formato exadec
        printf("\n");

        if(0xff < input){
            printf("test_function_pointers | WARNING, input value [0x%02x] excedes limit [0xff]\n", input);
            continue;
        }

        printf("test_function_pointers | input [0x%02x]\n", input);
        (*action)(input); 
    }

    printf("test_function_pointers | end\n");
    return 0;
}
