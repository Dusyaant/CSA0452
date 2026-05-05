#include <stdio.h>
int main() {
    int f=3, p[]={1,3,0,3,5,6}, m[]={-1,-1,-1}, count=0, hit=0;
    for(int i=0; i<6; i++) {
        int found=0;
        for(int j=0; j<f; j++) if(m[j]==p[i]) { found=1; hit++; }
        if(!found) { m[count%f]=p[i]; count++; }
    }
    printf("Faults: %d\n", count);
    return 0;
}
