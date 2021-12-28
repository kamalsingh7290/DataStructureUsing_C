#include <stdio.h> 
int main()
{
    int a[1000],i,n,min,max;
   
    printf("Enter size of the array : ");
    scanf("%d",&n);
 
    printf("Enter elements in array : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
 
    min=max=a[0];
    for(i=1; i<n; i++)
    {
         if(min>a[i])
		  min=a[i];   
		   if(max<a[i])
		    max=a[i];       
    }
     printf("minimum of array is : %d",min);
          printf("\nmaximum of array is : %d",max);
 
 
    return 0;
}




                                                    //Another Method
// #include<stdio.h>
// int main()
// {
//     int n;
//     printf("enter the size of an array\n");
//     scanf("%d",&n);
//     int arr[n];
//     printf("enter the values inside array\n");
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     int max,min;
//     max=min=0;
//     if(n==1)
//     {
//         max=min=arr[0];
        
//         printf("%d is greater\n ",max);
//         printf("%d is minimum\n ",min);
//     }
//     if(n>1)
//     {
//         if(arr[0]>arr[1])
//         {
//             max=arr[0];
//             min=arr[1];
//         }
//          else
//         {
//             min=arr[0];
//             max=arr[1];
//         }
//         for(int i=0;i<9;i++)
//         {
//             if(arr[i]>max)
//             {
//             max=arr[i];
//             }    
//             else if(arr[i]<min) 
//             {
//                 min=arr[i];
//             }
//         }
//         printf("%d is greater\n ",max);
//         printf("%d is minimum\n ",min);
//     }
//     return 0;
// }
