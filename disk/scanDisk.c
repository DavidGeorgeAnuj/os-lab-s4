#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int d;
int requests[100];int n;
int head;
int left[100];int right[100];int l=0;int r=0;
void main()
{
    printf("Enter The Size Of The Disk : ");
    scanf("%d",&d);
    
    printf("Enter The Requests Size : ");
    scanf("%d",&n);
    
    printf("Enter the requests values : ");
    for(int i = 0;i < n;i++)
    {scanf("%d",&requests[i]);}
    
    printf("Enter The Current The Head : ");
    scanf("%d",&head);
    
    for(int i = 0 ; i < n ; i++)
    {
        if(requests[i]<head)
            left[l++]=requests[i];
        else
            right[r++]=requests[i];
    }
    /////////////////////////////
    for(int i = 0 ; i < r-1 ; i++)
    {
        for(int j = 0 ; j < r-i-1 ;j++)
        {
            if(right[j]>right[j+1])
            {
                int temp = right[j];
                right[j] = right[j+1];
                right[j+1] = temp;
            }
        }
    }
    for(int i = 0 ; i < l-1 ; i++)
    {
        for(int j = 0 ; j < l-i-1 ;j++)
        {
            if(left[j]>left[j+1])
            {
                int temp = left[j];
                left[j] = left[j+1];
                left[j+1] = temp;
            }
        }
    }
    ///////////////////////////
    int distance = 0;
    int currHead = head;
    for(int i = 0;i < r;i++)
    {
        printf("%d->",currHead);
        distance+=abs(currHead-right[i]);
        currHead = right[i];
    }
    distance += abs(currHead-(d-1));
    currHead = d-1;
    for(int i = l-1 ; i >=0;i--)
    {
        printf("%d->",currHead);
        distance+=abs(currHead - left[i]);
        currHead = left[i];
    }
    printf("The Total Distance is = %d",distance);
}
/*
Enter The Size Of The Disk : 200
Enter The Requests Size : 7
Enter the requests values : 82 170 43 140 24 16 190
Enter The Current The Head : 50
ANS = 332
*/