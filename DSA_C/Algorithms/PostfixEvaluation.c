#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int STACK[MAX];
int TOP=-1;
void push(int n)
{
  STACK[++TOP]=n;
}

int pop()
{
  return STACK[TOP--];
}

int main()
{
    char ch;
    char s[50];
    printf("Enter the postfix expression:\n");
    gets(s);
    puts(s);
    int a,b,c,i;
    for(i=0;s[i]!='\0';i++)
    {
      ch=s[i];
      if (isdigit(ch))
      {
        push(ch-'0');
      }
      else
      {
        b=pop();
        a=pop();
        switch (ch)
        {
          case '+': c=a+b;
                    break;
          case '-': c=a-b;
                    break;
          case '*': c=a*b;
                    break;
          case '/': c=a/b;
                    break;
        } push(c);
      }
    }
    printf("\nThe result is: %d",pop());
}
