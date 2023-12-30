/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:31:15 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/19 12:31:16 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int key_event(int keycode, t_vars *vars)
{
    if(keycode == ESC && vars->keypress == 0)
        exit_game(vars);
    if (vars->game.coletables[1] == 0)
	{
		vars->door.tamsprite = 256;
		vars->door.curr_sprite = 192;
		paint_canvaw(vars, &vars->door, 256, 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->canva.img, 0, 0);
	}
    if(keycode == KEY_D && vars->keypress == 0)
    {
        vars->keycode = KEY_D;
        vars->person.direction = 0;
        vars->keypress = 1;
        vars->floor.curr_sx = vars->person.curr_sx;
        vars->floor.curr_sy = vars->person.curr_sy;
       
    }
    if(keycode == KEY_A && vars->keypress == 0)
    {
        vars->keycode = KEY_A;
        vars->person.direction = 1;
        vars->keypress = 1;
        vars->floor.curr_sx = vars->person.curr_sx;
        vars->floor.curr_sy = vars->person.curr_sy;
    }
     if(keycode == KEY_S && vars->keypress == 0)
    {
        vars->keycode = KEY_S;
        vars->person.direction = 2;
        vars->keypress = 1;
        vars->floor.curr_sx = vars->person.curr_sx;
        vars->floor.curr_sy = vars->person.curr_sy;
    }
    if(keycode == KEY_W && vars->keypress == 0)
    {
        vars->keycode = KEY_W;
        vars->person.direction = 3;
        vars->keypress = 1;
        vars->floor.curr_sx = vars->person.curr_sx;
        vars->floor.curr_sy = vars->person.curr_sy;
    }
    if(is_wall(vars) == 0 && vars->keypress == 1)
    {
        vars->keypress = 0;
    }
    return(0);
}


int     keynotpress(t_vars *vars)
{
    static int j;
    static int i;
    if(vars->keypress == 0)
        i = charstop(vars, vars->person.direction, i); 
    if(vars->keypress == 1 && vars->keycode == KEY_D)
        j = right_animation(vars, vars->person.direction , j);
    if(vars->keypress == 1 && vars->keycode == KEY_A)
        j = left_animation(vars, vars->person.direction , j);
    if(vars->keypress == 1 && vars->keycode == KEY_S)
        j = down_animation(vars, vars->person.direction , j);
    if(vars->keypress == 1 && vars->keycode == KEY_W)
        j = up_animation(vars, vars->person.direction , j);
    return(1);
}
