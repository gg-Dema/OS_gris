#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "float_linked_list.h"
#define MAX_LEN 20

int main(int argc, char const *argv[])
{
    ListHead head; 
    FloatList_init(&head); 
    printf("ho creato la lista\n");
    for(int i=0; i<MAX_LEN; ++i){
        
        FloatListItem* new_item = (FloatListItem*) malloc(sizeof(FloatListItem));
        if(!new_item){
            printf("out of memory\n");
            break; 
        }
        new_item-> item.prev = 0; 
        new_item-> item.next = 0; 
        new_item-> value = i/2.0;

        ListItem* result = List_insert(&head, head.last, (ListItem*) new_item);         
    }
    FloatList_print(&head); 
    return 0;
}
