#include<stdio.h>
void insert(int arr[],int size)
{
    int pos,i,element;
    printf("enter the element you wanna insert into array\n");
    scanf("%d",&element);
    printf("enter the position where you wanna insert this element\n");
    scanf("%d",&pos);
    for(i=size-1;i>=pos-1;i--)//error   
    {
        arr[i+1]=arr[i];
    }
    arr[pos-1]=element;
    printf("This is your array after insertion of element\n");
    for(i=0;i<size+1;i++)
    {
        printf("%d\n",arr[i]);
    }
}
int main()
{
     int size;
    printf("enetr the size of array\n");
    scanf("%d",&size);
    int arr[size],i;
    printf("enter the elements in array\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    insert(arr,size);
    return 0;
}