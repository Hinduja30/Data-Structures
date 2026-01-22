#include<stdio.h>

int main()
{
    int num  ,*ptr ,ele;
    printf("Enter the number of elements:");
    scanf("%d",&num);

    int arr[num];

    for(int i=1 ; i<=num ; i++)
    {
        printf("Enter element %d : ",i);
        scanf("%d",&arr[i]);
    }

    ptr=arr;
    printf("Enter the element you need adress of: ");
    scanf("%d",&ele);


    void *adress=(void *)((char *)ptr + (ele * (sizeof(arr[1]))));
    printf("The adress of %d th element is :%p",ele,adress);


}



