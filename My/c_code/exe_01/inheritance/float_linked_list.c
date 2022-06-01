//implementazione base della classe linked_list
#include "float_linked_list.h"
#include "linked_list.h"
#include <stdio.h>

void FloatList_init(ListHead* head){
    head->first = 0; 
    head->last = 0; 
    head->size = 0; 
}

void FloatList_print(ListHead* head){
    ListItem* aux = head->first; 
    int k = 0; 
    printf("PRINTING FLOAT LIST\n");
    while(aux){
        printf("valore %d [%f]\n", k, ((FloatListItem*) aux)->value);
        aux = aux ->next; 
        ++k; 
    }
}

FloatListItem* FloatList_find(ListHead* head, ListItem* item){
    ListItem* aux = head->first; 
    while(aux){
        if(aux == item)
            return (FloatListItem*) item; 
        aux = aux ->next; 
    }
    return 0; 
}

FloatListItem* FloatList_remove(ListHead* head, ListItem* item){
    
    ListItem* prev = item->prev;
    ListItem* next = item->next; 

    if(prev){
        prev->next = next; 
    }
    if(next){
        next->prev = prev; 
    }

    if(item==head->last){
        head->last = prev; 
    }
    if(item==head->first){
        head->first = next;
    }

    head->size--; 
    item->next = item->prev = 0;
    return (FloatListItem*) item; 

}