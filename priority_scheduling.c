#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

void sort_by_priority(struct Process proc[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Lower number = Higher priority
            if (proc[j].priority > proc[j + 1].priority) {
                temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

void calculate_times(struct Process proc[], int n) {
    proc[0].waiting_time = 0;
    proc[0].turnaround_time = proc[0].burst_time;

    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i - 1].waiting_time + proc[i - 1].burst_time;
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
    }
}

int main() {
    int n = 3;
    struct Process proc[] = {
        {1, 10, 2}, // PID 1, Burst 10, Priority 2
        {2, 5, 0},  // PID 2, Burst 5,  Priority 0 (Highest)
        {3, 8, 1}   // PID 3, Burst 8,  Priority 1
    };

    sort_by_priority(proc, n);
    calculate_times(proc, n);

    printf("PID\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\t%d\n", 
               proc[i].pid, proc[i].burst_time, proc[i].priority, 
               proc[i].waiting_time, proc[i].turnaround_time);
    }

    return 0;
}
