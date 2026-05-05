#include <stdio.h>

int main() {
    int frames[10], pages[30], counter[10], n, f, fault = 0;
    printf("Enter number of frames and pages: ");
    scanf("%d %d", &f, &n);
    printf("Enter reference string: ");
    for(int i = 0; i < n; i++) scanf("%d", &pages[i]);
    for(int i = 0; i < f; i++) frames[i] = -1;

    for(int i = 0; i < n; i++) {
        int flag = 0;
        for(int j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                flag = 1; counter[j] = i; break;
            }
        }
        if(flag == 0) {
            int pos = 0, min = counter[0];
            for(int j = 1; j < f; j++) {
                if(counter[j] < min) { min = counter[j]; pos = j; }
            }
            frames[pos] = pages[i];
            counter[pos] = i;
            fault++;
        }
    }
    printf("Total Page Faults: %d\n", fault);
    return 0;
}
