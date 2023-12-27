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

void	loadallimg(t_vars *vars)
{
	vars->person.img[0] = load_img("img/character/R/Sprites.xpm", vars);
	vars->person.img[1] = load_img("img/character/L/Sprites.xpm", vars);
	vars->person.img[2] = load_img("img/character/D/Sprites.xpm", vars);
	vars->person.img[3] = load_img("img/character/U/Sprites.xpm", vars);
	vars->coletables = load_img("img/coletables/pilha.xpm", vars);
	vars->walls = load_img("img/walls/f.xpm", vars);
	vars->door = load_img("img/door/doors.xpm", vars);
	vars->floor = load_img("img/floor/floor.xpm", vars);
}
