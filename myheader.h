#ifndef MYHEADER_H
#define MYHEADER_H

char *get_next_line(int fd);

char *_fill_line_buffer(int fd, char *left_c, char *buffer);

char *_set_line(char *line_buffer);

#endif