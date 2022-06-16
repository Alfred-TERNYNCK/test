/*
** EPITECH PROJECT, 2022
** option.c
** File description:
** option
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/fasta.h"

int char_list(char c)
{
    char *list = "ATGCN";

    for (int i = 0; list[i] != '\0'; i++) {
        if (c == list[i])
            return 1;
    }
    return 0;
}

char *my_strcapitalize_synthesis(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z' && (str[i - 1] == ' '))
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}

int read_file(fasta_t *p)
{
    char *line = NULL;
    p->tab = malloc(sizeof(char) * 30000);
    size_t len = 0;
    int i = 0;

    while(getline(&line, &len, stdin) != -1) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }
        p->tab[i] = strdup(line);
        printf("%s", p->tab[i]);
        i++;
    }
    p->tab[i] = NULL;
    return 0;
}

int option(int ac, char **av, fasta_t *p)
{
    if (ac < 2)
        return 1;
    if (strcmp(av[1], "1") == 0) {
        read_file(p);
        flag_1(p);
        return 0;
    }
    if (strcmp(av[1], "2") == 0) {
        read_file(p);
        flag_2(p);
        return 0;
    }
    if (strcmp(av[1], "3") == 0) {
        read_file(p);
        flag_3(p);
        return 0;
    }
    else
        return 1;
}