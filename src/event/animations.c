/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:13:45 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/27 14:13:51 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	where_mov(t_vars *vars)
{
	if (vars->pdirection == 0)
		vars->curr_sx += 64;
	if (vars->pdirection == 1)
		vars->curr_sx -= 64;
	if (vars->pdirection == 2)
		vars->curr_sy += 64;
	if (vars->pdirection == 3)
		vars->curr_sy -= 64;
}

int	is_exit(t_vars *vars, int sx, int sy)
{
	int	i;
	int	j;

	i = sx / 64;
	j = sy / 64;
	if (vars->game.map[j][i] == 'E')
	{
		vars->assets[DOOR].img.curr_sprite = 0;
		vars->assets[DOOR].img.tamsprite = 64;
		paint_canvaw(vars, &vars->assets[DOOR].img, 256, 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->canva.img, 0, 0);
		return (1);
	}
	else
		return (0);
}

void	mov(t_vars *vars)
{
	static int	i;

	i += 1;
	if (is_exit(vars, vars->curr_sx, vars->curr_sy) == 0)
		paint(vars, &vars->assets[FLOOR], vars->curr_sx - MIDDLE, vars->curr_sy
			- MIDDLE);
	where_mov(vars);
	paint(vars, &vars->assets[vars->pdirection], vars->curr_sx, vars->curr_sy);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->canva.img, 0, 0);
	vars->keypress = 0;
	vars->keycode = 0;
	print_mov(i);
}
