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

void	print_mov(int mov)
{
	write(1, "Movimentos:", 11);
	ft_putnbr(mov);
	write(1, "\n", 1);
}

void valuesforkey(t_vars *vars, int keycode)
{
	if(keycode == KEY_D || keycode == KEY_A || keycode == KEY_S ||
	keycode == KEY_W )
	{
		vars->keycode = keycode;
		vars->assets[FLOOR].img.curr_sx = vars->curr_sx;
		vars->assets[FLOOR].img.curr_sy = vars->curr_sy;
		vars->keypress = 1;
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
	valuesforkey(vars,keycode);
}

int	key_event(int keycode, t_vars *vars)
{
	if (keycode == ESC && vars->keypress == 0)
	{
		write(1,"Jogo fechado\n",13);
		exit_game(vars);
	}
	if (vars->keypress == 0)
		which_key(keycode, vars);
	if (is_wall(vars) == 0)
		vars->keypress = 0;
	return (0);
}

int	keynotpress(t_vars *vars)
{
	if(vars->keypress == 1)
		mov(vars,vars->pdirection);

	return (1);
}
