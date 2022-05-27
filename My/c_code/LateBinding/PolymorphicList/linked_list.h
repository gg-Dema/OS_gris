#pragma once
//ricorda che è un file .h ---> interfaccia 
struct ListItem; 

typedef void (*ListItemPrintFunct)(struct ListItem*);
typedef void (*ListItemDestroyFunct)(struct ListItem*);
//potevo usare la stessa typedef, ma per pulizia le aggiungo entrambe

typedef struct{
    ListItemDestroyFunct dtor_funct;
    ListItemPrintFunct print_funct; 
} ListItemOps;

typedef struct ListItem{
    ListItemOps *ops; //pointer to virtual method table
    struct ListItem* prev;
    struct ListItem* next; 
} ListItem; 

//wrapper
void ListItem_destroy( ListItem* item); 
void ListItem_print( ListItem* item); 

//costruttore generico
void ListItem_construct(ListItem* item, ListItemOps* ops);

/////////////////////////////////////////////////////////
//-------------------- LIST HEAD ------------------------
//      la lista (e la testa) non sono polimorfici,
//      non ci interessa al momento (eccetto print)

typedef struct ListHead{
    ListItem* first; 
    ListItem* last; 
    int size;
} ListHead; 
 
void List_init(ListHead* head); 
ListItem* List_find(ListHead* head, ListItem* item); 
ListItem* List_insert(ListHead* head, ListItem* previous, ListItem* item); 
ListItem* List_detach(ListHead* head, ListItem* item);
void List_print(ListHead* head); 