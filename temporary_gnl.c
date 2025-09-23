#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

// función auxiliar para concatenar strings
static char *str_join(char *s1, char *s2, int len2)
{
    int len1 = s1 ? strlen(s1) : 0;
    char *res = malloc(len1 + len2 + 1);
    if (!res) return NULL;

    if (s1)
    {
        memcpy(res, s1, len1);
        free(s1);
    }
    memcpy(res + len1, s2, len2);
    res[len1 + len2] = '\0';
    return res;
}

// get_next_line simplificado
char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int start = 0;
    static int bytes_read = 0;

    char *line = NULL;

    while (1)
    {
        if (start >= bytes_read)
        {
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            start = 0;
            if (bytes_read <= 0)
                return line; // EOF o error
        }

        int i = start;
        while (i < bytes_read && buffer[i] != '\n')
            i++;

        line = str_join(line, buffer + start, i - start);

        if (i < bytes_read && buffer[i] == '\n')
        {
            start = i + 1;
            return line;
        }

        start = i;
    }
}