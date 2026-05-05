#include <pthread.h>
#include <stdio.h>
void* func(void* arg) { pthread_exit(NULL); }
int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, func, NULL);
    pthread_create(&t2, NULL, func, NULL);
    if(pthread_equal(t1, t2)) printf("Equal\n");
    else printf("Not Equal\n");
    pthread_join(t1, NULL);
    return 0;
}
