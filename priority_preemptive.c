#include <stdio.h>

struct Process {
    int pid, at, bt, priority, rt, ct, tat, wt;
};

int main() {
    int n, completed = 0, current_time = 0, min_priority = 9999, short_p = -1;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("P%d Arrival, Burst, Priority: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
        p[i].rt = p[i].bt;
    }

    while(completed != n) {
        short_p = -1;
        min_priority = 9999;
        for(int i = 0; i < n; i++) {
            if(p[i].at <= current_time && p[i].rt > 0 && p[i].priority < min_priority) {
                min_priority = p[i].priority;
                short_p = i;
            }
        }
        if(short_p == -1) { current_time++; continue; }
        p[short_p].rt--;
        if(p[short_p].rt == 0) {
            completed++;
            p[short_p].ct = current_time + 1;
            p[short_p].tat = p[short_p].ct - p[short_p].at;
            p[short_p].wt = p[short_p].tat - p[short_p].bt;
        }
        current_time++;
    }
    printf("PID\tAT\tBT\tPRI\tWT\tTAT\n");
    for(int i=0; i<n; i++) printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].wt, p[i].tat);
    return 0;
}
