 #include <stdio.h>
#include <stdlib.h>
void HeapSort(int A[],int n)
{
    int i,j,temp;
    for(i=n/2-1;i>=0;i--)
        Heapify(A,n,i);
    for(i=n-1;i>0;i--)
    {
        temp=A[i];
        A[i]=A[0];
        A[0]=temp;
        Heapify(A,i,0);
    }
}
void Heapify(int A[],int n,int i)
{
    int largest=i,lc,rc;
    lc=i*2+1; rc=i*2+2;
    if(lc<n && A[lc]>A[largest])
        largest=lc;
    if(rc<n && A[rc]>A[largest])
        largest=rc;
    if(i!=largest)
    {
       int temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        Heapify(A,n,largest);
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
    HeapSort(A,n);
    printf("the Sorted Array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}

