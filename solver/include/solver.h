/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** dante
*/

#ifndef SOLVER_H
#define SOLVER_H

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../../lib/my/mylib.h"

typedef struct solv_s {
    char *map;
    int x;
    int y;
} solv_t;

#define MAP_SIZE ((solv->x * solv->y) - 1)

/* get_map.c */
int count_lines(solv_t *s, int fd);
int read_file(solv_t *s, int fd);
int open_file(int ac, char **av, solv_t *s);

#endif