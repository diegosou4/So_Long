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
	ft_putnbr(vars->pmoviment);
	write(1, "\n", 1);
}

void	which_key(int keycode, t_vars *vars)
{
	if (keycode == KEY_D && vars->keypress == 0)
	{
		vars->keycode = KEY_D;
		vars->pdirection = 0;
		vars->keypress = 1;
		vars->assets[FLOOR].img.curr_sx = vars->curr_sx;
		vars->assets[FLOOR].img.curr_sy = vars->curr_sy;
	}
	if (keycode == KEY_A && vars->keypress == 0)
	{
		vars->keycode = KEY_A;
		vars->pdirection = 1;
		vars->keypress = 1;
	}
	if (keycode == KEY_S && vars->keypress == 0)
	{
		vars->keycode = KEY_S;
		vars->pdirection = 2;
		vars->keypress = 1;
	}
	if (keycode == KEY_W && vars->keypress == 0)
	{
		vars->keycode = KEY_W;
		vars->pdirection = 3;
		vars->keypress = 1;
	}
}

int	key_event(int keycode, t_vars *vars)
{
	/*
	if (keycode == ESC && vars->keypress == 0)
	{
		write(1,"Jogo fechado\n",13);
		exit_game(vars);
	}*/
	if (vars->keypress == 0)
		which_key(keycode, vars);
	/*
	if (is_wall(vars) == 0)
		vars->keypress = 0;
	*/
	return (0);
}

int	keynotpress(t_vars *vars)
{
	int j;
	j = 360;
	if(vars->keypress == 1 && vars->keycode == KEY_D)
		mov(vars,0);
	if(vars->keypress == 1 && vars->keycode == KEY_A)
		mov(vars,1);
	if(vars->keypress == 1 && vars->keycode == KEY_S)
		mov(vars,2);
	if(vars->keypress == 1 && vars->keycode == KEY_W)
		mov(vars,3);
	return (1);
}
