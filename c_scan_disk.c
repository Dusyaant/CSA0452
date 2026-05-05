#include <stdio.h>
#include <stdlib.h>

int main() {
    int q[20], n, head, max, seek;
    printf("Enter head and disk size: ");
    scanf("%d %d", &head, &max);
    // C-SCAN moves from head to end, then restarts from 0
    seek = (max - head) + max + q[0]; 
    printf("Total Head Movement: %d\n", seek);
    return 0;
}
