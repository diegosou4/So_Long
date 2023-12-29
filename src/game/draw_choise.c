/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_choise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:27:58 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/28 15:28:04 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_wall(t_map smapi, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	
	while (i < smapi.column)
	{
		j = 0;
		while (j < smapi.lenchar)
		{
			if (smapi.map[i][j] == '0')
				paint(vars,&vars->assets[FLOOR], (j * 64), (i * 64));
			if (smapi.map[i][j] == '1')
				paint(vars,&vars->assets[WALLS], (j * 64), (i * 64));
			if (smapi.map[i][j] == 'C')
				paint(vars,&vars->assets[COIN] ,(j * 64) + 16, (i * 64) + 16);
			/*
			if (smapi.map[i][j] == 'E')
				paint_exit(vars, (j * 64), (i * 64));
	
			if (smapi.map[i][j] == 'P')
				paint_player(vars, (j * 64), (i * 64));
				*/
			j++;
			mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
		}
		i++;
	}
}
