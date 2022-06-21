/*
** EPITECH PROJECT, 2022
** palindrome.h
** File description:
** prototype
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef PROJ_H_
    #define PROJ_H_

typedef struct proj_s {
    char **tab;
} proj_t;

void flag_h(void);
void print_listes(char *elem, int i);
void print_title(char **av);
void print_directory(char **av, int i);
void print_listes(char *elem, int i);
int tablen(char **tab);

int first_step_2(char **av);
void print_listes_2(char *elem, int i);


#endif
