/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** init_map
*/

#include "include/generator.h"

void init_map_imp(gen_t *gen)
{
    char *map = my_malloc(sizeof(char) * (gen->x * gen->y + gen->y + 1));
    int i = 0;
    int j = 0;

    while (i < (gen->x * gen->y + gen->y)) {
        if ((i - j) % gen->x == 0 && i - j != 0) {
            map[i] = '\n';
            j = i + 1;
        } else if (rand()%4 == 0)
            map[i] = 'X';
        else
            map[i] = '*';
        i = i + 1;
    }
    map[i - 1] = '\0';
    map[i - 2] = '\0';
    map[0] = '*';
    map[(gen->x * gen->y + gen->y - 1)] = '\0';
    map[(gen->x * gen->y + gen->y - 2)] = '*';
    write(1, map, (gen->x * gen->y + gen->y - 1));
    free(map);
}

void init_map(gen_t *gen)
{
    int j = 0;
    int i = 0;

    gen->map = my_malloc(sizeof(char) * (gen->x * gen->y + gen->y + 1));
    for (i = 0; i < (gen->x * gen->y + gen->y); i = i + 1) {
        if ((i - j) % gen->x == 0 && i - j != 0) {
            gen->map[i] = '\n';
            j = i + 1;
        } else
            gen->map[i] = 'X';
    }
    gen->map[i - 1] = '\0';
    gen->map[i - 2] = '\0';
    gen->map[0] = '*';
    gen->pos = my_malloc(sizeof(long) * (gen->x * gen->y + 1));
    gen->pos[0] = 0;
    gen->pos[1] = -42;
}