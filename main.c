#include "myheader.h"
#include <fcntl.h>
#include <stdio.h>  // For printf
#include <stdlib.h> // For free
#include <unistd.h> // For close

int main()
{

    // opening file in read/write mode with open function
    int fd = open("test.txt", O_RDWR);
    if (fd == -1)
    {
        printf("error could not open file \n");
        return 1;
    }

    get_next_line(fd);  
}    
    