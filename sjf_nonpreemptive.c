#include <stdio.h>

int main() {
    int n, bt[20], p[20], wt[20], tat[20], i, j, total=0, pos, temp;
    printf("Enter number of process: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        p[i] = i+1;
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
    }
    // Sorting by Burst Time
    for(i=0; i<n; i++) {
        pos=i;
        for(j=i+1; j<n; j++) if(bt[j] < bt[pos]) pos=j;
        temp=bt[i]; bt[i]=bt[pos]; bt[pos]=temp;
        temp=p[i]; p[i]=p[pos]; p[pos]=temp;
    }
    wt[0]=0;
    for(i=1; i<n; i++) {
        wt[i]=0;
        for(j=0; j<i; j++) wt[i] += bt[j];
    }
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i=0; i<n; i++) {
        tat[i] = bt[i] + wt[i];
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    return 0;
}
