#include<stdio.h>
#include<stdbool.h>
int memory[100];int m;
int block[50];int b;


void linked()
{
  printf("Enter The Limit of Memory :");
  scanf("%d",&m);
  printf("Enter The Toatal Number of blocks to allocate : ");
  scanf("%d",&b);
  for(int i = 0 ; i < m ;i++)
  {
      memory[i] = 0;
  }
  for(int i = 0 ; i < b ; i++)
  {
      scanf("%d",&block[i]);
      if(memory[ block[i] ] == 1)
      {
          printf("ALready Allocated . aborting.....");
          return;
      }
  }
  for(int i = 0 ; i < b ; i++)
  {
      memory[block[i]] = 1;
  }
  
  for(int i = 0 ; i < m ;i++)
  {
      printf("%d->",memory[i]);
  }
  printf("\n");
  for(int i = 0 ; i < b ; i++)
  {
      printf("%d->",block[i]);
  }
}

void main()
{
    linked();
}