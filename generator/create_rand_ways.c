/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** create_rand_ways
*/

#include "include/generator.h"

int rand_way_one(gen_t *gen, long pos)
{
    int (*ways[4])(gen_t *gen, long pos) =
    {go_right, go_down, go_left, go_up};
    int i = 0;

    for (i = 0; i < 4 && ways[i](gen, pos) == 0; i = i + 1);
    return (i);
}

int rand_way_two(gen_t *gen, long pos)
{
    int (*ways[4])(gen_t *gen, long pos) =
    {go_down, go_left, go_up, go_right};
    int i = 0;

    for (i = 0; i < 4 && ways[i](gen, pos) == 0; i = i + 1);
    return (i);
}

int rand_way_three(gen_t *gen, long pos)
{
    int (*ways[4])(gen_t *gen, long pos) =
    {go_left, go_up, go_right, go_down};
    int i = 0;

    for (i = 0; i < 4 && ways[i](gen, pos) == 0; i = i + 1);
    return (i);
}

int rand_way_four(gen_t *gen, long pos)
{
    int (*ways[4])(gen_t *gen, long pos) =
    {go_up, go_right, go_down, go_left};
    int i = 0;

    for (i = 0; i < 4 && ways[i](gen, pos) == 0; i = i + 1);
    return (i);
}