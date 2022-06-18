/*
** EPITECH PROJECT, 2022
** option.c
** File description:
** option
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/fasta.h"

// int my_strlen_tab(char *str, char *delim)
// {
//    int i = 0;
//    int j = 0;
//    int compt = 0;

//    while (str[i] != '\0') {
//        if (str[i] == delim[j]) {
//            j++;
//            if (delim[j] == '\0') {
//                compt++;
//                j = 0;
//            }
//        }
//        i++;
//    }
//    return compt;
// }

// char **str_to_word_tab(char *str, char *delim)
// {
//     char **tab = NULL;
//     int i = 0;
//     int j = 0;
//     int k = 0;
//     int l = 0;

//     tab = malloc(sizeof(char *) * (my_strlen_tab(str, delim) + 1));
//     if (tab == NULL)
//         return (NULL);
//     for (i = 0; str[i] != '\0'; i++) {
//         if (str[i] == delim[0]) {
//             tab[j] = malloc(sizeof(char) * (k + 1));
//             if (tab[j] == NULL)
//                 return (NULL);
//             for (l = 0; l < k; l++)
//                 tab[j][l] = str[i - k + l];
//             tab[j][l] = '\0';
//             j++;
//             k = 0;
//         }
//         k++;
//     }
//     tab[j] = malloc(sizeof(char) * (k + 1));
//     if (tab[j] == NULL)
//         return (NULL);
//     for (l = 0; l < k; l++)
//         tab[j][l] = str[i - k + l];
//     tab[j][l] = '\0';
//     return (tab);
// }

// int char_list(char c)
// {
//     char *list = "ATGCN";

//     for (int i = 0; list[i] != '\0'; i++) {
//         if (c == list[i])
//             return 1;
//     }
//     return 0;
// }

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
    p->tab = malloc(sizeof(char *) * 30000);
    size_t len = 0;
    int i = 0;

    while(getline(&line, &len, stdin) != -1) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }
        p->tab[i] = strdup(line);
        i++;
    }
    p->tab[i] = NULL;
    return 0;
}

int option(int ac, char **av, fasta_t *p)
{
    if (ac == 3)
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
    if (strcmp(av[1], "4") == 0) {
        // read_file(p);
        // flag_4(p);
        return 0;
    }
    if (strcmp(av[1], "5") == 0) {
        // read_file(p);
        // flag_5(p);
        return 0;
    }
    else
        return 1;
}