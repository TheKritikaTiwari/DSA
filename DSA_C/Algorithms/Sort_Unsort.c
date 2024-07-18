#include <stdio.h>
#include <stdlib.h>
void input(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Element [%d]: ",i);
        scanf("%d",&a[i]);
    }
}
void Display(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void UnSort(int a[], int n)
{
    int i,index1,index2,temp;
    for(i=1;i<=n/2;i++)
    {
        index1=(rand()%((n-1)-0+1))+0;
        index2=(rand()%((n-1)-0+1))+0;
        temp=a[index1];
        a[index1]=a[index2];
        a[index2]=temp;
    }
}
void BubbleSort(int a[],int n)
{
    int temp,i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void SelectionSort(int a[],int n)
{
    int temp,i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void InsertionSort(int a[],int n)
{
    int temp,i,j;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>temp)
                a[j+1]=a[j];
            else
                break;
        }
        a[j+1]=temp;
    }
}
int main()
{
    int a[50],n,i,choice;
    printf("Enter total no. of elements for thr array:");
    scanf("%d",&n);
    input(a,n);
    do
    {
        printf("\n:- M E N U :-\n1. Bubble Sort\n2. Selection Sort\n3. Insertion sort\n4. Unsort\n0 EXIT\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        if(choice==1)
            {
                BubbleSort(a,n);
                printf("The Sorted Array Is:\n");
                Display(a,n);
            }
        else if(choice==2)
            {
                SelectionSort(a,n);
                printf("The Sorted Array Is:\n");
                Display(a,n);
            }
        else if(choice==3)
            {
                InsertionSort(a,n);
                printf("The Sorted Array Is:\n");
                Display(a,n);
            }
        else if(choice==4)
            {
                UnSort(a,n);
                printf("The Unsorted Array Is:\n");
                Display(a,n);
            }
        else if(choice==0)
            break;
    } while(1);
}
