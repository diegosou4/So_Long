/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:31:15 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/19 12:31:16 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	valuesforkey(t_vars *vars, int keycode)
{
	if (keycode == KEY_D || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_W)
	{
		vars->keycode = keycode;
	}
}

void	which_key(int keycode, t_vars *vars)
{
	if (keycode == KEY_D)
		vars->pdirection = 0;
	if (keycode == KEY_A)
		vars->pdirection = 1;
	if (keycode == KEY_S)
		vars->pdirection = 2;
	if (keycode == KEY_W)
		vars->pdirection = 3;
	valuesforkey(vars, keycode);
}

void	diff_key(t_vars *vars)
{
	if (vars->keycode != ESC && vars->keycode != KEY_D && vars->keycode != KEY_A
		&& vars->keycode != KEY_S && vars->keycode != KEY_D
		&& vars->keycode != KEY_W)
	{
		vars->keypress = 0;
	}
}

int	key_event(int keycode, t_vars *vars)
{
	if (vars->game.coletables[1] == 0)
	{
		vars->assets[DOOR].img.curr_sprite = 192;
		vars->assets[DOOR].img.tamsprite = 256;
		paint_canvaw(vars, &vars->assets[DOOR].img,
			vars->assets[DOOR].img.tamsprite, 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->canva.img, 0, 0);
		count_move(vars);
	}
	if (keycode == ESC && vars->keypress == 0)
	{
		write(1, "Jogo fechado\n", 13);
		exit_game(vars);
	}
	if (vars->keypress == 0)
	{
		which_key(keycode, vars);
		if (is_wall(vars) == 0)
			vars->keypress = 0;
		else
			vars->keypress = 1;
	}
	if (vars->keypress == 1)
		diff_key(vars);
	return (0);
}

int	keynotpress(t_vars *vars)
{
	count_move(vars);
	if (vars->keypress == 0)
		charstop(vars);
	if (vars->keypress == 1 && vars->keycode != 0)
	{
		mov(vars);
	}
	count_move(vars);
	return (1);
}
