#include "linked_list.h"
#include <stdio.h>
//implementazione dei metodi di list item 

void ListItem_constructor(ListItem* item, ListItemOps* ops){
    item->prev = item->next = 0; 
    item->ops = ops; 
}
void ListItem_destroy(ListItem* item){
    if(item->ops && item->ops->destroyFunct)
        (*item->ops->destroyFunct)(item); 
}
void ListItem_print(ListItem* item){
    if(item->ops && item->ops->printFunct)
        (*item->ops->printFunct)(item); 
}


//implementazione dei metodi della head AKA corpus list

void List_init(ListHead* head){
    head->first = 0; 
    head->last = 0; 
    head->size = 0;
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
    if(item->next || item->prev)
        return 0; 

    ListItem* next = prev? prev->next : head->first;
    if (prev) {
        item->prev=prev;
        prev->next=item;
    }
    if (next) {
        item->next=next;
        next->prev=item;
    }
    if (!prev)
        head->first=item;
    if(!next)
        head->last=item;

    ++head->size;
    return item;
}

ListItem* List_remove(ListHead* head, ListItem* item){

    ListItem* prev = item->prev; 
    ListItem* next = item->next; 

    if(prev){
        prev->next = next; 
    }   
    if(item==head->first)
        head->first = next; 
    if(item==head->last)
        head->last = prev; 
    head->size--;
    item->next = item->prev = 0; 
    return item; 
}


void List_print(ListHead* head){
    ListItem* item = head->first;  
    printf("Printing polimorphic list\n"); 
    int k = 0; 
    while(item){
        printf("list[%d]", k); 
        ListItem_print(item); 
        item = item->next; 
        ++k;
    }
}