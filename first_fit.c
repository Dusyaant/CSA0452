#include <stdio.h>
int main() {
    int b[10], p[10], nb, np, i, j;
    scanf("%d %d", &nb, &np);
    for(i=0; i<nb; i++) scanf("%d", &b[i]);
    for(i=0; i<np; i++) {
        scanf("%d", &p[i]);
        for(j=0; j<nb; j++) {
            if(b[j] >= p[i]) {
                printf("P%d in B%d\n", i+1, j+1);
                b[j] -= p[i]; break;
            }
        }
    }
    return 0;
}
