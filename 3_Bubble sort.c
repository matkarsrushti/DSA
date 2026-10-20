#include <stdio.h>
int bubblesort(int arr[], int n) 
{
    for (int i=0; i<n; i++)
    {
        for (int j=0;j<n-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }    
    }
}
int main(){
int arr[5]= {8,6,3,4,2};
    int n= 5;
printf("Sorted array: \n");
 bubblesort(arr,n);
   for (int i=0; i < n; i++)
   { printf("%d ", arr[i]);
   } 
    return 0;
}

