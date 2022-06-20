/*
** EPITECH PROJECT, 2022
** flag_3.c
** File description:
** flag_3
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/fasta.h"

char *my_revstr(char *str)
{
    int b = 0;
    int a = 0;
    char c;

    while (str[b] != '\0')
        b += 1;
    b = b - 1;
    while (a < b) {
        c = str[a];
        str[a] = str[b];
        str[b] = c ;
        a += 1;
        b -= 1;
    }
    return str;
}

int replace(fasta_t *p, int i, int j)
{
    if (p->tab[i][j] == 'A')
        p->tab[i][j] = 'T';
    else if (p->tab[i][j] == 'G')
        p->tab[i][j] = 'C';
    else if (p->tab[i][j] == 'T')
        p->tab[i][j] = 'A';
    else if (p->tab[i][j] == 'C')
        p->tab[i][j] = 'G';
    return 0;
}

int flag_3(fasta_t *p)
{
    int j = 0;
    int compt = 0;
    int len = 0;
    int len2 = 0;
    char *temp = NULL;

    for (int i = 0; p->tab[i] != NULL; i++) {
        if (p->tab[i][j] == '>') {
            if (compt == 1)
                printf("\n");
            printf("%s\n", p->tab[i]);
            compt ++;
            i++;
        }
        for (int j = 0; p->tab[i][j] != '\0'; j++) {
            if (p->tab[i][j] >= 'a' && p->tab[i][j] <= 'z') {
                p->tab[i][j] = p->tab[i][j] - 32;
            }
            p->tab[i] = my_revstr(p->tab[i]);
            replace(p, i, j);
            len = strlen(p->tab[i]);
            len2 = len;
            compt = 1;
            if (p->tab[i][j] == ' ' || p->tab[i][j] == 'R' || p->tab[i][j] == 'D' ||
            p->tab[i][j] == '=' || p->tab[i][j] == 39) {
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
