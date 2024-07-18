#include <stdio.h>
#include <stdlib.h>
void TOH(int n, char source, char aux, char desti)
{
    if(n>0)
    {
        TOH(n-1, source, desti, aux);
        printf("\nDisk%2d Moves from %c to %c", n,source,desti);
        TOH(n-1,aux,source,desti);
    }
}
int main()
{
    int n;
    printf("Enter no. of disks: ");
    scanf("%d",&n);
    TOH(n, 'A','B','C');
}
