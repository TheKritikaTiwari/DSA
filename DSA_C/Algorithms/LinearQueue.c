#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int LQ[MAX];
int rear=-1;
int front=-1;
void Enque(int item)
{
   if (rear==MAX-1)
   {
     printf("\nQueue is Overflowing");
   }
   else
   {
     if (rear==-1)
     {
       front=rear=0;
     }
     else
     {
       rear=rear+1;
     }
     LQ[rear]=item;
   }
}

int Deque()
{
   if (front==-1)
   {
     printf("\nQueue is Underflowing");
   }
   else
   {
     printf("Item Deleted from Queue is %d\n",LQ[front]);
     if (front==rear)
     {
       front=rear=-1;
     }
     else
     {
       front=front+1;
     }
   }
}

void Display(int item)
{
  int i;
  printf("The Queue is:\n");
  for(i=front;i<=rear;i++)
  {
    printf("%d ",LQ[i]);
  }
}

int main()
{
    int choice,item;
    do
    {
      printf("\nPress\n1 for Enque\n2 for Deque\n3 for Display\n4for EXIT\n");
      printf("Enter your choice:");
      scanf("%d",&choice);
      if (choice==1)
      {
        printf("Enter the element you want to Enque:");
        scanf("%d",&item);
        Enque(item);
      }
      else if (choice==2)
      {
        Deque();
      }
      else if (choice==3)
      {
        Display(item);
      }
      else if (choice==4)
      {
        printf("\nEXIT");
        break;
      }
      else
      {
        printf("INVALID CHOICE");
      }
    } while(1);
}
