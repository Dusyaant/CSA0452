#include <stdio.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    int shmid = shmget((key_t)1234, 1024, 0666|IPC_CREAT);
    void *shared_memory = shmat(shmid, NULL, 0);
    printf("Process writing to memory...\n");
    strcpy(shared_memory, "Hello from Shared Memory!");
    printf("Data stored: %s\n", (char *)shared_memory);
    shmdt(shared_memory);
    return 0;
}
