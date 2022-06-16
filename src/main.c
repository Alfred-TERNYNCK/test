/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/fasta.h"

#include <stdio.h>

int main (int ac, char **av)
{
    fasta_t *p;
    p = malloc(sizeof(fasta_t));

    if (av[1][0] == '-' && av[1][1] == 'h') {
        flag_h();
        return 0;
    }
    if (option(ac, av, p) == 1) {
        printf("invalid argument\n");
        return 84;
    }
    return 0;
}
