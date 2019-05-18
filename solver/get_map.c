/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** get_map
*/

#include "include/solver.h"

int read_file(solv_t *solv, int fd)
{
    struct stat st;
    int len;
    int offset = 0;

    if (fstat(fd, &st))
        return (84);
    solv->map = my_malloc(sizeof(char) * (st.st_size + 1));
    fill_str(solv->map, st.st_size + 1);
    while ((len = read(fd, solv->map + offset, st.st_size - offset)) > 0)
        offset += len;
    solv->x = 1;
    solv->y = 1;
    for (int i = 0; solv->map[i]; i++) {
        if (solv->y < 2 && solv->map[i] != '\n')
            solv->x += 1;
        if (solv->map[i] == '\n')
            solv->y += 1;
    }
    return (0);
}

int open_file(int ac, char **av, solv_t *solv)
{
    int fd = -1;

    if (ac != 2)
        return (84);
    if ((fd = open(av[1], O_RDONLY)) == -1)
        return (84);
    if (read_file(solv, fd) == 84)
        return (84);
    close(fd);
    if (solv->x < 1 || solv->y < 1)
        return (84);
    return (0);
}