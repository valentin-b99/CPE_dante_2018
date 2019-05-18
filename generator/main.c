/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** main
*/

#include "include/generator.h"

void set_ways(gen_t *gen)
{
    int (*ways[4])(gen_t *gen, long pos) =
    {rand_way_one, rand_way_two, rand_way_three, rand_way_four};
    int i = 0;

    while (gen->pos[0] != -42) {
        while (ways[rand()%4](gen, gen->pos[i]) < 4)
            i = i + 1;
        gen->pos[i] = -42;
        i = i - 1;
    }
}

void odd_maps(gen_t *gen)
{
    if (gen->x % 2 == 0)
        gen->map[(gen->x * gen->y + gen->y) - 2] = '*';
    if (gen->y % 2 == 0 && gen->x % 2 == 0)
        gen->map[(gen->x * gen->y + gen->y) - gen->x - 3] = '*';
    if (gen->y % 2 == 0 && gen->x % 2 != 0)
        gen->map[(gen->x * gen->y + gen->y) - 2] = '*';
}

void destroy_gen(gen_t *gen)
{
    free(gen->map);
    free(gen->pos);
    free(gen);
}

int main(int ac, char **av)
{
    gen_t *gen = my_malloc(sizeof(gen_t));

    if (error_management(ac, av, gen) == 84)
        return (84);
    srand(time(NULL));
    if (ac == 4) {
        init_map(gen);
        set_ways(gen);
        odd_maps(gen);
        write(1, gen->map, (gen->x * gen->y + gen->y - 1));
        destroy_gen(gen);
    } else {
        init_map_imp(gen);
        free(gen);
    }
    return (0);
}