#include<stdio.h>
void Swaping(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void sorting(int Array[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)     
 
       for (j = 0; j < n-i-1; j++)
           if (Array[j] > Array[j+1])
              Swaping(&Array[j], &Array[j+1]);
}
void printing(int Array[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", Array[i]);
    printf("\n");
}
int main()
{
    int size;
    printf("Enter the size of array\n");
    scanf("%d",&size);
    int Array[size];
    printf("Enter %d values for the array\n",size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&Array[i]);
    }
    int n = sizeof(Array)/sizeof(Array[0]);
    sorting(Array, n);
    printf("Sorted array: \n");
    printing(Array, n);
    return 0;
}