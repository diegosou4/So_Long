/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:14:29 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/23 15:14:31 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	paint(t_vars *vars,t_assets *assets, int sx, int sy)
{
	assets->img.curr_sx = sx;
	assets->img.curr_sy = sy;
	assets->img.tamsprite = 64;
	assets->img.curr_sprite = 0;
	paint_canvaw(vars, &assets->img, assets->img_width, assets->img_height);
}
/*
void	paint_exit(t_vars *vars, int sx, int sy)
{
	vars->door.curr_sx = sx;
	vars->door.curr_sy = sy;
	vars->door.tamsprite = 64;
	vars->door.curr_sprite = 0;
	paint_canvaw(vars, &vars->door, 256, 64);
}

void	paint_coletables(t_vars *vars, int sx, int sy)
{
	vars->coletables.curr_sx = sx + 16;
	vars->coletables.curr_sy = sy + 10;
	vars->coletables.tamsprite = 32;
	vars->coletables.curr_sprite = 0;
	paint_floor(vars, sx, sy);
	paint_canvaw(vars, &vars->coletables, 32, 32);
}

void	paint_player(t_vars *vars, int sx, int sy)
{
	int	i;

	i = 0;
	vars->person.img[0].curr_sx = sx + 16;
	vars->person.img[0].curr_sy = sy + 10;
	vars->person.curr_sx = sx;
	vars->person.curr_sy = sy;
	while (i < 4)
	{
		vars->person.img[i].tamsprite = 360;
		vars->person.img[i].curr_sprite = 320;
		i++;
	}
	paint_floor(vars, sx, sy);
	paint_canvaw(vars, &vars->person.img[0], width, heigth);
}
*/