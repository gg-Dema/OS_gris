#pragma once 

typedef void (*ActionPtrFunct) (unsigned char); 

extern ActionPtrFunct action; 
extern unsigned int payload_size;

void actionFnS1(unsigned char input);
void actionFnS2(unsigned char input);
void actionFnS3(unsigned char input);
void actionFnS4(unsigned char input);
void actionFnS5(unsigned char input);


/*
    --------EXTERN KEYWORD----------

    extern aka gloab variables
    aka var defined outside the functions 

                VS
    
    auto aka local variables

*/