/*
** EPITECH PROJECT, 2022
** requirement.c
** File description:
** requirement
*/

#include <stdlib.h>
#include <stdio.h>

char *my_strcapitalize_synthesis(char *str)
{
    int i = 0;
 
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 32;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z' && (str[i - 1] == ' ') && str[i - 1] == '-' || str[i - 1] == '+')
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}
