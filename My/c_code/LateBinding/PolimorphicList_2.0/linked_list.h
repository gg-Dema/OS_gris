#pragma once 

struct ListItem;

//struttura delle funzioni da chiamare
typedef void (*Item_printFunct_pointer)(struct ListItem*);
typedef void (*Item_destroyFunct_pointer)(struct ListItem*);

//virtual function table 
typedef struct{
    Item_printFunct_pointer printFunct; 
    Item_destroyFunct_pointer destroyFunct; 
}ListItemOps; 

//elemento polimorfico della lista
typedef struct ListItem {
    ListItemOps* ops; 
    struct ListItem *next;
    struct ListItem *prev; 
} ListItem; 


//costruttore 
void ListItem_constructor(ListItem* item, ListItemOps* ops);
//wrapper
void ListItem_destroy(ListItem* item); 
void ListItem_print(ListItem* item); 

///////////////////////////////////////
//LIST HEAD PART ---> non polimorfica//
///////////////////////////////////////

typedef struct ListHead{
    ListItem* first;
    ListItem* last; 
    int size;  
} ListHead;

//definizione di metodi sulla lista, non polimorfici 
void List_init(ListHead* head); 
void List_print(struct ListHead* head); 
ListItem* List_find(struct ListHead* head, ListItem* item); 
ListItem* List_remove(struct ListHead* head, ListItem* item); 
ListItem* List_insert(ListHead* head, ListItem* previous, ListItem* item); 
