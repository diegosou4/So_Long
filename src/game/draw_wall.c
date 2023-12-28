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

void	paint_floor(t_vars *vars, int sx, int sy)
{
	vars->floor.curr_sx = sx;
	vars->floor.curr_sy = sy;
	vars->floor.tamsprite = 64;
	vars->floor.curr_sprite = 0;
	paint_canvaw(vars,&vars->floor, 64,64);
}

void	paint_exit(t_vars *vars, int sx, int sy)
{
	vars->door.curr_sx = sx;
	vars->door.curr_sy = sy;
	vars->door.tamsprite = 64;
	vars->door.curr_sprite = 0;
	paint_canvaw(vars,&vars->door,256,64);
}

void	paint_coletables(t_vars *vars, int sx, int sy)
{
	vars->coletables.curr_sx = sx;
	vars->coletables.curr_sy = sy;
	vars->coletables.tamsprite = 32;
	vars->coletables.curr_sprite = 0;
	paint_floor(vars,sx,sy);
	paint_canvaw(vars,&vars->coletables,32,32);
}

void	paint_player(t_vars *vars, int sx, int sy)
{
	int i;
	i = 0;

	vars->person.img[0].curr_sx = sx;
	vars->person.img[0].curr_sy = sy;
	vars->person.curr_sx = sx;
	vars->person.curr_sy = sy;
	while(i < 4)
	{
			vars->person.img[i].tamsprite = 360;
			vars->person.img[i].curr_sprite = 320;
			i++;
	}
	paint_floor(vars,sx,sy);
	paint_canvaw(vars,&vars->person.img[0],width,heigth);
}
void  paint_wall(t_vars *vars, int sx, int sy)
{
	vars->walls.curr_sx = sx;
	vars->walls.curr_sy = sy;
	vars->walls.tamsprite = 120;
	vars->walls.curr_sprite = 0;
	paint_canvaw(vars,&vars->walls,64,64);

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
			if (smapi.map[i][j] == '0')
				paint_floor(vars, (j * 64), (i * 64));
			if (smapi.map[i][j] == 'E')
				paint_exit(vars, (j * 64), (i * 64));
			if (smapi.map[i][j] == '1')
				paint_wall(vars,(j * 64), (i * 64));
			if (smapi.map[i][j] == 'C')
				paint_coletables(vars, (j * 64), (i * 64));
			if (smapi.map[i][j] == 'P')
				paint_player(vars, (j * 64), (i * 64));
			j++;
		}
		i++;
	}
}
