/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** main
*/

#include "include/solver.h"

void clean_map(solv_t *solv)
{
    for (int i = 0; solv->map[i]; i++)
        if (solv->map[i] == '#')
            solv->map[i] = '*';
}

void write_on_map(solv_t *solv, int i, int *prev_i)
{
    (*prev_i) = i;
    if (solv->map[i] == '*')
        solv->map[i] = 'o';
    else
        solv->map[i] = '#';
}

int find_way(solv_t *solv, int i, char blocked)
{
    if (i + 1 <= MAP_SIZE && solv->map[i + 1] == '*')
        return (1);
    if (i + solv->x <= MAP_SIZE && solv->map[i + solv->x] == '*')
        return (solv->x);
    if (i - solv->x >= 0 && solv->map[i - solv->x] == '*')
        return (-solv->x);
    if (i - 1 >= 0 && solv->map[i - 1] == '*')
        return (-1);
    if (i + 1 <= MAP_SIZE && solv->map[i + 1] == 'o' && blocked)
        return (1);
    if (i + solv->x <= MAP_SIZE && solv->map[i + solv->x] == 'o' && blocked)
        return (solv->x);
    if (i - solv->x >= 0 && solv->map[i - solv->x] == 'o' && blocked)
        return (-solv->x);
    if (i - 1 >= 0 && solv->map[i - 1] == 'o' && blocked)
        return (-1);
    return (0);
}

int solver(solv_t *solv)
{
    char blocked = 0;
    int prev_i = 0;
    int i = 0;

    solv->map[i] = 'o';
    while (i < MAP_SIZE - 1) {
        i += find_way(solv, i, blocked);
        if (i == prev_i) {
            blocked += 1;
        } else if (blocked && solv->map[i] == '*') {
            blocked = 0;
            solv->map[prev_i] = 'o';
        }
        write_on_map(solv, i, &prev_i);
        if (blocked > 2)
            return (84);
    }
    if (solv->map[i] == '*')
        solv->map[i] = 'o';
    return (0);
}

int main(int ac, char **av)
{
    solv_t *solv = my_malloc(sizeof(solv_t));
    pid_t pid;
    int status;

    if (open_file(ac, av, solv) == 84)
        return (84);
    if (solver(solv) == 84) {
        my_putstr("no solution found");
        return (84);
    }
    clean_map(solv);
    write(1, solv->map, MAP_SIZE);
    free(solv->map);
    free(solv);
    return (0);
}