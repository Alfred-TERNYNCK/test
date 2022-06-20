/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** print a char into console
*/

#include <stdio.h>
#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
