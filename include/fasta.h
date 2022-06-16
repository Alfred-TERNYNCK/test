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

#ifndef FASTA_H_
    #define FASTA_H_

typedef struct fasta_s {
    char **tab;
} fasta_t;

void flag_h(void);
int option(int ac, char **av, fasta_t *p);
char *my_strcapitalize(char *str);
char *open_file(char *str);
int flag_1(fasta_t *p);
int char_list(char c);

#endif
