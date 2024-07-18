#include <stdio.h>
#include <stdlib.h>
struct ABC
{
    int data;
    struct ABC *next;
};
typedef struct ABC node;
node *head, * tail;
void Create()
{
    int item,i,n;
    printf("Enter no. of times you want to insert:");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        printf("Enter the item you want to insert:");
        scanf("%d",&item);
        Insert(item);
    }
}
void Insert(int item)
{
    node *temp=(node*)malloc(sizeof(node));
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        temp->data=item;
        temp->next=NULL;
    }
    else
    {
      tail->next=temp;
      temp->data=item;
      temp->next=NULL;
      tail=temp;
    }
    return;
}
void Insertion()
{
    int item,ch,ele;
    do
    {
        printf("\nPress\n1 for Insert After a specific Node\n2 for Insert Before a specific Node\n0 for EXIT\n");
        printf("Enter your choice:");
        scanf("\%d",&ch);
        if(ch==0)
        {
            break;
        }
        if (ch==1)
        {
            printf("Enter the item after which you want to insert the element:");
            scanf("%d",&item);
            printf("Enter the element you want to insert:");
            scanf("%d",&ele);
            InsertAfter(item,ele);
        }
        else if(ch==2)
        {
            printf("Enter the item before which you want to insert the element:");
            scanf("%d",&item);
            printf("Enter the element you want to insert:");
            scanf("%d",&ele);
            InsertBefore(item,ele);
        }

    } while(1);
}
void InsertAfter(int item,int ele)
{
    node *dh, *temp;
    int flag=0;
    dh=head;
    while(dh!=NULL)
    {
        if (dh->data==item)
        {
            flag=1;
            break;
        }
       dh=dh->next;
    }
    if (flag==0)
    {
        printf("\nITEM NOT FOUND");
        return;
    }
    temp=(node*)malloc(sizeof(node));
    temp->data=ele;
    temp->next=dh->next;
    dh->next=temp;
    if (tail->next!=NULL)
        tail=temp;
}
void InsertBefore(int item,int ele)
{
    node *dh, *temp;
    int flag=0;
    dh=head;
    if(head->data==item)
    {
        temp=(node*)malloc(sizeof(node));
        temp->data=ele;
        temp->next=head;
        head=temp;
    }
    else
    {
       while(dh->next!=NULL)
       {
           if (dh->next->data==item)
           {
               flag=1;
               break;
           }
           dh=dh->next;
       }
       if (flag==0)
       {
            printf("\nITEM NOT FOUND");
            return;
       }
        temp=(node*)malloc(sizeof(node));
        temp->data=ele;
        temp->next=dh->next;
        dh->next=temp;
    }
}
void Search(int item)
{
    node *dh;
    int flag=0;
    dh=head;
    while(dh!=NULL)
    {
        if (dh->data==item)
        {
            flag=1;
            break;
        }
       dh=dh->next;
    }
    if (flag==1)
    {
        printf("\nITEM FOUND");
        return;
    }
    else
    {
       printf("\nITEM NOT FOUND");
        return;
    }
}
void Traverse()
{
    node *dh;
    dh=head;
    while(dh!=NULL)
    {
        printf("%d ",dh->data);
        dh=dh->next;
    }
}
void Deletion(int item)
{
    node *dh, *temp;
    int flag=0;
    dh=head;
    if(head->data==item)
    {
        temp=head;
        head=head->next;
        if (head==NULL)
        {
            tail=NULL;
        }
        free(temp);
        return;
    }
    while(dh->next!=NULL)
    {
        if (dh->next->data==item)
        {
            flag=1;
            break;
        }
        dh=dh->next;
    }
    if (flag==0)
    {
        printf("\nITEM NOT FOUND");
        return;
    }
    temp=dh->next;
    dh->next=temp->next;
    if (temp==tail)
        tail=dh;
    free(temp);
    return;
}
void Reverse()
{
    node *dh,*prev=NULL,*next;
    dh=head;
    while(dh!=NULL)
    {
        next=dh->next;
        dh->next=prev;
        prev=dh;
        dh=next;
    } head=prev;
}
int main()
{
    int choice,item;
    do
    {
        printf("\nPress\n1 for Create\n2 for Insertion\n3 for Search\n4 for Traverse\n5 for Reverse\n6 for Deletion\n0 for EXIT\n");
        printf("Enter your choice:");
        scanf("\%d",&choice);
        if(choice==1)
        {
            Create();
        }
        else if(choice==2)
        {
            Insertion();
        }
        else if(choice==3)
        {
            printf("Enter the item after which you want to search:");
            scanf("%d",&item);
            Search(item);
        }
        else if(choice==4)
        {
            Traverse();
        }
        else if(choice==5)
        {
            Reverse();
        }
        else if(choice==6)
        {
            printf("Enter the item you want to delete:");
            scanf("%d",&item);
            Deletion(item);
        }
        else if(choice==0)
        {
            printf("\nEXIT");
            break;
        }
        else
        {
            printf("\nINVALID CHOICE");
        }
    } while(1);
}
