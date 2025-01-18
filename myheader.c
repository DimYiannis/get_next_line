#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h> 

char *get_next_line(int fd)
{
    // char static *stash;
    // char *line;

    if (fd > 0)
    {
        char buffer[1024];

        read(fd, buffer, sizeof(buffer));
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