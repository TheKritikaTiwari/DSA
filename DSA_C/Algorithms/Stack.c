#include <stdio.h>
#include <stdlib.h>
struct stack{
int data;
struct stack *next;
};
typedef struct stack node;
node*TOP=NULL;
void push(int item)
{
    node*temp=(node*)malloc(sizeof(node));
    temp->data=item;
    temp->next=TOP;
    TOP=temp;
}
int pop()
{
    node*temp;int ele;
    if(TOP==NULL)
    {
        printf("\nUNDERFLOW");
        return;
    }
    printf("\nDeleted item is: %d",TOP->data);
    temp=TOP;
    ele=TOP->data;
    TOP=TOP->next;
    free(temp);
}
void Display()
{
    if(TOP==NULL)
    {
        printf("Stack Is Empty");
        return;
    }
    node*ptr;
    ptr=TOP;
    printf("Stack Is Now:\n");
    while(ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    int choice,k,item;
    do
    {
      printf("\n-: M E N U :-\n1. Push\n2. Pop\n3. Display\n0 for EXIT\n");
      printf("Enter your choice:");
      scanf("%d",&choice);
      if(choice==1)
      {
        printf("\nEnter the item:");
        scanf("%d",&item);
        push(item);
      }
      if(choice==2)
        pop();
      if(choice==3)
        Display();
      if(choice==0)
        break;
    } while(1);
}
