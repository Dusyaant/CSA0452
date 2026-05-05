#include <stdio.h>
int main() {
    int nb, np, b[20], p[20], alloc[20], i, j, wz, id;
    printf("Enter blocks & processes count: ");
    scanf("%d %d", &nb, &np);
    for(i=0; i<nb; i++) scanf("%d", &b[i]);
    for(i=0; i<np; i++) {
        scanf("%d", &p[i]);
        alloc[i] = -1;
    }
    for(i=0; i<np; i++) {
        id = -1; wz = -1;
        for(j=0; j<nb; j++) {
            if(b[j] >= p[i] && b[j] > wz) {
                wz = b[j]; id = j;
            }
        }
        if(id != -1) {
            alloc[i] = id;
            b[id] -= p[i];
        }
    }
    for(i=0; i<np; i++) printf("P%d -> Block %d\n", i+1, alloc[i]+1);
    return 0;
}
