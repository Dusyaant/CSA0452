#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // fork() 
    pid = fork();

    if (pid < 0) {
        // Error occurred
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } 
    else if (pid == 0) {
        // This block is executed by the Child Process
        printf("\n--- Child Process ---");
        printf("\nProcess ID (PID): %d", getpid());
        printf("\nParent Process ID (PPID): %d\n", getppid());
    } 
    else {
        // This block is executed by the Parent Process
        // pid contains the ID of the child
        printf("\n--- Parent Process ---");
        printf("\nProcess ID (PID): %d", getpid());
        printf("\nChild Process ID: %d\n", pid);
        
        
        sleep(1); 
    }

    return 0;
}
