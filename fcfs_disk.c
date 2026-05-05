#include <stdio.h>
#include <stdlib.h>

int main() {
    int q[20], n, head, seek = 0;
    printf("Enter number of requests and head position: ");
    scanf("%d %d", &n, &head);
    for(int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
        seek += abs(head - q[i]);
        head = q[i];
    }
    printf("Total Head Movement: %d\n", seek);
    return 0;
}
