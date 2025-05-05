#include<stdio.h>
int queue[100];
int tail = -1;
void push(int item)
{
    queue[++tail]= item;
}
int pop()
{
    int item;
    if(tail == -1)
    return -1;
    else
    {
        item = queue[0];
        for(int i = 0 ; i < tail ; i++)
        {
            queue[i]= queue[i+1];
        }
    }
    tail--;
    return item;
}
//////////////////////////////////////////INPUT
struct process
{
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
    int inside;
}p[100];
int n;
int Q;
void input()
{
    printf("Enter The Number of Processes : ");
    scanf("%d",&n);
    printf("ENter The Time Quantum : ");
    scanf("%d",&Q);
    for(int i = 0; i<n;i++)
    {
        printf("ENter ArtvalTime ANd Burst Time");
            scanf("%d%d",&p[i].at,&p[i].bt);
            p[i].pid = i;
            p[i].rt = p[i].bt;
            p[i].ct = 0;
            p[i].tat = 0;
            p[i].wt = 0;
            p[i].inside = 0;
        
    }
}
////////////////////////////////////////HELPER
void display() {
    printf("Pid\tA.T\t\tB.T\t\tR.T\t\tC.T\t\t\tTAT\t\t\tWT\t\tInside\n");

   
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\t\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].rt, p[i].ct, p[i].tat, p[i].wt, p[i].inside);
    }
}
void dispQueue()
{
    printf("Queue : ");
    for(int i = 0 ; i <= tail ; i++)
    {
        printf("%d\t",queue[i]);
    }printf("\n");
}
void sortAt()
{
    for(int i = 0 ; i < n-1 ; i++)
    {
        for(int j = 0 ; j < n-i-1;j++)
        {
            if(p[j].at>p[j+1].at)
            {
                struct process temp = p[j];
                p[j]=p[j+1];
                p[j+1] = temp;
            }
        }
    }
}
//////////////////////////////////////////////////
void rr()
{
    int time = -1;
    int completedProcesses = 0;
    while(completedProcesses!=n)
    {
        if(tail != -1)
        {
            int i = pop();
            int execTime = p[i].rt > Q ? Q : p[i].rt;
            time += execTime;
            p[i].rt -= execTime;
           //// this segment must be named j otherwise i value overwirtes
            for(int j = 0 ; j < n ; j++)
            {
                if(p[j].at <= time && p[j].inside == 0)
                {
                    push(j);
                    p[j].inside = 1;
                }
            }
           //// 
            if(p[i].rt == 0)
            {
                p[i].ct = time;
                p[i].tat = p[i].ct - p[i].at;
                p[i].wt = p[i].tat - p[i].bt;
                completedProcesses ++;
            }
            else
            {
                push(i);
            }
        }
        else
        {
            time++;
            for(int i = 0 ; i < n ; i++)
            {
                if(p[i].at <= time && p[i].inside == 0)
                {
                    push(i);
                    p[i].inside = 1;
                }
            }
        }
    }
}
///

void main()
{
    input();
    printf("\n\n");
    display();
    rr();
    display();
}

