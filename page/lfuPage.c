#include<stdio.h>
#include<stdbool.h>

int pages[100];int p;
int frames[50];int f;
int recent[50];int faults = 0;

void readRows()
{
    for(int j = 0 ; j < f ; j++)
    {
        printf("%d\t",frames[j]);
    }printf("\n");
}

void initialize()
{
    printf("Enter The Number Of Pages : ");
    scanf("%d",&p);
    printf("Enter The Number Of Frames : ");
    scanf("%d",&f);
    
    printf("Enter The Page Numbers : ");
    for(int i = 0 ; i < p ; i++)
    {
        scanf("%d",&pages[i]);
    }
    for(int i = 0 ; i < f ; i++)
    {
        frames[i] = -1;
        recent[i] = -1;
    }
    
}
void main()
{
    initialize();
    for(int i = 0 ; i < p ; i++)
    {
        readRows();
        bool notHit = true;
        for(int j = 0 ; j < f; j++)
        {
            if(pages[i] == frames[j])
            {
                notHit = false;
                recent[j] = i;
            }
        }
        if(notHit == true)
        {
            faults++;
            bool found = false;
            for(int j = 0 ; j < f ; j++)
            {
                if(frames[j] == -1)
                {
                    frames[j] = pages[i];
                    recent[j] = i;
                    found = true;
                    break;
                }
            }
            if(found == false)
            {
                int index = 0;
                for(int j = 1; j < f ; j++)
                {
                    if(recent[j]<recent[index])
                    index = j;
                }
                frames[index] = pages[i];
                recent[index] = i;
            }
        }
    }
    readRows();
    printf("Page Faults = %d",faults);
}
    