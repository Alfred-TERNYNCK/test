/*
** EPITECH PROJECT, 2022
** flag_1.c
** File description:
** flag_1
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/fasta.h"

int flag_1(fasta_t *p)
{
    char **tab_temp = NULL;
    int j = 0;
    int compt = 0;
    int len = 0;

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
            len = strlen(p->tab[i]);
            compt = 1;
            if (p->tab[i][j] == ' ' || p->tab[i][j] == 'R' || p->tab[i][j] == 'D' ||
            p->tab[i][j] == '=' || p->tab[i][j] == 39) {
                if (p->tab[i][j] == '\n') {
                    printf("%c", p->tab[i][j]);
                    j++;
                }
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
