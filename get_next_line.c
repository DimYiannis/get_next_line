#include <fcntl.h>

int main()
{
    int fd;

    //opening the test file in read/write mode with open function
    fd = open("test.txt", O_RDWR);

    if (fd>0)
    {
        /* code */
    }
    
}