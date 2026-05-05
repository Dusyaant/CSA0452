#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t wrt;
pthread_mutex_t mutex;
int read_count = 0;

void* reader(void* arg) {
    pthread_mutex_lock(&mutex);
    read_count++;
    if(read_count == 1) sem_wait(&wrt);
    pthread_mutex_unlock(&mutex);
    printf("Reader is reading...\n");
    pthread_mutex_lock(&mutex);
    read_count--;
    if(read_count == 0) sem_post(&wrt);
    pthread_mutex_unlock(&mutex);
}

void* writer(void* arg) {
    sem_wait(&wrt);
    printf("Writer is writing...\n");
    sem_post(&wrt);
}

int main() {
    pthread_t r, w;
    sem_init(&wrt, 0, 1); pthread_mutex_init(&mutex, NULL);
    pthread_create(&w, NULL, writer, NULL);
    pthread_create(&r, NULL, reader, NULL);
    pthread_join(w, NULL); pthread_join(r, NULL);
    return 0;
}
