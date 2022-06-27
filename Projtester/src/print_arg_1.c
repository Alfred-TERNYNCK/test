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

int tablen(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return i - 1;
}

void print_directory(char **av, int i)
{
    char *one = "rootDirectory1";
    char *two = "rootDirectory2";
    char *three = "rootDirectory3";

    if (av[1][i] == '1')
        printf("%s\n", one);
    else if (av[1][i] == '2')
        printf("%s\n", two);
    else if (av[1][i] == '3')
        printf("%s\n", three);
}

void print_title(char **av)
{
    for (int i = 0; av[1][i]; i++) {
        if (av[1][i] != '.' && av[1][i] != '/')
            print_directory(av, i);
    }
}

void print_name(int i, struct dirent *dir)
{
    for (int compt = 0; compt < i; compt++)
        printf("-");
    printf("%s\n", dir->d_name);
}

void print_listes(char *elem, int i)
{
    struct dirent **dir_tab;
    char *dirent_p;
    int n = scandir(elem, &dir_tab, 0, alphasort);
    int j = 0;

    for (int j = 0; j != n; j++) {
        if (dir_tab[j]-> d_type != DT_DIR)
            print_name(i, dir_tab[j]);
        else if (dir_tab[j]-> d_type == DT_DIR &&
        strncmp(dir_tab[j]->d_name, ".", 1)) {
            print_name(i, dir_tab[j]);
            dirent_p = malloc(sizeof(char) *
            (strlen(elem) + strlen(dir_tab[j]->d_name)) + 2);
            sprintf(dirent_p, "%s/%s", elem, dir_tab[j]->d_name);
            print_listes(dirent_p, i + 5);
            free(dirent_p);
        }
    }
}
