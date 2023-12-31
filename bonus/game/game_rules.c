/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:23:54 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/23 18:23:56 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	locale_sx(t_vars *vars, int i)
{
	i = (vars->curr_sx / 64);
	if (vars->pdirection == 0)
	{
		i = (vars->curr_sx + 64) / 64;
	}
	if (vars->pdirection == 1)
	{
		i = (vars->curr_sx - 64) / 64;
	}
	return (i);
}

int	locale_sy(t_vars *vars, int j)
{
	j = (vars->curr_sy / 64);
	if (vars->pdirection == 2)
		j = (vars->curr_sy + 64) / 64;
	if (vars->pdirection == 3)
		j = (vars->curr_sy - 64) / 64;
	return (j);
}

int	is_wall(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = locale_sx(vars, i);
	j = locale_sy(vars, j);
	if (vars->game.map[j][i] == '1')
		return (0);
	if (vars->game.map[j][i] == 'C')
	{
		vars->game.map[j][i] = '0';
		vars->game.coletables[1] -= 1;
	}
	if (vars->game.map[j][i] == 'E' && vars->game.coletables[1] == 0)
	{
		write(1, "Parabens meu nobre voce ganhou \n", 33);
		exit_game(vars);
	}
	return (1);
}
