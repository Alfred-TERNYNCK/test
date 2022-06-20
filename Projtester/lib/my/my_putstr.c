/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** print a char into console
*/

#include <stdio.h>
#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (1);
}
