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

int first_step(char **av)
{
    int i = 5;
    char **tab = my_str_to_word_array(av[1]);
    char *elem = av[1];
    for (int j = 0; tab[j] != NULL; j++)
    print_listes(elem, i);
    return 0;
}

int error_case(char **av)
{
    struct dirent *entry;
    DIR *dir = opendir(av[1]);

    if (dir == NULL)
        return 1;
    if ((entry = readdir(dir)) == NULL)
        return 1;
    else
        return 0;
}

int main(int ac, char **av)
{
    int z = 5;
    if (av[1] == NULL) {
        printf("ERROR: binary not found\n");
        return 84;
    }
    if (strcmp(av[1], "-h") == 0) {
        flag_h();
        return 0;
    }
    if (error_case(av) == 1)
        return 84;
    if (ac == 2) {
        print_title(av);
        first_step(av);
        return 0;
    }
    if (ac == 3) {
        first_step_2(av);
        return 0;
    }
    return 0;
}
