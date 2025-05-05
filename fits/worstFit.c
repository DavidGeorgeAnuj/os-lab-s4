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
        int index = -1;
        int max = -1;
        for(int j = 0;j < p ;j++)
        {
            if(used[j]==-1&&partition[j]>=blocks[i]&&partition[j]>max)
            {
                index = j;
                max = partition[j];
                flag = true;
            }
        }
        if(flag)
        {
            used[index] = 0;
            intF+=partition[index]-blocks[i];
        }else
        {
            printf("\nNot Allocted\n");
        }
    }
            for(int i = 0 ;i < p ; i++)
        {
            if(used[i]==-1)
                extF+=partition[i];
        }
        printf("EXT = %d and INT = %d",extF,intF);
}