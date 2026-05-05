#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t chopstick[5];

void* philosopher(void* num) {
    int i = *(int*)num;
    while(1) {
        printf("Philosopher %d is thinking\n", i);
        sem_wait(&chopstick[i]);
        sem_wait(&chopstick[(i+1)%5]);
        printf("Philosopher %d is eating\n", i);
        sleep(1);
        sem_post(&chopstick[i]);
        sem_post(&chopstick[(i+1)%5]);
    }
}
