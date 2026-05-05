#include <stdio.h>
int main() {
    int b[20], p[20], nb, np, i, j, best;
    scanf("%d %d", &nb, &np);
    for(i=0; i<nb; i++) scanf("%d", &b[i]);
    for(i=0; i<np; i++) scanf("%d", &p[i]);
    for(i=0; i<np; i++) {
        best = -1;
        for(j=0; j<nb; j++) {
            if(b[j] >= p[i]) {
                if(best == -1 || b[j] < b[best]) best = j;
            }
        }
        if(best != -1) {
            printf("P%d in Block %d\n", i+1, best+1);
            b[best] -= p[i];
        }
    }
    return 0;
}
