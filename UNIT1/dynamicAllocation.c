#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *)malloc(5 * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed using malloc.\n");
        return 1;
    }
    printf("Memory allocation using malloc.\n");
    for (int i = 0; i < 5; i++){
        arr[i] = i + 1;
        printf("%d \n", arr[i]);
    }

    //for (int i = 0; i < 5; i++)
    //printf("%d ", arr[i]);

    int *arr2 = (int *)calloc(5 , sizeof(int));
    if(arr2 == NULL)
    {
        printf("Memory allocation failed using calloc\n");
        free(arr);
        return 1;
    }

    printf("Array allocated using calloc:\n");
    for (int i = 0 ;i<5 ; i++)
    {
        arr2[i]=i + 1;
        printf("%d\n",arr2[i]);
    }
     
    int *temp = (int *)realloc(arr,10 * sizeof(int));
    if(temp == NULL)
    {
        printf("Memory reallocation failed using realloc\n");
        free(arr);
        free(arr2);
        return 1;
    }

    arr = temp;

    printf("Memory extra allocated using realloc\n");
    for(int i=5 ; i<10;i++)
    {
        arr[i]= i +1;
    }

    for(int i=0 ; i <10 ; i++)
    {
        printf("%d\n",arr[i]);
    }
    free(arr);
    free(arr2);

    printf("Memory successfully freed");
    return 0;
}
