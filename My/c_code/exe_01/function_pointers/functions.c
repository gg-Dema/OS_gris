#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "functions.h"

ActionPtrFunct action = actionFnS1; 
unsigned int payload_size = 0; 

void actionFnS1(unsigned char input){
    printf("action Fn S1 | input [0x%02x] \n", input); 
    if (0xAA == input){
        action = actionFnS2;
        printf("next_state: S2\n\n");
    }
    else{
        printf("next_state: S1\n\n");
    }
    return; 
}

void actionFnS2(unsigned char input){
    printf("action Fn S1 | input [0x%02x] \n", input);
    if(0X55==input){
        action = actionFnS3; 
        printf("next_state: S3\n\n");
    }
    else{
        printf("next_state: S2\n\n");
    }
    return;
}

void actionFnS3(unsigned char input){

    printf("action Fn S3 | input [0x%02x] \n", input);
    payload_size = (unsigned int) (input); 
    printf("actionFnS3 | payload [ %d ]\n\n", payload_size); 
    action = actionFnS4;
    printf("next_state: S4\n\n");
    return;
}

void actionFnS4(unsigned char input){
    printf("actionFnS5 | no new input \n");
    if (payload_size--){
        printf("actionFnS4 | payload to read [ %d ] - value [0x%02x]\n\n",
        payload_size, input); 
    }
    else{
        action = actionFnS5;
        printf("next_state S5\n\n");
    }
}
void actionFnS5(unsigned char input){
    printf("actionFnS5 | input [0x%02x]\n", input);
    if(0XAA == input){
        action = actionFnS2;
        printf("next_state S2\n\n");
    }
    else{
        action = actionFnS1;
        printf("next_state S1\n\n");
    }
    return; 
}