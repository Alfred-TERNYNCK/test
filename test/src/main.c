/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
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
#include "../include/my.h"
#include "../include/proj.h"

void print_files(char *path)
{
    DIR * d = opendir(path);
    if (d == NULL)
        return;
    struct dirent *dir;
    while ((dir = readdir(d)) != NULL) {
        if (dir->d_type != DT_DIR)
            printf("-----%s\n", dir->d_name);
        if (dir->d_type == DT_DIR && strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0 ) {
            printf("-----%s\n", dir->d_name);
            char d_path[255];
            printf("-----");
            sprintf(d_path, "%s/%s", path, dir->d_name);
            print_files(d_path);
        }
    }
    closedir(d);
}


int main (int ac, char **av)
{
    char *path = av[1];
    if (ac == 1) {
        flag_h();
        return 0;
    }
    for (int i = 0; av[1][i]; i++)
        if (av[1][i] != '.' && av[1][i] != '/')
            printf("%c", av[1][i]);
        printf("\n");
    print_files(path);
    return 0;
}
