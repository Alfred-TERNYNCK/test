/*
** EPITECH PROJECT, 2022
** open_file.c
** File description:
** open_file
*/

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *open_file(char *str)
{
    char *buffer = NULL;
    int fd = 0;
    struct stat size;

    if ((fd = open(str, O_RDONLY)) <= 0)
        return NULL;
    if (stat(str, &size) < 0)
        return NULL;
    buffer = malloc(sizeof(char) * size.st_size + 1);
    if (read(fd, buffer, size.st_size) <= 0)
        return NULL;
    buffer[size.st_size] = '\0';
    close(fd);
    return (buffer);
}
