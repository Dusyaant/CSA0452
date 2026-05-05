#include <fcntl.h>
#include <unistd.h>
int main() {
    char buf[20];
    int fd = open("test.txt", O_CREAT | O_RDWR, 0644);
    write(fd, "Hello UNIX", 10);
    lseek(fd, 0, SEEK_SET);
    read(fd, buf, 10);
    write(1, buf, 10);
    close(fd);
    return 0;
}
