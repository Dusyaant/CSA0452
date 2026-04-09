#include <stdio.h>

void calculateMetrics(int n, int burst_time[]) {
    int wait_time[n], turnaround_time[n];
    float total_wt = 0, total_tat = 0;

    // First process has 0 waiting time
    wait_time[0] = 0;

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        wait_time[i] = wait_time[i - 1] + burst_time[i - 1];
    }

    // Calculate turnaround time and totals
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + wait_time[i];
        total_wt += wait_time[i];
        total_tat += turnaround_time[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], wait_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst_time[n];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    calculateMetrics(n, burst_time);

    return 0;
}
