#include <stdio.h>
#include <stdlib.h>
void MergeSort(int A[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,mid+1,high);
    }
}
void Merge(int A[],int low1,int up1,int low2,int up2)
{
    int i,j,p,k,D[20];
    i=low1; j=low2; p=0;k=0;
    while(i<=up1 && j<=up2)
    {
        if(A[i]<A[j])
            D[p++]=A[i++];
        else
            D[p++]=A[j++];
    }
    while(i<=up1)
        D[p++]=A[i++];
    while(j<=up2)
        D[p++]=A[j++];
    for(i=low1;i<=up2;i++)
        A[i]=D[k++];
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
    MergeSort(A,low,high);
    printf("the Sorted Array is:\n");
    for(i=low;i<=high;i++)
    {
        printf("%d ",A[i]);
    }
}
