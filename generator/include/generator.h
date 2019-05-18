/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** dante
*/

#ifndef GENERATOR_H
#define GENERATOR_H

#include "../../lib/my/mylib.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define HELP "Usage:\n\t./generator size_x size_y (+ optional: [perfect])\n"

typedef struct gen_t gen_t;
struct gen_t {
    char *map;
    int x;
    int y;
    long *pos;
};

/* init_map.c */
void init_map_imp(gen_t *gen);
void init_map(gen_t *gen);

/* errors_management.c */
int error_management(int ac, char **av, gen_t *gen);

/* ways.c */
int go_right(gen_t *gen, long pos);
int go_down(gen_t *gen, long pos);
int go_left(gen_t *gen, long pos);
int go_up(gen_t *gen, long pos);

/* create_rand_ways.c */
int rand_way_one(gen_t *gen, long pos);
int rand_way_two(gen_t *gen, long pos);
int rand_way_three(gen_t *gen, long pos);
int rand_way_four(gen_t *gen, long pos);

#endif