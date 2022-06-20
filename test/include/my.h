/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** prototype
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef MY_H_
    #define MY_H_
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int countchar(char *str, char c);
int count_word(char *str, char c);
int my_strcmp(char const *s1, char const *s2);

#endif
