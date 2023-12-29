/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:13:45 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/27 14:13:51 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


void where_mov(t_vars *vars,int direction)
{
	if(direction == 0)
		vars->curr_sx += 64;
	if(direction == 1)
		vars->curr_sx -= 64;
	if(direction == 2)
		vars->curr_sy -= 64;
	if(direction == 3)
		vars->curr_sy += 64;
}

void mov(t_vars *vars, int direction)
{
	paint(vars,&vars->assets[FLOOR],vars->curr_sx - 16,vars->curr_sy - 16);
	printf("%i direction \n", direction);
	where_mov(vars,direction);
	paint(vars,&vars->assets[direction],vars->curr_sx,vars->curr_sy);	
	mlx_put_image_to_window(vars->mlx, vars->win, vars->canva.img, 0, 0);
	vars->keypress = 0;
	vars->keycode = 0;
	vars->pmoviment += 1;
	print_mov(vars);
}

