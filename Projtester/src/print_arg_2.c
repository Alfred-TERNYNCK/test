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

void display_name_2(int i, struct dirent *dir)
{
    char *str = NULL;
    printf("%s :%s\n", dir->d_name, str);
}

void display_name_2_2(int i, struct dirent *dir)
{
    printf("[%s] ", dir->d_name);
}

int first_step_2(char **av)
{
    int i = 5;
    char **tab = my_str_to_word_array(av[1]);
    char *elem = av[1];
    for (int j = 0; tab[j] != NULL; j++)
    print_listes_2(elem, i);
    return 0;
}

void print_listes_2(char *elem, int i)
{
    struct dirent **dir_tab;
    struct dirent *dir;
    char *dirent_p;
    int n = scandir(elem, &dir_tab, 0, alphasort);
    int j = 0;

    for (int j = 0; j != n; j++) {
        if (dir_tab[j]->d_type != DT_DIR)
            display_name_2(i, dir_tab[j]);
            //printf("%s", dir->d_name);
        else if (dir_tab[j]->d_type == DT_DIR &&
        strncmp(dir_tab[j]->d_name, ".", 1)) {
            display_name_2_2(i, dir_tab[j]);
            dirent_p = malloc(sizeof(char) *
            (strlen(elem) + strlen(dir_tab[j]->d_name)) + 2);
            sprintf(dirent_p, "%s/%s", elem, dir_tab[j]->d_name);
            //printf("%s", dir->d_name);
            print_listes_2(dirent_p, i + 5);
            free(dirent_p);
        }
    }
}
