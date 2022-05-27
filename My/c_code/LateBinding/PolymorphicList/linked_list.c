#include "linked_list.h"
#include <assert.h>
#include <stdio.h>

//************** LIST ITEM *********************

void ListItem_construct(ListItem* item, ListItemOps* ops){
    item->prev = item->next = 0; 
    item->ops = ops; 
}
void ListItem_destroy(ListItem* item){
    assert(item); 
    if(item->ops && item->ops->dtor_funct)
        (*item->ops->dtor_funct)(item); 
}
void ListItem_print(ListItem* item){
    assert(item); 
    assert(item->ops && item->ops->print_funct); 
    (*item->ops->print_funct)(item); 
}

// ********************** LIST CORPUS ***************

void List_init(ListHead* head){
    head->first = 0; 
    head->last  = 0; 
    head->size  = 0;
}

ListItem* List_find(ListHead* head, ListItem* item){
    ListItem* aux = head->first; 
    while(aux){
        if(aux==item)
            return item; 
        aux = aux->next; 
    }
    return 0; 
}


ListItem* List_insert(ListHead* head, ListItem* prev, ListItem* item){
    if(item->next || item->prev)//item non pulito
        return 0; 

#ifdef _LIST_DEBUG_
    ListItem* instance = List_find(head, item); 
    assert(!instance); 

    if(prev){
        ListItem* prev_instance=List_find(head, prev); 
        assert(prev_instance); 
    }
#endif    
    ListItem* next = prev ? prev->next : head->first; 
    if(prev){
        item->prev = prev; 
        prev->next = item; 
    }
    if(next){
        item->next = next; 
        next->prev = item; 
    }
    if(!prev)
        head ->first = item; 
    if(!next)
        head -> last = item; 
    ++head->size; 
    return item; 

}


ListItem* List_detach(ListHead* head, ListItem* item) {

#ifdef _LIST_DEBUG_
  // we check that the element is in the list
  ListItem* instance=List_find(head, item);
  assert(instance);
#endif

  ListItem* prev=item->prev;
  ListItem* next=item->next;
  if (prev){
    prev->next=next;
  }
  if(next){
    next->prev=prev;
  }
  if (item==head->first)
    head->first=next;
  if (item==head->last)
    head->last=prev;
  head->size--;
  item->next=item->prev=0;
  return item;
}

void List_print(ListHead* head){
    ListItem* item = head->first; 
    printf("PRINTING POLIMORPHIC LIST\n");
    int k=0; 
    while(item){
        printf("element[%d] : ", k); 
        ListItem_print(item); 
        item = item->next; 
        ++k; 
    }
}