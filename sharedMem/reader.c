#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
gcc writer.c -o writer
gcc reader.c -o reader

./writer  # Runs the writer program
./reader  # Runs the reader program

void main()
{
    key_t key = 1234;
    
    int id = shmget(key,1024,0666|IPC_CREAT);
    
    int *ptr =(int*) shmat(id,NULL,0);
    
    printf("%d",*ptr);
    
    shmdt(ptr);
}

