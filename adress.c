#include<stdio.h>

int main()
{
//     int rows,cols;
//     printf("Enter number of rows : ");
//     rows = scanf("%d",&rows);
//     printf("Enter the number of columns : ");
//     cols = scanf("%d",&cols);
//     int arr[rows][cols];

//     for(int i=0 ; i<rows ; i++)
//     {
//         for(int j=0 ; j<cols ; j++)
//         {
//            printf("Element %d %d ",i,j);2
//            scanf("%d",arr[i][j]); 
//         }
//         printf("\n");
//     }

//     int i,j;
//     printf("Enter the required element : ");
//     int index = scanf("%d %d",&i,&j);
//     int (*ptr)[cols] = arr;

//     void *adress=(void *)((char *)ptr + ((i*cols)+j)*sizeof(arr[0]));
//     printf("%p",adress);

//     return 0;
   

// }
// #include <stdio.h>

// int main()
// {
//     int arr[5] = {1,2,3,4,5};
//     int num;
//     printf("Enter a number between 1-5: ");
//     scanf("%d", &num);
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int address;

//     if (num >= size && num < 0)
//     {
//         printf("Invalid input! Please enter between 1 and 5.\n");
//     } 
//     else {
//         for (int i = 0; i <= size; i++) {
//             if(num == i){
//                 address = &arr + (i * sizeof(arr[0]));
//                 printf("Address: %d\n", address);
//             } 
//         }
//     }
//     return 0;
// }

int rows, cols;
    printf("\nEnter number of rows and columns for 2D array: ");
    scanf("%d", &rows);
    scanf("%d",&cols);
    int arr[rows][cols];
    printf("Enter elements of %d x %d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int i, j;
    printf("Enter row and column index of element to find address (0-based): ");
    scanf("%d%d", &i, &j);

    int (*ptr)[cols] = arr;

    printf("\n2D Array:\n");
    // printf("Base Address = %p\n", ptr);
    // printf("Address of arr2D[%d][%d] (using pointer) = %p\n", i, j, &arr[i][j]);

    printf("Calculated Address = %p",
           (void *)((char *)ptr + (((i * cols) + j) * sizeof(arr[0][0]))));

    return 0;
}
