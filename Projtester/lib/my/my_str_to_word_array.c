/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** print a char into console
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int check_alpha(char c)
{
    if (c == '/' || c == ' ' || c == '.')
        return 0;
    else
        return 1;
}

int char_count(char *str, int i)
{
    while (str[i] && check_alpha(str[i]) == 1) {
        i++;
    }
    return i;
}

int word_count(char *str)
{
    int i = 0;
    int k = 0;

    while (str[i] != '\0') {
        if (i > 0 && check_alpha(str[i]) == 0 && check_alpha(str[i - 1]) == 1)
            k++;
        i++;
    }
    return k;
}

void check_loop(int *i, int *j, int *k, char const *str)
{
    if (*i > 0 && check_alpha(str[*i]) == 0 &&
    check_alpha(str[*i - 1]) == 1) {
        *i = *i + 1;
        *j = *j + 1;
        *k = 0;
    } else if (*i == 0 && check_alpha(str[*i]) == 1)
        return;
    else
        *i = *i + 1;
}

char **my_str_to_word_array(char *str)
{
    char **tab = NULL;
    int i = 0;
    int j = 0;
    int k = 0;

    if ((tab = malloc(sizeof(char *) * (word_count(str) + 2))) == NULL)
        return NULL;
    while (str[i] != '\0') {
        check_loop(&i, &j, &k, str);
        if ((tab[j] = malloc(sizeof(char) * (char_count(str, i) + 1))) == NULL)
            return NULL;
        for (; str[i] != '\0' && check_alpha(str[i]) == 1; i++) {
            tab[j][k] = str[i];
            k++;
        }
        tab[j][k] = '\0';
    } if (check_alpha(str[i - 1]) == 1)
        j++;
    tab[j] = NULL;
    return tab;
}
