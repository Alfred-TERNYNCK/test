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

int tablen(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return i - 1;
}

void display_name(int i, struct dirent *dir)
{
    for (int compt = 0; compt < i; compt++)
        printf("-");
    printf("%s\n", dir->d_name);
}

void print_listes(char *elem, int i)
{
    struct dirent **dir_tab;
    char *d_path;
    int n = scandir(elem, &dir_tab, 0, alphasort);
    int j = 0;

    for (int j = 0; j != n; j++) {
        if (dir_tab[j]-> d_type != DT_DIR)
            display_name(i, dir_tab[j]);
        else if (dir_tab[j]-> d_type == DT_DIR &&
        strncmp(dir_tab[j]->d_name, ".", 1)) {
            display_name(i, dir_tab[j]);
            d_path = malloc(sizeof(char) *
            (strlen(elem) + strlen(dir_tab[j]->d_name)) + 2);
            sprintf(d_path, "%s/%s", elem, dir_tab[j]->d_name);
            print_listes(d_path, i + 5);
            free(d_path);
        }
    }
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
    if (ac == 1) {
        flag_h();
        return 0;
    }
    else if (av[1] == NULL)
        return 84;
    if (error_case(av) == 1)
        return 84;
    for (int i = 0; av[1][i]; i++)
        if (av[1][i] != '.' && av[1][i] != '/')
            printf("%c", av[1][i]);
    printf("\n");
    first_step(av);
    return 0;
}
