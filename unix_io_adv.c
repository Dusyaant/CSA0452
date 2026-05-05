#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
int main() {
    struct stat s;
    stat("test.txt", &s);
    printf("Size: %ld bytes\n", s.st_size);
    DIR *d = opendir(".");
    struct dirent *dir;
    while((dir = readdir(d)) != NULL) printf("%s\n", dir->d_name);
    closedir(d);
    return 0;
}
