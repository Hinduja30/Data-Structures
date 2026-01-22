#include<stdio.h>

int main(){
    int arr[]={1,2,3,4,5};
    //average(arr);
//}

//int average(int array){
    int sum=0;
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0 ; i<size ; i++)
    {
     sum = sum+arr[i];
    }
    int average=(int)(sum/size);
    printf("the average is %d",average);
    
}