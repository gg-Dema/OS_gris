//esperimenti con la lista polimorfica in c.

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "linked_list.h"
#define MAX_NUM_ITEMS 20

typedef struct{
    ListItem list; 
    int info;
} IntListItem;

void intListItem_print(struct ListItem* item){
    printf("[int] %d\n", ((IntListItem*)item)->info);
}

ListItemOps int_list_item_ops = {
    .dtor_funct=0, 
    .print_funct=intListItem_print
}; 

typedef struct{
    ListItem list; 
    float f;
} FloatListItem; 

void FloatListItem_print(struct ListItem* item){
    printf("[float] %f\n", ((FloatListItem*)item)->f);
}
//vtable for float list
ListItemOps float_list_item_ops = {
    .dtor_funct = 0,
    .print_funct = FloatListItem_print
}; 

int main(int argc, char const *argv[])
{
    ListHead head; 
    List_init(&head); 
    for (int i=0; i<MAX_NUM_ITEMS; ++i){
        ListItem* item=0; 
        if(i&0x1){ //and logico, equivalente di modulo 2
            FloatListItem* new_element = (FloatListItem*) malloc(sizeof(FloatListItem));
            ListItem_construct( (ListItem*) new_element, &int_list_item_ops);
            new_element->f = i/2.0; 
            item = (ListItem*) new_element; 
        }       
        else{
            IntListItem* new_element = (IntListItem*) malloc(sizeof(IntListItem));
            ListItem_construct((ListItem*) new_element, &float_list_item_ops); 
            new_element->info = i;
            item = (ListItem*) new_element; 
    }
    List_insert(&head, head.last, item); 
    }
    List_print(&head); 

    return 0;
}


