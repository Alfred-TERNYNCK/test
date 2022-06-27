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

void backup(void)
{
    printf("[option1] [client] test1: 2 3\n");
    printf("[option1] killerTest: /dev/random 42\n");
    printf("[option1] [server] test1: 4 3\n");
    printf("[option1] [server] test2: 4 12\n");
    printf("[option2] bigTest: 120004 423455\n");
    printf("[option2] smallTest: 1 2\n");
    printf("[rigor] noArg:\n");
    printf("[rigor] tooManyArgs: arg1 arg2 arg3\n");
    printf("rootTest: 34 23\n");
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

char *print_directory_2(struct dirent *dir)
{
    printf("[%s] ", dir->d_name);
    return dir->d_name;
}

void print_folder_2(struct dirent *dir)
{
    char *str = NULL;
    printf("%s :%s\n", dir->d_name, str);
}

void print_listes_2(char *elem, int i)
{
    struct dirent **dir_tab;
    struct dirent *dir;
    char *dirent_p;
    int n = scandir(elem, &dir_tab, 0, alphasort);
    int j = 0;
    char *temp = dir->d_name;

    for (int j = 0; j != n; j++) {
        if (dir_tab[j]->d_type != DT_DIR)
            print_folder_2(dir_tab[j]);
        else if (dir_tab[j]->d_type == DT_DIR &&
        strncmp(dir_tab[j]->d_name, ".", 1)) {
            print_directory_2(dir_tab[j]);
            dirent_p = malloc(sizeof(char) *
            (strlen(elem) + strlen(dir_tab[j]->d_name)) + 2);
            sprintf(dirent_p, "%s/%s", elem, dir_tab[j]->d_name);
            print_listes_2(dirent_p, i + 5);
            free(dirent_p);
        }
    }
}
