#include <stdio.h>
#include <stdlib.h>

int main() {
    int q[20], n, head, max, temp, seek = 0;
    printf("Enter n, head, disk size: ");
    scanf("%d %d %d", &n, &head, &max);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    // Sort queue
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(q[i]>q[j]) { temp=q[i]; q[i]=q[j]; q[j]=temp; }
    
    seek = (max - head) + (max - q[0]); // Assumes moving to high end first
    printf("Total Head Movement: %d\n", seek);
    return 0;
}
