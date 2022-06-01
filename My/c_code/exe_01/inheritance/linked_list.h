#pragma once


typedef struct ListItem{
    struct ListItem* prev; 
    struct ListItem* next; 
}ListItem;
//no metodi per la classe ListItem base---> la devo estendere,
//                                          tanto vale progettare i metodi dopo

typedef struct ListHead{
    ListItem* first; 
    ListItem* last; 
    int size; 
}ListHead; 

void List_init(ListHead* head);
void List_print(ListHead* head); 
ListItem* List_find(ListHead* head, ListItem* item); 
ListItem* List_remove(ListHead* head, ListItem* item); 
