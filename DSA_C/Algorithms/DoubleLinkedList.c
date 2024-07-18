#include <stdio.h>
#include <stdlib.h>
struct ABC
{
    int data;
    struct ABC *next;
    struct ABC *prev;
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
    temp->data=item;
    if(head==NULL)
    {
        head=tail=temp;
        head->next=NULL;
        head->prev=NULL;
    }
    else
    {
      temp->next=NULL;
      temp->prev=tail;
      tail->next=temp;
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
        scanf("%d",&ch);
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
        if(ch==2)
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
    do
    {
        if(dh->data==item)
        {
            flag=1;
            break;
        }
        dh=dh->next;
    } while(dh!=NULL);
    if(flag==0)
    {
        printf("\nItem Not Found");
        return;
    }
    temp=(node*)malloc(sizeof(node));
    temp->data=ele;
    temp->next=dh->next;
    temp->prev=dh;
    dh->next=temp;
    if(temp->next==NULL)
        tail=temp;
    else
        temp->next->prev=temp;
}
void InsertBefore(int item,int ele)
{
    node *dh, *temp;
    int flag=0;
    dh=head;
    do
    {
        if(dh->data==item)
        {
            flag=1;
            break;
        }
        dh=dh->next;
    } while(dh!=NULL);
    if(flag==0)
    {
        printf("\nItem Not Found");
        return;
    }
    temp=(node*)malloc(sizeof(node));
    temp->data=ele;
    temp->next=dh;
    temp->prev=dh->prev;
    if(dh->prev!=NULL)
        dh->prev->next=temp;
    dh->prev=temp;
    if(temp->prev==NULL)
    {
        head=temp;
    }
}
void Search(int item)
{
    node *dh, *temp;
    int flag=0;
    dh=head;
    do
    {
        if(dh->data==item)
        {
            flag=1;
            break;
        }
        dh=dh->next;
    } while(dh!=NULL);
    if(flag==1)
    {
        printf("\nItem Found");
        return;
    }
    else
    {
        printf("\nItem Not Found");
        return;
    }
}
void Traverse()
{
    node *dh;
    dh=head;
    if(head==NULL)
    {
        printf("\nNothing to display");
        return;
    }
    printf("\nForward Traversing:\n");
    while(dh!=NULL)
    {
        printf("%d ",dh->data);
        dh=dh->next;
    }
    printf("\nBackward Traversing:\n");
    node *dt;
    dt=tail;
    while(dt!=NULL)
    {
        printf("%d ",dt->data);
        dt=dt->prev;
    }
}
void Reverse()
{
    node *dh,*p=NULL,*next,*dt,*q=NULL,*n;
    dh=head;
    while(dh!=NULL)
    {
        next=dh->next;
        dh->next=p;
        p=dh;
        dh=next;
    } head=p;
    dt=tail;
    while(dt!=NULL)
    {
        n=dt->prev;
        dt->prev=q;
        q=dt;
        dt=n;
    } tail=q;
}
void Delete(int item)
{
    node *dh, *temp;
    int flag=0;
    dh=head;
    do
    {
        if(dh->data==item)
        {
            flag=1;
            break;
        }
        dh=dh->next;
    } while(dh!=NULL);
    if(flag==0)
    {
        printf("\nItem Not Found");
        return;
    }
    temp=dh;
    if (temp->prev==NULL && temp->next==NULL)
    {
        head=NULL;
        tail=NULL;
        free(temp);
        return;
    }
    if(temp->prev==NULL)
    {
        dh=temp->next;
        dh->prev=NULL;
        head=dh;
        free(temp);
        return;
    }
    if(temp->next==NULL)
    {
        dh=temp->prev;
        dh->next=NULL;
        tail=dh;
        free(temp);
        return;
    }
    dh->prev->next=temp->next;
    dh->next->prev=temp->prev;
    free(temp);
}
int main()
{
    int choice,item;
    do
    {
        printf("\nPress\n1 for Create\n2 for Insertion\n3 for Search\n4 for Traverse\n5 for Reverse\n6 for Deletion\n0 for EXIT\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
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
            printf("Enter the item that you want to search:");
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
            Delete(item);
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
