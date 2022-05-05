#include <assert.h>
#include "LinkedList.h"


void List_init(ListHead* head){
    head->first=0; 
    head->last=0;
    head->size=0;
}

ListItem* List_find(ListHead* head, ListItem* item){

    ListItem* aux = head->first; 
    while (aux)
    {   if(aux==item)
            return item; 
        aux = aux ->next;
    }
    return 0;    
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
    item->next = item->prev = 0;
    return item;
}


ListItem* List_insert(ListHead* head, ListItem* prev, ListItem* item){
    if( item->next || item ->prev)
        return 0;
    
#ifdef  _LIST_DEBUG_
    //we check that the element is not in the list
    ListItem* instance = List_find(head, item);
    assert(!instance);

    //we check that the previous is in the list
    if(prev){
        ListItem* prev_instance=List_find(head, prev);
    }
    assert(prev_instance);

#endif

    ListItem* next = prev ? prev->next : head->first;
    if(prev){
        item->prev = prev;
        prev->next = item; 
        //my error--> stavo assegnando male i puntatori,
        // chiudendo a cerchio il tutto| il codice seguente è solo un memorandum
        //item->next = item;
    }
    if(next){
        item->next=prev;
        item->prev=item; 
    }

    if(!prev) head->first=item;
    if(!next) head->last=item;
    ++head->size; 
    return item; 
}
