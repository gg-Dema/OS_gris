//ereditarietà senza polimorfismo
#pragma once
#include <assert.h>
#include <stdint.h>
#include "linked_list.h"

typedef struct FloatListItem{
    ListItem item; 
    float value; 
} FloatListItem ;


//nuovi metodi della lista FLOAT List
void FloatList_print(ListHead* head); 
void FloatList_init(ListHead* head); 
FloatListItem* FloatList_find(ListHead* head, ListItem* item); 
FloatListItem* FloatList_remove(ListHead* head, ListItem* item);
