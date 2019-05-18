/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** ways
*/

#include "include/generator.h"

void add_a_pos(gen_t *gen, long pos)
{
    int i = 0;

    for (i = 0; gen->pos[i] != -42; i = i + 1);
    gen->pos[i] = pos;
    gen->pos[i + 1] = -42;
}

int go_right(gen_t *gen, long pos)
{
    if (pos + 2 < (gen->x * gen->y + gen->y - 1) &&
    gen->map[pos + 2] == 'X' && gen->map[pos + 1] != '\n') {
        gen->map[pos + 1] = '*';
        gen->map[pos + 2] = '*';
        add_a_pos(gen, pos + 2);
        return (1);
    }
    return (0);
}

int go_down(gen_t *gen, long pos)
{
    if (pos + (2 * (gen->x + 1)) < (gen->x * gen->y + gen->y - 1) &&
    gen->map[pos + (2 * (gen->x + 1))] != '*') {
        gen->map[pos + (1 * (gen->x + 1))] = '*';
        gen->map[pos + (2 * (gen->x + 1))] = '*';
        add_a_pos(gen, pos + (2 * (gen->x + 1)));
        return (1);
    }
    return (0);
}

int go_left(gen_t *gen, long pos)
{
    if (pos - 2 >= 0 && gen->map[pos - 2] == 'X' &&
    gen->map[pos - 1] != '\n') {
        gen->map[pos - 1] = '*';
        gen->map[pos - 2] = '*';
        add_a_pos(gen, pos - 2);
        return (1);
    }
    return (0);
}

int go_up(gen_t *gen, long pos)
{
    if (pos - (2 * (gen->x + 1)) >= 0 &&
    gen->map[pos - (2 * (gen->x + 1))] != '*') {
        gen->map[pos - (1 * (gen->x + 1))] = '*';
        gen->map[pos - (2 * (gen->x + 1))] = '*';
        add_a_pos(gen, pos - (2 * (gen->x + 1)));
        return (1);
    }
    return (0);
}