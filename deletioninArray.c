#include<stdio.h>
int main()
{
    int size;
    printf("enetr the size of array\n");
    scanf("%d",&size);
    int flag=0,pos;
    int arr[size],i,element;
    printf("enter the elements in array\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the element you wanna delete from array\n");
    scanf("%d",&element);
    for(i=0;i<size;i++)
    {
        if(element==arr[i])
        {
            // printf("deletion is not possible\n");
            // flag=1;
            pos=i;
        }
    } 
if(pos>size)
{
    printf("deletion is not possible");
}
        for(i=pos;i<size-1;i++)
        {
            arr[i]=arr[i+1];
        }
    printf("your resultant array after deletion of array\n");
    for(i=0;i<size-1;i++)
    {
        printf("%d is at %d position of array\n",arr[i],i);
    }
    return 0;
}
