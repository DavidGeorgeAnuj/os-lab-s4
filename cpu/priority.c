#include<stdio.h>
struct process{
    int pid,at,bt,rt,tat,ct,wt,priority;
}p[100];
int n;
void input()
{
    printf("Enter The Number of Processes : ");
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        printf("ENter The Arrival Time , Burst Time and Priority : ");
        scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].priority);
        p[i].pid = i;
        p[i].rt = p[i].bt;
        p[i].tat = 0;p[i].ct = 0;p[i].wt = 0;
    }
}
void priority()
{
    int time = 0;
    int completedProcesses = 0;
    while(completedProcesses != n)
    {
        int index = -1;
        int priority = 999;
        for(int i = 0 ; i < n ; i++)
        {
            if(p[i].at <= time && p[i].rt > 0 && p[i].priority < priority )
            {
                index = i;
                priority = p[i].priority;
            }
        }
        if(index != -1)
        {
            p[index].rt -= 1;
            if(p[index].rt == 0)
            {
                p[index].ct = time+1;
                p[index].tat = p[index].ct - p[index].at;
                p[index].wt = p[index].tat - p[index].bt;
                completedProcesses +=1;
            }
        }
        time++;
    }  
}
void display()
{
    printf("\npid\t\tA.T\t\tB.T\t\tR.T\t\tT.A.T\t\tC.T\t\tW.T\t\tProprity\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\t\t\t%d\t\n",p[i].pid,p[i].at,p[i].bt,p[i].rt,p[i].tat,p[i].ct,p[i].wt,p[i].priority);
    }
}
void sortAt()
{
    for(int i = 0 ; i < n - 1; i++)
    {
        for(int j = i ; j < n-i-1;j++)
        {
            if(p[j].at>p[j+1].at)
            {
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}
void main()
{
    input();
    sortAt();
    priority();
    display();
}
//testcase
/*
Enter The Number of Processes : 5
 0 3 3
 1 6 4
 3 1 9
 2 2 7
 4 4 8
