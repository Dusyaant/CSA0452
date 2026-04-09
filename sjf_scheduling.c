#include <stdio.h>

void sortProcesses(int n, int p[], int bt[]) {
    int temp;
    // Simple Bubble Sort to order processes by Burst Time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                // Swap Burst Time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                // Swap Process ID to keep track of which is which
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    float avg_wt, avg_tat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int p[n], bt[n], wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sort by smallest execution time (Shortest Job First)
    sortProcesses(n, p, bt);

    wt[0] = 0; // First process in sorted list has 0 wait time

    // Calculate Waiting Time
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        total_wt += wt[i];
    }

    // Calculate Turnaround Time
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_tat += tat[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
