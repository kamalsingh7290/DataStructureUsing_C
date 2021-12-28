#include<stdio.h>  
void main ()  
{  
    int i,j,temp,n;  
    printf("Enter the size of array\n");
    scanf("%d",&n);   
    int arr[n];
    printf("Enter the elements for array\n");
    for (i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("printing sorted elements...\n");  
    for(i=1; i<n; i++)   
    {  
        temp = arr[i];  
        j= i-1;  
        while(j>=0 && temp <= arr[j])  
        {  
            arr[j+1] = arr[j]; 
            j = j-1;  
        }  
        arr[j+1] = temp;  
    }  
        printf("\n");

    for(i=0;i<n;i++)  
    {  
        printf("%d\n",arr[i]);  
    }  
}  


                                                            // Second method
// #include<stdio.h>
// int main()
// {
//     int arr[]={23,12,45,2},i,j,temp;
//     for(i=0;i<4;i++)
//     {
//         temp=arr[i];
//         j=i-1;
//         while(j>=0&&temp<=arr[j])
//         {
//             arr[j+1]=arr[j];
//             j=j-1;
//         }
//         arr[j+1]=temp;
//     }
//         for(i=0;i<4;i++)
//         {
//             printf("%d\t",arr[i]);
//         }
    
//     return 0;
// }