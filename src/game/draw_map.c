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


void    draw_window(t_map smapi, t_vars *vars)
{
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, (smapi.lenchar * TAM_B),(smapi.column * TAM_B), "So_Long");
    vars->canva.img = mlx_new_image(vars->mlx,(smapi.lenchar * TAM_B),(smapi.column * TAM_B));
    vars->canva.addr = mlx_get_data_addr(vars->canva.img, &vars->canva.bits_per_pixel, &vars->canva.line_length,
								&vars->canva.endian);
    loadallimg(vars);
    vars->person.direction = 0;
    vars->keypress = 0;
    vars->person.curr_sx = (((smapi.sx[0]) + 1) * 64);
    vars->person.curr_sy = (((smapi.sy[0]) + 1)* 64);
    paintcanvaW(vars, &vars->person.img[0] ,vars->person.curr_sx, vars->person.curr_sy, 360, 320, width, heigth);

    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);

}