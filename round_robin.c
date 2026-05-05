#include <stdio.h>

int main() {
    int n, qt, count=0, temp, sq=0, bt[10], wt[10], tat[10], rem_bt[10];
    printf("Enter number of processes & Time Quantum: ");
    scanf("%d %d", &n, &qt);
    for(int i=0; i<n; i++) {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }
    while(1) {
        int done = 1;
        for(int i=0; i<n; i++) {
            if(rem_bt[i] > 0) {
                done = 0;
                if(rem_bt[i] > qt) {
                    sq += qt;
                    rem_bt[i] -= qt;
                } else {
                    sq += rem_bt[i];
                    wt[i] = sq - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if(done == 1) break;
    }
    for(int i=0; i<n; i++) tat[i] = bt[i] + wt[i];
    printf("\nPID\tBT\tWT\tTAT\n");
    for(int i=0; i<n; i++) printf("%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    return 0;
}
