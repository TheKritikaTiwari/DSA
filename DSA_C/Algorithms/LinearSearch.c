#include <stdio.h>
#include <stdlib.h>
int LSearch(int A[],int low,int high,int ele)
{
    if(low>high)
        return -1;
    if(A[low]==ele)
        return low;
    return (LSearch(A,low+1,high,ele));
}
int main()
{
    int n,A[20],low,high,i,p,ele;
    printf("Enter total no. of elements for the array:");
    scanf("%d",&n);
    high=n-1;
    for(i=0;i<n;i++)
    {
        printf("Element [%d]: ",i);
        scanf("%d",&A[i]);
    }
    printf("Enter the elements that you want to search: ");
    scanf("%d",&ele);
    p=LSearch(A,low,high,ele);
    if(p==-1)
        printf("Element Not Found");
    else
        printf("Element found at position %d",p);
}
