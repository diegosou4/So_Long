#include "../includes/so_long.h"


void count_move(t_vars *vars)
{
    mlx_string_put(vars->mlx, vars->win, 8, 20, 16777215, "Moviment:  ");
    mlx_string_put(vars->mlx, vars->win, 65, 20, 16777215, ft_itoa(vars->person.moviment));
}