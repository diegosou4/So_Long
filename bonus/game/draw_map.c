/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:40:10 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/21 14:40:12 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	case_map(char map, t_vars *vars, int i, int j)
{
	if (map == '0' || map == 'C' || map == 'P')
		paint(vars, &vars->assets[FLOOR], (j * 64), (i * 64));
	if (map == 'C')
		paint(vars, &vars->assets[COIN], (j * 64) + MIDDLE, (i * 64) + MIDDLE);
	if (map == 'P')
		paint(vars, &vars->assets[CHAR_R], (j * 64) + MIDDLE, (i * 64)
			+ MIDDLE);
	if (map == '1')
		paint(vars, &vars->assets[WALLS], (j * 64), (i * 64));
	if (map == 'E')
		paint(vars, &vars->assets[DOOR], (j * 64), (i * 64));
}

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
			case_map(smapi.map[i][j], vars, i, j);
			j++;
		}
		i++;
	}
}

int	draw_window(t_map smapi, t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (smapi.lenchar * TAM_B), (smapi.column
				* TAM_B), "So_Long");
	vars->canva.img = mlx_new_image(vars->mlx, (smapi.lenchar * TAM_B),
			(smapi.column * TAM_B));
	vars->canva.addr = mlx_get_data_addr(vars->canva.img,
			&vars->canva.bits_per_pixel,
			&vars->canva.line_length,
			&vars->canva.endian);
	loadallimg(vars);
	vars->pdirection = 0;
	vars->keypress = 0;
	return (vars->numassets);
}
