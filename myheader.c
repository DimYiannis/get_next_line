#include <fcntl.h>
#include <stdlib.h>


char *get_next_line(int fd)
{
    //opening file in read/write mode with open function
    open(fd, O_RDWR);

    if (fd>0)
    {
        read();
    }
    else
    {
        return NULL;
    }
    
}

char *_fill_line_buffer(int fd, char *left_c, char *buffer)
{

}

char *_set_line(char *line_buffer)
{
    
}