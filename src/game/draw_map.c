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
  //  loadallimg(vars);
    printf("%i sx e sy %i \n", (smapi.sx[0] * 64), (smapi.sy[0] * 64));
    vars->person.img->curr_sx = ((smapi.sx[0] + 1) * 64);
    vars->person.img->curr_sy = ((smapi.sy[0] +1 )* 64);

}