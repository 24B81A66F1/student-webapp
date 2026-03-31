// fifo_reader.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char *myfifo = "myfifo";
    char buffer[100];

    // Open FIFO for reading
    fd = open(myfifo, O_RDONLY);

    // Read message
    read(fd, buffer, sizeof(buffer));

    printf("Message received: %s\n", buffer);

    close(fd);

    return 0;
}
