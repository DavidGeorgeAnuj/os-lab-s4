#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int requests[100];
int r;
int head;
int time = 0;
void main()
{
    printf("Enter The Total Number of Requests : ");
    scanf("%d",&r);

    printf("Enter The requests : ");
    for(int i =0 ; i < r ; i++)
    {
        scanf("%d",&requests[i]);
    }

    printf("Enter The Initial Head Position : ");
    scanf("%d",&head);

    for(int i = 0 ; i < r ;i++)
    {
        printf("%d -> ", requests[i]);
        time += abs(head-requests[i]);
        head = requests[i];
    }

    printf("The total no of head movements is %d ",time);

    
}