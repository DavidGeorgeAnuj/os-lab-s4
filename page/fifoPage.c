#include<stdio.h>
#include<stdbool.h>
int pages[100],p;
int frames[50],f;
int faults=0;
void displayRow()
{
    for(int i = 0 ; i < f ; i++)
    {
        printf("%d\t",frames[i]);
    }
    printf("\n");
}
void main()
{
    printf("Enter The Page Limit");
    scanf("%d",&p);
    printf("Enter The Page Numbers ");
    for(int i = 0;i < p;i++)
    {
        scanf("%d",&pages[i]);
    }
    printf("\nEnter The Frame Number ");
    scanf("%d",&f);
    for(int i = 0; i < f;i++)
    {
        frames[i]=-1;
    }
    int x = 0;
    for(int i = 0 ; i < p ; i++)
    {
        displayRow();
        bool hit = false;
        for(int j = 0 ; j < f ; j++)
        {
            if(pages[i] == frames[j])
            {
                hit = true;
                break;
            }
        }
        if(!hit)
        {
            faults++;
            frames[x] = pages[i];
            x = (x+1)%f;
        }
    }
    printf("Page Faults = %d",faults);
}