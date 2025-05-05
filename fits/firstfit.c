#include<stdio.h>
#include<stdbool.h>
int blocks[100];int b;
int partition[100];int p;
int used[100];
void input()
{
    printf("Enter The partition Limit : ");
    scanf("%d",&p);
    printf("Enter Partitions : ");
    for(int i = 0 ; i < p ; i++)
    {
        scanf("%d",&partition[i]);
    }
    printf("Enter The Block Limit : ");
    scanf("%d",&b);
    printf("Enter The Blocks : ");
    for(int i = 0 ; i < b ; i++)
    {
        scanf("%d",&blocks[i]);
    }
    for(int i = 0 ; i < 100 ; i++)
    {
        used[i] = -1;
    }
}
void main()
{
    int extF = 0;
    int intF = 0;
    input();
    for(int i = 0 ; i < b ; i++)
    {
        bool flag = false;
        for(int j = 0;j < p ;j++)
        {
            if(used[j]==-1&&partition[j]>=blocks[i])
            {
                flag = true;
                used[j] = 0;
                printf("\nblock %d allocted at partition %d ",i,j);
                intF += partition[j]-blocks[i];
                break;
            }
        }
        if(!flag)
        {
            printf("\nNot ALlocated.");
        }
    }
            for(int i = 0 ;i < p ; i++)
        {
            if(used[i]==-1)
                extF+=partition[i];
        }
        printf("EXT = %d and INT = %d",extF,intF);
}