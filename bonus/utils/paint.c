/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:30:16 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/19 12:30:17 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	paint(t_vars *vars, t_assets *assets, int sx, int sy)
{
	assets->img.curr_sx = sx;
	assets->img.curr_sy = sy;
	assets->img.tamsprite = 64;
	assets->img.curr_sprite = 0;
	if (assets->img.img_width == 1200 && assets->img.img_height == 120)
	{
		vars->curr_sx = sx;
		vars->curr_sy = sy;
		assets->img.tamsprite = 360;
		assets->img.curr_sprite = 320;
		assets->img_width = 400;
		assets->img_height = 40;
	}
	paint_canvaw(vars, &assets->img, assets->img_width, assets->img_height);
}

void	paintcanva(t_vars *varg, t_img *img, int sx, int sy)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			my_mlx_pixel_put(&varg->canva, sx + x, sy + y, my_mlx_pixel_get(img,
					x, y));
			x++;
		}
		y++;
	}
}

void	paint_canvaw(t_vars *varg, t_img *img, float w, float h)
{
	float	x;
	float	y;
	int		k;
	int		j;
	t_vars	*p;

	k = 0;
	y = 0;
	w = (img->img_width) / w;
	h = (img->img_height) / h;
	p = varg;
	while (y < img->img_height)
	{
		j = 0;
		x = img->curr_sprite * w;
		while (x < img->img_width && (j + img->curr_sprite) < img->tamsprite)
		{
			my_mlx_pixel_put(&p->canva, (img->curr_sx + j), (img->curr_sy + k),
				(my_mlx_pixel_get(img, (int)x, (int)y)));
			x += w;
			j++;
		}
		k++;
		y += h;
	}
}
