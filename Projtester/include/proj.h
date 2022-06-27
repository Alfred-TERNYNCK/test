/*
** EPITECH PROJECT, 2022
** palindrome.h
** File description:
** prototype
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#ifndef PROJ_H_
    #define PROJ_H_

typedef struct proj_s {
    char **tab;
} proj_t;

int error_case(char **av);
int first_step(char **av);

void print_listes(char *elem, int i);
void print_name(int i, struct dirent *dir);
void print_title(char **av);
void print_directory(char **av, int i);
int tablen(char **tab);

void print_listes_2(char *elem, int i);
void print_folder_2(struct dirent *dir);
char *print_directory_2(struct dirent *dir);
int first_step_2(char **av);
void backup(void);

void flag_cat(char **av);

void flag_h(void);

#endif
