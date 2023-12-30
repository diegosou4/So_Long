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

	if(assets->img.img_width == 1200 && assets->img.img_height == 120)
	{
		vars->curr_sx = sx;
		vars->curr_sy = sy;
		vars->keypress = 0;
		assets->img.tamsprite = 360;
		assets->img.curr_sprite = 320;
		assets->img_width = 400;
		assets->img_height = 40;
	}
	paint_canvaw(vars, &assets->img, assets->img_width, assets->img_height);
}
