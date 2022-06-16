/*
** EPITECH PROJECT, 2022
** option.c
** File description:
** option
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/fasta.h"

// my_strdup(char *str)


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

int flag_1(fasta_t *p)
{
    int j = 0;
    int compt = 0;

    for (int i = 0; p->tab[i] != NULL; i++) {
        if (p->tab[i][j] == '>') {
            printf("%s\n", p->tab[i]);
            i++;
        }
        if (p->tab[i - 1][0] == '>')
            printf("\n");
        for (int j = 0; p->tab[i][j] != '\0'; j++) {
            if (p->tab[i][j] >= 'a' && p->tab[i][j] <= 'z') {
                p->tab[i][j] = p->tab[i][j] - 32;
            }
            if (p->tab[i][j] == ' ' || p->tab[i][j] == 'R' || p->tab[i][j] == 'D')
                p->tab[i][j] = p->tab[i][j - 1];
        }
        printf("%s", p->tab[i]);
    }
    return 0;
}

// char **my_strcapitalize(char **tab)
// {
//     int i = 0;

//     while (tab[i] != '\0' && tab[i] != '\n') {
//         if (tab[i] == '>') {
//             for (i; tab[i] != '\n' && tab[i] != '\0'; i++)
//                 printf("%c", tab[i]);
//             printf("\n");
//         }
//         else if (tab[i + 1] == '>')
//             printf("\n");
//         else if (tab[i] == '\n' && tab[i - 1] >= 'A' && tab[i - 1] <= 'Z' && tab[i + 1] != '>') {
//             i++;
//         }
//         else if (tab[i] == ' ')
//             i++;
//         else if (tab[i] >= 'a' && tab[i] <= 'z') {
//             tab[i] = tab[i] - 32;
//             printf("%c", tab[i]);
//         }
//         else if (tab[i] >= 'A' && tab[i] <= 'Z') {
//             printf("%c", tab[i]);
//             i++;
//         }
//     }
//     return tab;
// }

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
        printf("%s\n", p->tab[i]);
        i++;
    }
    p->tab[i] = NULL;
    printf("----------------------\n");
    return 0;
}

// char *flag_1(char *seq)
// {
//     for (int i = 0; seq[i] != '\0'; i++) {
//         if (seq[i] == '\n' && (seq[i - 1] >= 'A' && seq[i - 1] <= 'Z' && seq[i + 1] != '>') || seq[i] == ' ')
//             i++;
//         printf("%c", seq[i]);
//     }
//     return seq;
// }

int option(int ac, char **av, fasta_t *p)
{
    if (ac < 2)
        return 1;
    if (strcmp(av[1], "1") == 0) {
        read_file(p);
        flag_1(p);
    }
    return 0;
}