#include "LinkedList.h"
#include <assert.h>
#define NULL 0

void List_init(ListHead* head){
    head->first=NULL; 
    head->last=NULL;
    head->size=0;
}

ListItem* List_find(ListHead* head, 
                    ListItem* item){
    ListItem* aux = head->first; 
    while (aux)
    {   if(aux==item)
            return item; 
        aux = aux ->next;

    }
    return NULL;    
}

ListItem* List_detach(ListHead* head, ListItem* item){

#ifdef _LIST_DEBUG_
    // we check that the element is in the list
    ListItem* instance = List_find(head, item);
    assert(instance);
#endif

    ListItem* prev = item->prev;
    ListItem* next = item->next; 
    if(prev){
        prev->next = next;
    }
    if(next){
        next->prev = prev; 
    }
    if(item==head->first){
        head->first = next;
    }
    if(item==head->last){
        head->last=prev; 
    }
    head->size--;
    item->next = item->prev = NULL;
    return item;
}


