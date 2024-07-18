#include <stdio.h>
#include <stdlib.h>
struct ABC
{
    int data;
    struct ABC *lc;
    struct ABC *rc;
};
typedef struct ABC node;
node *root;
node*CreateBST(node*root,int item)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->data=item;
        root->lc=NULL;
        root->rc=NULL;
        return;
    }
    if(item<root->data)
        root->lc=CreateBST(root->lc,item);
    else
        root->rc=CreateBST(root->rc,item);
    return(root);
}
void Traverse()
{
    int ch;
    if(root==NULL)
    {
        printf("\nNOTHING TO DISPLAY\n");
        return;
    }
    do
    {
       printf("\n-: M E N U :-\n1. Inorder Traverse\n2. Preorder Traverse\n3. Postorder Traverse\n0 for EXIT\n");
       printf("\nEnter your choice:");
       scanf("%d",&ch);
       if(ch==0)
        break;
       if(ch==1)
       {
           printf("\nINORDER TRAVERSE\n");
           InOrder(root);
       }
       if(ch==2)
       {
           printf("\nPREORDER TRAVERSE\n");
           PreOrder(root);
       }
       if(ch==3)
       {
          printf("\nPOSTORDER TRAVERSE\n");
          PostOrder(root);
       }
    } while(1);
}
void InOrder(node*root)
{
    if(root!=NULL)
    {
        InOrder(root->lc);
        printf("%d ",root->data);
        InOrder(root->rc);
    }
}
void PreOrder(node*root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        PreOrder(root->lc);
        PreOrder(root->rc);
    }
}
void PostOrder(node*root)
{
    if(root!=NULL)
    {
        PostOrder(root->lc);
        PostOrder(root->rc);
        printf("%d ",root->data);
    }
}
node*Search(node*root,int item)
{
    if(root==NULL)
        return NULL;
    else
    {
        if(root->data==item)
            return(root);
        if(item<root->data)
            return(Search(root->lc,item));
        else
            return(Search(root->rc,item));
    }
}
int NodeCount(node*root)
{
    int ld,rd,tot;
    if(root==NULL)
        return 0;
    else
    {
        ld=NodeCount(root->lc);
        rd=NodeCount(root->rc);
        tot=ld+rd+1;
        return(tot);
    }
}
int Height(node*root)
{
    int ld,rd,td;
    if(root==NULL)
        return 0;
    else
    {
        ld=Height(root->lc);
        rd=Height(root->rc);
        if(ld>rd)
            td=ld+1;
        else
            td=rd+1;
        return(td);
    }
}
/*node*Delete(node*root,int item)
{
    node*p,*q;
    int t;
    if(root==NULL)
    {
        printf("EMPTY");
        return;
    }
    if(item<root->data)
        t=Delete(root->lc,item);
    else if(item>root->data)
        t=Delete(root->rc,item);
    p=root;
    q=NULL;
    if(q->rc==NULL && q->lc==NULL)
        q=NULL;
    else if(q->rc==NULL)
        root=q->lc;
    else if(q->lc==NULL)
        root=q->rc;
    free(p);
    return root;
}*/
void Deletion(node*root,int item)
{
    node*droot=root,*temp,*tempp=NULL;
    int f=0;
    while(droot!=NULL)
    {
        if(droot->data==item)
        {
            temp=droot;
            f=1;
            break;
        }
        tempp=droot;
        if(item<droot->data)
            droot=droot->lc;
        else
            droot=droot->rc;
    }
    if(f==0)
    {
        printf("\nItem Not Found");
        return;
    }
    if(temp->lc==NULL && temp->rc==NULL)
    {
        if(tempp==NULL)
        {
            root=NULL;
            free(temp);
            return;
        }
        if(tempp->lc==temp)
            tempp->lc=NULL;
        else
            tempp->rc=NULL;
        temp=NULL;
        free(temp);
        return;
    }
    if(temp->lc==NULL && temp->rc!=NULL)
    {
        if(tempp==NULL)
        {
            root=droot->rc;
            free(droot);
            return;
        }
        if(temp==tempp->lc)
            tempp->lc=temp->rc;
        else
            tempp->rc=temp->rc;
        temp=NULL;
        free(temp);
        return;
    }
    if(temp->lc!=NULL && temp->rc==NULL)
    {
        if(tempp==NULL)
        {
            root=droot->lc;
            free(droot);
            return;
        }
        if(temp==tempp->lc)
            tempp->lc=temp->lc;
        else
            tempp->rc=temp->lc;
        temp=NULL;
        free(temp);
        return;
    }
    if(temp->lc!=NULL && temp->rc!=NULL)
    {
        temp=droot->rc;
        tempp=droot;
        while(temp->lc!=NULL)
        {
            tempp=temp;
            temp=temp->lc;
        }
        droot->data=temp->data;
        if(tempp->rc==temp)
            tempp->rc=temp->rc;
        else
            tempp->lc=temp->rc;
        temp=NULL;
        free(temp);
        return;
    }
}
int main()
{
    root=NULL;
    int choice,item,n,i,ld,rd,tot,td;
    do
    {
        printf("\n-: M E N U :-\n1. Create\n2. Insertion\n3. Traverse\n4. Search\n5. Height\n6. Total No. of Nodes\n7. Deletion\n0 for EXIT\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\nEnter no. of times you want to insert:");
            scanf("%d",&n);
            for (i=1;i<=n;i++)
            {
                printf("\nEnter the item you want to insert:");
                scanf("%d",&item);
                root=CreateBST(root,item);
            }
        }
        else if(choice==2)
        {
            printf("\nEnter the item you want to insert:");
            scanf("%d",&item);
            root=CreateBST(root,item);
        }
        else if(choice==3)
        {
            Traverse();
        }
        else if(choice==4)
        {
            printf("\nEnter the item that you want to search:");
            scanf("%d",&item);
            node*temp=Search(root,item);
            if(temp==NULL)
                printf("\nItem Not Found");
            else
                printf("\nItem Found");
        }
        else if(choice==5)
        {
            td=Height(root);
            printf("\nHeight of tree is: %d",td);
        }
        else if(choice==6)
        {
            tot=NodeCount(root);
            printf("\nTotal no.of nodes are: %d",tot);
        }
        else if(choice==7)
        {
            printf("\nEnter the item that you want to delete:");
            scanf("%d",&item);
            Deletion(root,item);
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
