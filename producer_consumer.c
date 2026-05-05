#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t empty, full;
pthread_mutex_t mutex;
int buffer[5], in=0, out=0;

void* producer(void* arg) {
    for(int i=0; i<5; i++) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = i; printf("Produced: %d\n", buffer[in]);
        in = (in+1)%5;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void* consumer(void* arg) {
    for(int i=0; i<5; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        printf("Consumed: %d\n", buffer[out]);
        out = (out+1)%5;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}
int main() {
    pthread_t p, c;
    sem_init(&empty, 0, 5); sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);
    pthread_join(p, NULL); pthread_join(c, NULL);
    return 0;
}
