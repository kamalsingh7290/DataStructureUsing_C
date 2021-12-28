#include<stdio.h>
int main()//reversal of an array 
{
    int arr[10]={1,2,3,4,5,6,7,8,9};
    for(int i=8;i>=0;i--)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}