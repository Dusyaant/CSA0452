#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    int src_fd, dest_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    // 1. Open the source file in Read-Only mode
    src_fd = open("source.txt", O_RDONLY);
    if (src_fd == -1) {
        perror("Error opening source file");
        exit(1);
    }

    // 2. Open/Create the destination file
    // O_WRONLY: Write only
    // O_CREAT: Create if it doesn't exist
    // O_TRUNC: Overwrite if it exists
    // 0644: Permissions (rw-r--r--)
    dest_fd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Error opening/creating destination file");
        close(src_fd);
        exit(1);
    }

    // 3. Read from source and write to destination using a buffer
    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            break;
        }
    }

    if (bytes_read == -1) {
        perror("Error reading source file");
    }

    // 4. Close both file descriptors
    close(src_fd);
    close(dest_fd);

    printf("File copy completed successfully.\n");

    return 0;
}
