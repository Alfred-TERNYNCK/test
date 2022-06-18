/*
** EPITECH PROJECT, 2022
** requirement.c
** File description:
** requirement
*/

#include <stdlib.h>
#include <stdio.h>

char already_char(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    if (c >= 'A' && c <= 'Z')
        return c;
}

char *my_strcapitalize_synthesis(char *str)
{
    int i = 0;

    if (str == NULL)
        return (NULL);
 
    while (str[i] != '\0') {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
            if ((str[i - 1] < 48 || str[i - 1] > 57) && (str[i - 1] < 97 ||
            str[i] > 122) && (str[i - 1] < 65 || str[i - 1] > 90))
                str[i] = already_char(str[i]);
    }
    return (str);
}
