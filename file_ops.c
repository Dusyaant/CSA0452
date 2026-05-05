#include <stdio.h>
int main() {
    FILE *fp = fopen("new.txt", "w");
    fclose(fp);
    rename("new.txt", "old.txt");
    remove("old.txt");
    return 0;
}
