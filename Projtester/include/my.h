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
int check_alpha(char c);
int my_strlen(char const *str);
int char_count(char *str, int i);
int countchar(char *str, char c);
int count_word(char *str, char c);
int word_count(char *str);
void check_loop(int *i, int *j, int *k, char const *str);
char **my_str_to_word_array(char *str);
int my_strcmp(char const *s1, char const *s2);

#endif
