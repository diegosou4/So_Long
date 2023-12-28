/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:14:01 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/27 14:14:06 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	print_mov(t_vars *vars)
{
	write(1, "Movimentos:", 11);
	ft_putnbr(vars->person.moviment);
	write(1, "\n", 1);
}

void	which_key(int keycode, t_vars *vars)
{
	if (keycode == KEY_D && vars->keypress == 0)
	{
		vars->keycode = KEY_D;
		vars->person.direction = 0;
		vars->keypress = 1;
	}
	if (keycode == KEY_A && vars->keypress == 0)
	{
		vars->keycode = KEY_A;
		vars->person.direction = 1;
		vars->keypress = 1;
	}
	if (keycode == KEY_S && vars->keypress == 0)
	{
		vars->keycode = KEY_S;
		vars->person.direction = 2;
		vars->keypress = 1;
	}
	if (keycode == KEY_W && vars->keypress == 0)
	{
		vars->keycode = KEY_W;
		vars->person.direction = 3;
		vars->keypress = 1;
	}
}

int	key_event(int keycode, t_vars *vars)
{
	if (keycode == ESC && vars->keypress == 0)
	{
		exit_game(vars);
		vars->keypress = 1;
	}
	if (vars->keypress == 0)
		which_key(keycode, vars);
	if (is_wall(vars) == 0)
		vars->keypress = 0;
	return (0);
}

int	keynotpress(t_vars *vars)
{
	int	j;

	j = 360;
	if (vars->game.coletables[1] == 0)
	{
		vars->door.tamsprite = 256;
		vars->door.curr_sprite = 192;
		paint_canvaw(vars, &vars->door, 256, 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->canva.img, 0, 0);
	}
	if (vars->keypress == 1 && vars->keycode == KEY_D)
		j = right_animation(vars, vars->person.direction, j);
	if (vars->keypress == 1 && vars->keycode == KEY_A)
		j = left_animation(vars, vars->person.direction, j);
	if (vars->keypress == 1 && vars->keycode == KEY_S)
		j = down_animation(vars, vars->person.direction, j);
	if (vars->keypress == 1 && vars->keycode == KEY_W)
		j = up_animation(vars, vars->person.direction, j);
	return (1);
}
