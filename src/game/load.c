/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:30:07 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/19 12:30:09 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_img	load_img(char *path, t_vars *varg)
{
	t_img	img;

	img.relative_path = path;
	img.img = mlx_xpm_file_to_image(varg->mlx, img.relative_path,
			&img.img_width, &img.img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}

void 	givevalues(t_assets *assets, int img_with, int img_height)
{
	assets->img_width = img_with;
	assets->img_height = img_height;
}

void	loadallimg(t_vars *vars)
{
	vars->assets = New (Class * 8);
	vars->numassets = 8;
	int i;
	if(!vars->assets)
	{	
		vars->numassets = 0;
		return;
	}
	i = 0;
	vars->assets[0].img =  load_img("img/character/R/Sprites.xpm", vars);
	vars->assets[1].img =  load_img("img/character/L/Sprites.xpm", vars);
	vars->assets[2].img =  load_img("img/character/D/Sprites.xpm", vars);
	vars->assets[3].img =  load_img("img/character/U/Sprites.xpm", vars);
	vars->assets[4].img =  load_img("img/coletables/pilha.xpm", vars);
	vars->assets[5].img =  load_img("img/walls/f.xpm", vars);
	vars->assets[6].img =  load_img("img/door/doors.xpm", vars);
	vars->assets[7].img =  load_img("img/floor/floor.xpm", vars);
	givevalues(&vars->assets[COIN],32,32 );
	givevalues(&vars->assets[WALLS],64,64);
	givevalues(&vars->assets[FLOOR],64,64);
	givevalues(&vars->assets[DOOR],256,64);
	while(i < 4)
	{
		givevalues(&vars->assets[i],400,40);
		i++;
	}
}
