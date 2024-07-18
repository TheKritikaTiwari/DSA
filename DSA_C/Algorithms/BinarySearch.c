#include <stdio.h>
#include <stdlib.h>
/*int BSearch(int A[],int low,int high,int ele)
{
    int mid;
    if(low>high)
        return -1;
    mid=(low+high)/2;
    if(A[mid]==ele)
        return mid;
    else if(ele<A[mid])
        return (BSearch(A,low,mid-1,ele));
    else
        return (BSearch(A,mid+1,high,ele));
}*/
int BSearch(int A[],int low,int high,int ele)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(A[mid]==ele)
            return mid;
        else if(ele<A[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return (-1);
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
    p=BSearch(A,low,high,ele);
    if(p==-1)
        printf("Element Not Found");
    else
        printf("Element found at position %d",p);
}

