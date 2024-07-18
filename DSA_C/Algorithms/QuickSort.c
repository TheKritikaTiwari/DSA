#include <stdio.h>
#include <stdlib.h>
int QuickSort(int A[], int low, int high)
{
    int pivot,i,j,temp;
    if(low<high)
    {
        pivot=low;
        i=low;
        j=high;
        while(i<j)
        {
            while(A[i]<=A[pivot] && i<low)
                i++;
            while(A[j]>A[pivot])
                j--;
            if(i<j)
            {
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
        temp=A[pivot];
        A[pivot]=A[j];
        A[j]=temp;
        QuickSort(A,low,j-1);
        QuickSort(A,j+1,high);
    }
}
int main()
{
    int A[20],n,i,low=0,high;
    printf("Enter total no. of elements for the array:");
    scanf("%d",&n);
    high=n-1;
    for(i=0;i<n;i++)
    {
        printf("Elements [%d]: ",i);
        scanf("%d",&A[i]);
    }
    QuickSort(A,low,high);
    printf("the Sorted Array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}
