#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 5

char *get_next_line(int fd)
{
    static char *stash; // Static variable to store leftover characters
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
    }
    line = malloc(1024); // Allocate memory for line
    if (!line)
    {
        free(buffer);
        free(stash);
        return NULL;
    }

    char *stash_start = stash; // Save the starting position of stash
    char *line_start = line;   // Save the starting position of line

    bytesRead = read(fd, buffer, BUFFER_SIZE);

    while (bytesRead > 0)
    {
        if (bytesRead <= 0)
            break; // Break if no more data is read or error occurs

        buffer[bytesRead] = '\0'; // Null-terminate buffer
        // populate stash
        for (int i = 0; i < bytesRead; i++)
        {
            if (buffer[i] != '\n')
            {
                // Append current character to stash
                *stash++ = buffer[i]; // Move stash pointer forward
            }
            else
            {
                *stash = '\0'; // null terminating string

                stash = stash_start;
                // populating the line, moving backwards in stash and forward in line
                while (*stash)
                {
                    *line++ = *stash++; // Move characters forward to line
                }
                // reset stash back at its initial position
                
                *line = '\0';
                free(buffer);
                printf("File Contents: %s\n", line_start);
                return line_start;
            }
        }
        bytesRead = read(fd, buffer, BUFFER_SIZE);
    }

    free(buffer); // Free buffer memory
    // If we reached the end without any new lines, return NULL
    if (stash_start == stash)
    {
        free(line_start);
        return NULL;
    }

    return line_start;
}