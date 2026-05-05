#include <stdio.h>

int main() {
    int f, n, frames[10], pages[30], fault = 0;
    scanf("%d %d", &f, &n);
    for(int i = 0; i < n; i++) scanf("%d", &pages[i]);
    for(int i = 0; i < f; i++) frames[i] = -1;

    for(int i = 0; i < n; i++) {
        int flag = 0;
        for(int j = 0; j < f; j++) if(frames[j] == pages[i]) flag = 1;
        if(flag == 0) {
            int pos = -1, farthest = i + 1;
            for(int j = 0; j < f; j++) {
                int k;
                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k]) {
                        if(k > farthest) { farthest = k; pos = j; }
                        break;
                    }
                }
                if(k == n) { pos = j; break; }
            }
            if(pos == -1) pos = 0;
            frames[pos] = pages[i];
            fault++;
        }
    }
    printf("Page Faults: %d\n", fault);
    return 0;
}
