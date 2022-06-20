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

// open directory
DIR *open_dir(char *dir)
{
    DIR *dir_ptr = opendir(dir);
    if (dir_ptr == NULL) {
        my_putstr("Error: cannot open directory\n");
        return (NULL);
    }
    return (dir_ptr);
}

// print all files in directory
void print_files(DIR *dir_ptr, char *pass, char **av)
{
    struct dirent *entry;
    int i = 1;

    while ((entry = readdir(dir_ptr)) != NULL) {
        if (entry->d_name[0] != '.') {
            printf("-----");
            printf("%s\n", entry->d_name);
            pass = av[i];
            i++;
            if (entry->d_type == DT_DIR)
                print_files(dir_ptr, pass, av); // str pass
        }
    }
}

int main (int ac, char **av)
{
    struct proj_t *proj = malloc(sizeof(proj_t));
    DIR *dir_ptr = NULL;
    int i = 1;
    char *pass = av[i];

    for (int i = 0; av[1][i]; i++)
        if (av[1][i] != '.' && av[1][i] != '/')
            printf("%c", av[1][i]);
        printf("\n");
    if (ac == 1) {
        flag_h();
        return 0;
    } else {
        dir_ptr = open_dir(av[1]);
        print_files(dir_ptr, pass, av);
    }
    return 0;
}
