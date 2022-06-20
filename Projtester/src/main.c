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

//my_strlen_tab
int my_strlen_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return (i);
}

// str_to_word_tab
char **str_to_word_tab(char *str)
{
    char **tab = malloc(sizeof(char *) * (my_strlen_tab(str) + 1));
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t') {
            tab[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
            i++;
            j++;
        } else {
            tab[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
            while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0') {
                tab[j][i] = str[i];
                i++;
            }
            tab[j][i] = '\0';
            j++;
        }
    }
    tab[j] = NULL;
    return (tab);
}

void sort_file(char **file)
{
    int i = 0;
    int j = 0;
    char *tmp = NULL;

    for (i = 0; file[i] != NULL; i++) {
        for (j = i + 1; file[j] != NULL; j++) {
            if (my_strcmp(file[i], file[j]) > 0) {
                tmp = file[i];
                file[i] = file[j];
                file[j] = tmp;
            }
        }
    }
}

void print_listes(char *elem, int i)
{
    DIR *dir;
    struct dirent *entry;
    int x = 0;
    char **stock_file = NULL;

    // stock_file = str_to_word_tab(elem);
    // sort_file(stock_file);

    if (!(dir = opendir(elem)))
        return;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
                continue;
            sprintf(path, "%s/%s", elem, entry->d_name);
            for (x = i ;x > 0; x--)
                printf("-");
            printf("%*s%s\n", 0, "", entry->d_name);
            print_listes(path, i + 5);
        } else {
            for (x = i ;x > 0; x--)
                printf("-");
            printf("%*s%s\n", 0, "", entry->d_name);
        }
    }
    closedir(dir);
}

int main(int ac, char **av)
{
    int i = 5;
    if (ac == 1) {
        flag_h();
        return 0;
    }
    for (int i = 0; av[1][i]; i++)
        if (av[1][i] != '.' && av[1][i] != '/')
            printf("%c", av[1][i]);
    printf("\n");
    print_listes(av[1], i);
    return 0;
}
