#include<stdio.h>
struct process {
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
}p[100];
int n;
void input()
{
    printf("Enter The Number od Processes : ");
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter The Arrival Time And Burst Time : ");
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].rt = p[i].bt;
        p[i].ct = 0;
        p[i].tat = 0;
        p[i].wt = 0;
        p[i].pid = i;
    }
}

void sortAt()
{
    for(int i = 0 ; i < n-1; i++)
    {
        for(int j = 0 ; j < n-i-1 ; j++)
        {
            if(p[j].at > p[j+1].at)
            {
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}
void sjf()
{
    int time = 0;
    int completedProcesses = 0;
    //////////////////////////////////////////////
    //MAKE SURE TO ADD THE NO OF PROCEESS WITH 0 BURSTIME TO THE COMPLETED PROCESS COUNT TO PREVENT INFINITE LOOP
    /////////////////////////////////////////////
    while(completedProcesses != n)
    {
        int index = -1;
        int remTime = 999;

        for(int i = 0 ; i < n ; i++)
        {
            if(p[i].at <= time && p[i].rt > 0 && p[i].rt<remTime)
            {
                index = i;
                remTime = p[i].rt;
            }
        }

        if(index != -1)
        {
            p[index].rt-=1;
            if(p[index].rt == 0)
            {
                p[index].ct = time+1;
                p[index].tat = p[index].ct - p[index].at;
                p[index].wt = p[index].tat - p[index].bt;
                completedProcesses+=1;
            }
        }
        time+=1;
    }
}

void display()
{
    printf("\npid\t\tA.T\t\tB.T\t\tR.T\t\tT.A.T\t\tC.T\t\tW.T\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].rt,p[i].tat,p[i].ct,p[i].wt);
    }
}
void main()
{
    input();
    sortAt();
    sjf();
    display();
}
/*
test case
Enter The Number od Processes : 5
Enter The Arrival Time And Burst Time :  6 	2 
	                                     2 	5
 	                                     8 	1 
 	                                     3 	0 
	                                     4  4 
NOTE MAKE SURE BURST TIME IS NOT 0
*/