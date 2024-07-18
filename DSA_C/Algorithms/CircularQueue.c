#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int CQ[MAX];
int rear=-1;
int front=-1;
void Enque(int item)
{
  if ((rear + 1)%MAX == front)
  {
    printf("\nQueue is Overflowing");
  }
  else
  {
    if (rear==-1)
    {
      rear=front=0;
      CQ[rear]=item;
    }
    else
    {
      rear = (rear + 1)%MAX;
      CQ[rear]=item;
    }
  }
}

int Deque()
{
  if ((front==-1) && (rear==-1))
  {
    printf("\nQueue is Underflowing");
  }
  else if(front==rear)
  {
    printf("\nItem Deleted from Queue is %d\n",CQ[front]);
    rear=front=-1;
  }
  else
    {
      printf("\nItem Deleted from Queue is %d\n",CQ[front]);
      front=(front + 1)%MAX;
    }

}

void Display(int item)
{
  int f=front , r=rear;
  if ((front==-1) && (rear==-1))
  {
    printf("\nThe Queue is Empty\n");
  }
  else
  {
    printf("\nThe Queue is:\n");
    if(f<=r)
    {
      while(f<=r)
      {
        printf("%d ",CQ[f]);
        f++;
      }
    }
    else
    {
      while(f<=MAX-1)
      {
        printf("%d ",CQ[f]);
        f++;
      }
      f=0;
      while(f<=r)
      {
        printf("%d ",CQ[f]);
        f++;
      }
    }
  }
}
int main()
{
    int choice,item;
    do
    {
      printf("\nPress\n1 for Enque\n2 for Deque\n3 for Display\n4 for EXIT\n");
      printf("Enter your choice:");
      scanf("%d",&choice);
      if (choice==1)
      {
        printf("\nEnter the element you want to Enque:");
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
        printf("\nINVALID CHOICE");
      }
    } while(1);
}
