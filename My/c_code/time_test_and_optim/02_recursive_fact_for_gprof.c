#include <stdio.h>

int factorial(int n){
    if (n==1) return 1; 
    return factorial(n-1) * n; 
}

int main(int argc, char const *argv[])
{
    int x = 19; 
    printf("factorial of 5 = %d\n", factorial(x));
    return 0;
}
