#include "myheader.h"
#include <fcntl.h>

int main()
{

    // opening file in read/write mode with open function
    int fd = open("test.txt", O_RDWR);

    get_next_line(fd);
}