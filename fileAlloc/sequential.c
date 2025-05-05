#include<stdio.h>
#include<stdbool.h>
int memory[100];int m;
void main()
{
    printf("Enter The memory limit : ");
    scanf("%d",&m);
    int n,l;
    printf("Enter the total number the starting block ");
    scanf("%d",&n);
    printf("Enter the length of allocation ");
    scanf("%d",&l);
    
    bool canAllocate = true;
    for(int i = n ; i <(n+l);i++)
    {
        if(memory[i]==1)
        {
        printf("Terminating");
        return;
        }
    }
    for(int i = n ; i <(n+l);i++)
    {
        memory[i] =1;
    }
    ///printing
    for(int i = 0 ; i < m;i++)
        printf("%d->",memory[i]);
    printf("\n\nsuccessfull...");
}