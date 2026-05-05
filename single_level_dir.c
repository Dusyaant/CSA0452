#include <stdio.h>
#include <string.h>

int main() {
    int i, n = 0;
    char dir[20], file[20][20];
    printf("Enter directory name: ");
    scanf("%s", dir);
    while(1) {
        printf("\n1. Create File  2. List Files  3. Exit\nEnter choice: ");
        int ch; scanf("%d", &ch);
        if(ch == 1) {
            printf("Enter file name: ");
            scanf("%s", file[n++]);
        } else if(ch == 2) {
            printf("\nDirectory: %s\nFiles: ", dir);
            for(i=0; i<n; i++) printf("%s  ", file[i]);
        } else break;
    }
    return 0;
}
