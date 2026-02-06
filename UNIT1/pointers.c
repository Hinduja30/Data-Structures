#include<stdio.h>

int main(){
    int *intPointer;
    char *charPointer;
    void *voidPointer;

    printf("Size of int pointer: %zu bytes \n",sizeof(intPointer));
    printf("Size of char pointer: %zu bytes \n",sizeof(charPointer));
    printf("Size of void pointer: %zu bytes \n",sizeof(voidPointer));

    return 0;
}