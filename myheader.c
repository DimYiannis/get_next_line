#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 5

char *get_next_line(int fd)
{
    static char *stash;       // Static variable to store leftover characters
    static char *stash_write; // Keep track of where we left off in stash
    char *buffer;
    char *line = malloc(1024);
    int bytesRead;

    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return NULL;
    }

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
    {
        return NULL;
    }

    if (!stash)
    {
        stash = malloc(1024);
        if (!stash)
        {
            free(buffer);
            return NULL;
        }
        stash[0] = '\0';
        stash_write = stash;
    }

    char *stash_start = stash; // starting position of stash
    char *line_start = line;   // original position of line

    // First read all content into stash
    while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        // populate stash
        for (int i = 0; i < bytesRead; i++)
        {
            *stash_write++ = buffer[i];
        }
    }
    *stash_write = '\0';
    free(buffer);

    // Now check stash for newline and copy to line
    while (*stash_start && *stash_start != '\n')
    {
        *line++ = *stash_start++;
    }
    *line = '\0';

    // If we found a newline, move past it for next time
    if (*stash_start == '\n')
        stash_start++;

    // Move remaining content to start of stash
    stash_write = stash; //move stash write in the beginning of stash
    while (*stash_start)
    {
        *stash_write++ = *stash_start++; //copy remining characters
    }
    *stash_write = '\0'; //null terminate

    printf("File Contents: %s\n", line_start);
    return line_start;
}