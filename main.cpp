#include <iostream>

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>

using namespace std;

int main()
{
    int fd_in, fd_out;

    char *fifo_in = "/home/box/in.fifo";
    char *fifo_out = "/home/box/out.fifo";

    mkfifo(fifo_in, 0666);
    mkfifo(fifo_out, 0666);

    char buf[PIPE_BUF];

    while (1)
    {
        fd_in = open(fifo_in, O_RDONLY);
        if (fd_in == -1) {
            cerr << "open error" << endl;
            exit(EXIT_FAILURE);
        }
        read(fd_in, buf, PIPE_BUF);
        close(fd_in);        

        cout << "buf: " << buf << endl;

        fd_out = open(fifo_out, O_WRONLY);
        write(fd_out, buf, strlen(buf) + 1);
        close(fd_out);
    }
    return 0;
}
