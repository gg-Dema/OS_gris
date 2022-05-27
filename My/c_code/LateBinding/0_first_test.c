#include <stdio.h>

struct A;

typedef void (*A_PrintFnPtr)(struct A*); 

void A_print_impl(struct A* a){
    printf("A\n");
}
void B_print_impl(struct A* a){
    printf("B\n"); 
}

typedef struct{
    /* data */
    A_PrintFnPtr print_fn; 
} A_ops;

typedef struct A{
    /* data */
    A_ops * ops; 
} A;

typedef struct B{
    A parent; 
}B;

A_ops a_ops = {.print_fn = A_print_impl}; 
A_ops b_ops = {.print_fn = B_print_impl}; 


//just a wr ap per
void A_print(struct A* a_ptr){
    (*a_ptr -> ops -> print_fn)(a_ptr); 
}

int main(int argc, char const *argv[])
{
    A a1 = {.ops = &a_ops};
    A a2 = {.ops = &a_ops}; 
    B b1 = {.parent.ops = &b_ops};
    B b2 = {.parent.ops = &b_ops};

    A* a_ptr = &a1; 
    A_print(a_ptr);

    a_ptr = (A*) &b1; 
    A_print(a_ptr);

    a_ptr = &a2; 
    A_print(a_ptr);

    a_ptr = (A*) &b2; 
    A_print(a_ptr);


    return 0;
}
