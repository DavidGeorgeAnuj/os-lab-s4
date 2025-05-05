
#include<stdio.h>
#include<stdbool.h>

//int alloc[10][10] , max[10][10] , need[10][10] , avail[10];
int P = 5;
int R = 3;

//hardcoded matrix
int alloc[5][3] = {
    {0, 1, 0},  
    {2, 0, 0},  
    {3, 0, 2},  
    {2, 1, 1},  
    {0, 0, 2}  
};
int max[5][3] = {
    {7, 5, 3},  
    {3, 2, 2},  
    {9, 0, 2},  
    {2, 2, 2},  
    {4, 3, 3}  
};
int avail[3] = {3, 3, 2};  
int need[5][3] = {
    {7-0, 5-1, 3-0},  // {7, 4, 3}
    {3-2, 2-0, 2-0},  // {1, 2, 2}
    {9-3, 0-0, 2-2},  // {6, 0, 0}
    {2-2, 2-1, 2-1},  // {0, 1, 1}
    {4-0, 3-0, 3-2}   // {4, 3, 1}
};

bool bankers()
{
    int work[R];
    int finished[P];
    for(int i = 0 ; i < R; i++)
    {
        work[i] = avail[i];
    }
    for(int i = 0 ; i < P ; i++)
    {
        finished[i] = 0;
    }
    int completedProcesses = 0;
    while(completedProcesses != P)
    {
        bool found = false;
        for(int i = 0 ; i < P ; i++)
        {
            if(finished[i] == 0)
            {
                bool canFinish = true;
                for(int j = 0 ; j < R ; j++)
                {
                    if(need[i][j]>work[j])
                    {
                        canFinish = false;
                        break;
                    }
                }
                if(canFinish == true)
                {
                    for(int j = 0 ; j < R ; j++)
                    {work[j]+=alloc[i][j];}
                    found = true;
                    completedProcesses +=1;
                    finished[i] = 1;
                }
            }
        }
        if(!found)
        {
            return false;
        }
    }
    return true;
}
void main()
{
 if(bankers())
 {
     printf("Safe");
 }
 else
 {
     printf("NOT SAfe");
 }
}