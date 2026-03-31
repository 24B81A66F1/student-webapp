// fifo_writer.c
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char *myfifo = "myfifo";
    char msg[] = "Hello from writer using FIFO";

    // Create named pipe
    mkfifo(myfifo, 0666);

    // Open FIFO for writing
    fd = open(myfifo, O_WRONLY);

    // Write message
    write(fd, msg, strlen(msg) + 1);

    printf("Message sent through FIFO\n");

    close(fd);

    return 0;
}
