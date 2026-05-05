#include <stdio.h>
struct { char dname[10], fname[10][10]; int fcnt; } dir[10];
int main() {
    int i, ch, dcnt = 0;
    while(1) {
        printf("\n1. Create Dir  2. Create File  3. List  4. Exit: ");
        scanf("%d", &ch);
        if(ch==1) { printf("Enter dir name: "); scanf("%s", dir[dcnt++].dname); }
        else if(ch==2) {
            char d[10]; printf("Enter dir name: "); scanf("%s", d);
            for(i=0; i<dcnt; i++)
                if(strcmp(d, dir[i].dname)==0) {
                    printf("File name: "); scanf("%s", dir[i].fname[dir[i].fcnt++]);
                }
        }
        else if(ch==3) {
            for(i=0; i<dcnt; i++) {
                printf("\nDir: %s | Files: ", dir[i].dname);
                for(int j=0; j<dir[i].fcnt; j++) printf("%s ", dir[i].fname[j]);
            }
        } else break;
    }
    return 0;
}
