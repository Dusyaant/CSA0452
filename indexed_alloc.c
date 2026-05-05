#include <stdio.h>

int main() {
    int index, n, blocks[20];
    printf("Enter index block: ");
    scanf("%d", &index);
    printf("Enter number of blocks: ");
    scanf("%d", &n);
    printf("Enter block numbers: ");
    for(int i = 0; i < n; i++) scanf("%d", &blocks[i]);

    printf("\nIndex Block: %d\n", index);
    for(int i = 0; i < n; i++) printf("%d -> %d\n", index, blocks[i]);
    return 0;
}
