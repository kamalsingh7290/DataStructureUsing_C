#include<stdio.h>
#define MAX 10

int input(int arr[])
{
    int size=0;
    printf("enter the size of array \n");
    scanf("%d",&size);
    printf("enter the elements in array\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    return size;
}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition (int arr[], int low, int high)
{
	int pivot = arr[low]; 
	int start=low;
	int end =high;
	while(start<end)
	{
		while (arr[start]<=pivot)		
		{
			start++;
		}
		while(arr[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			swap(&arr[start],&arr[end]);
		}
	}
	swap(&arr[low], &arr[end ]);
	return (end);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		
		int pi = partition(arr, low, high);
		
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void printArray(int arr[],int size)
{
    printf("the Array is : ");
    for (int i = 0; i<size; i++)
    {
        printf(" %d  ",arr[i]);
    }
}
int main()
{
	int arr[MAX],size;
    size=input(arr);
	quickSort(arr,0,size-1);
    printArray(arr,size);
	return 0;
}