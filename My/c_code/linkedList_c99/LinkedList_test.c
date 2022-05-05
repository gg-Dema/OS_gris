#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkedList.h"
#define MAX_NUMB_ITEMS 50


//derived class
typedef struct  IntListItem{
    ListItem list;
    int info;
} IntListItem; 

//metodo proprietario
void IntList_print(ListHead* head){
    ListItem* aux = head->first; 
    printf("["); 
    while (aux)
    {   IntListItem* element = (IntListItem*) aux; 
        //il cast in c non comporta creazione di codice
        //solo nel puntatore ovviamente 
        printf("%d ", element->info); 
        aux = aux -> next; 
    }
    
}

int main(int argc, char const *argv[])
{
    
    ListHead head;
    List_init(&head);

    for(int i=0; i<MAX_NUMB_ITEMS; ++i){

        IntListItem* new_element = (IntListItem*) malloc(sizeof(IntListItem));
        if (!new_element){
            pritnf("out of memory\n");
            break; 
        }

        new_element-> list.prev = 0;
        new_element-> list.next = 0;
        new_element-> info = i; 
        ListItem* result = List_insert(&head, head.last, (ListItem*) new_element);
        assert(result);

    }
    IntList_print(&head);


    return 0;
}
