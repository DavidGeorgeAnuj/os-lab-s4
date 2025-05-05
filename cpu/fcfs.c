#include<stdio.h>
struct process {
    int pid,at,bt,ct,tat,wt;
}p[100];
int n;
void input()
{
    printf("Enter The Number of Processes : ");
    scanf("%d",&n);
    for(int i = 0; i < n ; i++)
    {
        printf("Enter The Arrival Tiem and Burst Time :");
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].pid = i;
        p[i].ct = 0;
        p[i].tat = 0;
        p[i].wt = 0;
    }
}
void sortAt()
{
    for(int i = 0 ; i < n - 1; i++)
    {
        for(int j = 0 ; j < n-i-1 ; j++)
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
void fcfs()
{
    p[0].ct = p[0].at + p[0].bt;
    p[0].tat = p[0].ct - p[0].at;
    p[0].wt = p[0].tat - p[0].bt;
    for(int i = 1 ; i < n ; i++)
    {
         if(p[i].at > p[i-1].ct)
            p[i].ct = p[i].at + p[i].bt;
        else
            p[i].ct = p[i-1].ct + p[i].bt;
            
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}
void display()
{
    printf("PID\tA.T\tB.T\tC.T\tTAT\tWT\n");
    for(int i = 0 ; i < n ; i++)
    {
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
}
void main()
{
    input();
    sortAt();
    fcfs();
    display();
}
/*
Enter The Number od Processes : 

*/