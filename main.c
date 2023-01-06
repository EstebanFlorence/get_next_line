#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;
    (void)argc;

//Casting argc to quiet the compiler's warnings.

    fd = open(argv[1], O_RDONLY);
    line = "";
    while (line != NULL)
    {
        line = get_next_line(fd);
        printf("%s", line);
    }
    fd = close(fd);
    return (0);
}