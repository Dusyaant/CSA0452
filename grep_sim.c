#include <stdio.h>
#include <string.h>
int main() {
    char line[100], pat[20];
    FILE *fp = fopen("test.txt", "r");
    printf("Pattern: "); scanf("%s", pat);
    while(fgets(line, 100, fp)) if(strstr(line, pat)) printf("%s", line);
    fclose(fp);
    return 0;
}
