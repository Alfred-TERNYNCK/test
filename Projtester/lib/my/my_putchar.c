/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** print a char into console
*/

#include <stdio.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
