/*
** EPITECH PROJECT, 2022
** requirement.c
** File description:
** requirement
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

void my_ps_synthesis(void)
{
    pid_t pid = fork();
    char *av[2] = {"ps", NULL};

    if (pid == -1)
        return;
    else if (pid == 0)
        execv("/bin/ps", av);
    else if (pid > 0)
        wait(NULL);
}
