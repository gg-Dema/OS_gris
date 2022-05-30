#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#define MAX_NUM_ITEMS 20

//************** int VERSION ***************
typedef struct{
    ListItem list; 
    int info; 
} IntListItem; 

//print method in late binding
void IntListItem_print(struct ListItem* item){
    printf("[int] %d\n", ((IntListItem*)item)->info);
}

//virtual table for int list (INSTANCE)
ListItemOps int_list_item_ops ={
    .destroyFunct=0,
    .printFunct=IntListItem_print
}; 

//************** FLOAT VERSION ***************
typedef struct {
    ListItem* list; 
    float info_f;
} FloatListItem; 

//print method in Late Binding
void FloatListItem_print(struct ListItem* item){
    printf("[float] %f", ((FloatListItem*)item)->info_f);
}

//virtual table for float list (INSTANCE)
ListItemOps float_list_item_ops = {
    .destroyFunct = 0, 
    .printFunct=FloatListItem_print
};

//********************************************
//      fine classi figlie

int main(int argc, char const *argv[])
{
    
    ListHead head;
    List_init(&head);
    for (int i=0; i<MAX_NUM_ITEMS; ++i){
        ListItem* item=0;
    // the even elements are int, the odd elements are float
        if (i&0x1) {
            FloatListItem* new_element = (FloatListItem*) malloc(sizeof(FloatListItem));
            ListItem_constructor((ListItem*) new_element, &int_list_item_ops);
            new_element->info_f = i/2.0; 
            item = (ListItem*) new_element; 
        }
        else{
            IntListItem* new_element = (IntListItem*) malloc(sizeof(IntListItem));
            ListItem_constructor((ListItem*) new_element, &int_list_item_ops);
            new_element->info=i;
            item = (ListItem*) new_element;
        }
        List_insert(&head, head.last, item); 
    }
    List_print(&head);

    ListItem* aux=head.first;
    while(aux){
        ListItem* item=aux;
        aux=aux->next;
        List_remove(&head, item);
        free(item);
    }

    return 0;
}
