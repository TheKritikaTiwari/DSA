#include <stdio.h>
#include <stdlib.h>
int InSearch(int A[],int low,int high,int ele)
{
    int pos,k;
    while(low<=high)
    {
        k=((float)(ele-A[low])/(A[high]-A[low]));
        if(k<0 || k>1)
            return -1;
        pos=(low+k*(high-low));
        if(A[pos]==ele)
            return pos;
        else if(ele<A[pos])
            high=pos-1;
        else
            low=pos+1;
    }
    return -1;
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
    p=InSearch(A,low,high,ele);
    if(p==-1)
        printf("Element Not Found");
    else
        printf("Element found at position %d",p);
}

