#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *get_next_line(int fd)
{
    // static char *stash; // Static variable to store leftover characters
    //  char *line;

    if (fd > 0)
    {
        char *buffer = malloc(1024 + 1);
        if (!buffer)
        {
            return NULL; // Handle malloc failure
        }

        int bytesRead = read(fd, buffer, 1024);
        buffer[bytesRead] = '\0'; // Null-terminate the string
        printf("%d bytes read!\n", bytesRead);
        printf("File Contents: %s\n", buffer);
        return buffer;
    }
    else
    {
        return NULL;
    }
}

// char *_fill_line_buffer(int fd, char *left_c, char *buffer)
// {
// }

// char *_set_line(char *line_buffer)
// {
// }