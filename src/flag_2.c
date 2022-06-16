/*
** EPITECH PROJECT, 2022
** flag_2.c
** File description:
** flag_2
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/fasta.h"

int flag_2(fasta_t *p)
{
    int j = 0;
    int compt = 0;
    int len = 0;

    for (int i = 0; p->tab[i] != NULL; i++) {
        if (p->tab[i][j] == '>') {
            if (compt == 1)
                printf("\n");
            printf("%s", p->tab[i]);
            compt ++;
            i++;
        }
        if (p->tab[i - 1][0] == '>')
            printf("\n");
        for (int j = 0; p->tab[i][j] != '\0'; j++) {
            if (p->tab[i][j] >= 'a' && p->tab[i][j] <= 'z') {
                p->tab[i][j] = p->tab[i][j] - 32;
            }
            if (p->tab[i][j] == 'T')
                p->tab[i][j] = 'U';
            len = strlen(p->tab[i]);
            if (p->tab[i][j] == ' ' || p->tab[i][j] == 'R' || p->tab[i][j] == 'D') {
                for(int z = j; z < len; z++)
                    p->tab[i][z] = p->tab[i][z + 1];
                len--;
                j--;
            }
        }
        printf("%s", p->tab[i]);
    }
    return 0;
}
