#include <stdio.h>
struct emp { int id; char name[20]; float sal; };
int main() {
    FILE *fp = fopen("emp.dat", "wb+");
    struct emp e;
    int n, i;
    printf("Enter number of employees: "); scanf("%d", &n);
    for(i=0; i<n; i++) {
        e.id = i+1; printf("Name & Salary for ID %d: ", e.id);
        scanf("%s %f", e.name, &e.sal);
        fwrite(&e, sizeof(e), 1, fp);
    }
    printf("\nEnter ID to search: "); scanf("%d", &i);
    fseek(fp, (i-1)*sizeof(e), SEEK_SET);
    fread(&e, sizeof(e), 1, fp);
    printf("ID: %d, Name: %s, Salary: %.2f\n", e.id, e.name, e.sal);
    fclose(fp);
    return 0;
}
