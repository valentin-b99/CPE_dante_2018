/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** errors_management
*/

#include "include/generator.h"

int error_management(int ac, char **av, gen_t *gen)
{
    if (ac < 3) {
        if (ac == 2 && my_strcmp(av[1], "-h") == 0)
            my_printf(HELP);
        else
            my_putstr_error("Not enough arguments\n");
        return (84);
    } else {
        if (is_digits(av[1]) != 0 || is_digits(av[2]) != 0) {
            my_putstr_error("X and Y must be numbers\n");
            return (84);
        } else if ((gen->x = my_getnbr(av[1])) < 1 ||
        (gen->y = my_getnbr(av[2])) < 1) {
            my_putstr_error("X or Y must be > 0");
            return (84);
        }
    }
    return (0);
}