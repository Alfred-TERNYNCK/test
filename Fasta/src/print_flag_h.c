/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "../include/my.h"
#include "../include/fasta.h"

void flag_h(void)
{
    printf("USAGE\n");
    printf("\t./FASTAtools option [k]\n");
    printf("DESCRIPTION\n");
    printf("\toption 1: read FASTA from the standard input, write the DNA");
    printf(" sequences to the\n");
    printf("\t\tstandard output\n");
    printf("\toption 2: read FASTA from the standard input, write the RNA");
    printf("A sequences to the\n");
    printf("\t\tstandard output\n");
    printf("\toption 3: read FASTA from the standard input, write the");
    printf(" reverse complement\n");
    printf("\t\tto the standard output\n");
}
