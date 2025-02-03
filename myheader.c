#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *get_next_line(int fd)
{
    static char *stash; // Static variable to store leftover characters
    char *line;

    if (fd > 0)
    {
        char *buffer = malloc(1024 + 1);
        if (!buffer)
        {
            return NULL; // Handle malloc failure
        }

        int bytesRead = 5;

        while (bytesRead > 0)
        {
            if (bytesRead <= 0)
                break; // Break if no more data is read or error occurs

            bytesRead = read(fd, buffer, 5);
            // populate stash
            for (int i = 0; i < bytesRead; i++)
            {
                if (buffer[i] == '\n')
                {
                    *stash = '\0'; // null terminating string
                    // populating the line, moving backwards in stash and forward in line
                    while (*--stash)
                    {
                        *line++ = *stash; // Move characters forward to line
                    }

                    // clean stash
                }

                // Append current character to stash
                *stash++ = buffer[i]; // Move stash pointer forward            }
            }

            printf("File Contents: %s\n", buffer);
            return buffer;
        }
    }

    // char *_fill_line_buffer(int fd, char *left_c, char *buffer)
    // {
    // }

    // char *_set_line(char *line_buffer)
    // {
    // }