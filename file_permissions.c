#include <stdio.h>
#include <sys/stat.h>

int main() {
    char *filename = "test_perm.txt";

    // 1. Create a dummy file
    FILE *fp = fopen(filename, "w");
    fclose(fp);

    // 2. Change permissions using chmod()
    // S_IRUSR = Read (User), S_IWUSR = Write (User), S_IXUSR = Execute (User)
    // 0700 means rwx for owner only
    if (chmod(filename, S_IRUSR | S_IWUSR | S_IXUSR) == 0) {
        printf("Permissions changed successfully to 700 (rwx------)\n");
    }

    // 3. To set specific numeric permissions like 755
    // Note: 0755 starts with 0 to indicate octal in C
    if (chmod(filename, 0755) == 0) {
        printf("Permissions changed successfully to 755 (rwxr-xr-x)\n");
    }

    return 0;
}
