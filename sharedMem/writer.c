#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

void main()
{
    key_t key = 1234;
    //creates
    int id = shmget(key,1024,0666|IPC_CREAT);
    //attches
    int* ptr = (int*) shmat(id,NULL,0);
    //writes
    *ptr = 44;
    //detaches
    shmdt(ptr);
}