#include <stdio.h>

int main() {
    int n, start, len, blocks[100] = {0};
    printf("Enter number of files: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter start block and length: ");
        scanf("%d %d", &start, &len);
        int can_alloc = 1;
        for(int j = start; j < (start + len); j++) if(blocks[j] == 1) can_alloc = 0;
        if(can_alloc) {
            for(int j = start; j < (start + len); j++) blocks[j] = 1;
            printf("File allocated to disk\n");
        } else printf("Block already allocated!\n");
    }
    return 0;
}
