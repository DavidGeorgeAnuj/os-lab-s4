#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

int buffer[5];
int in = 0;
int out = 0;

//$ gcc -o sem sem.c -pthread
//./sem

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void* producer(void* args)
{
    for(int i = 0 ; i < 10 ; i++)
    {
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);

    buffer[in] = i;
    printf("produced %d\n",buffer[in]);
    in = (in + 1)%5;
    
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    }
}

void* consumer(void* args)
{
    for(int i = 0 ; i < 10 ; i++)
    {
    sem_wait(&full);
    pthread_mutex_lock(&mutex);

    printf("\t\tconsumed %d\n",buffer[out]);
    out = (out + 1)%5;
    
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    sleep(1);
    }
}

void main()
{
    pthread_t prods;
    pthread_t cons;

    sem_init(&empty,0,5);
    sem_init(&full,0,0);
    pthread_mutex_init(&mutex,NULL);

    pthread_create(&prods,NULL,producer,NULL);
    pthread_create(&cons,NULL,consumer,NULL);

    pthread_join(prods,NULL);
    pthread_join(cons,NULL);
    
}