/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:29:36 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/19 12:29:38 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



int    charstop(t_vars *vars, int d, int i)
{
    if(i == 0)
        i = 320;
    paint_floor(vars, vars->person.curr_sx, vars->person.curr_sy);
    vars->person.img[d].tamsprite = i + TAM_P;
    vars->person.img[d].curr_sprite = i;
    paint_canvaw(vars, &vars->person.img[d], width, heigth);
    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
    i += TAM_P;
    ft_usleep(TIME_ANIM * 3);
    if(i == 400)
        i = 0;
     return  (i);
}

int right_animation(t_vars *vars, int j)
{
   if(j >= 320)
            j = 0;
    paint_floor(vars,vars->floor.curr_sx , vars->floor.curr_sy);
    vars->person.curr_sx += 8;
    vars->person.img[d].curr_sx = vars->person.curr_sx + 16;
	vars->person.img[d].curr_sy = vars->person.curr_sy + 10;
    vars->person.img[d].tamsprite = j + TAM_P;
    vars->person.img[d].curr_sprite = j;
    paint_flooranimated(vars,&vars->floor,(vars->floor.curr_sx + 64),vars->floor.curr_sy);
    paint_canvaw(vars, &vars->person.img[d] ,width, heigth);
    j += TAM_P;
    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
    ft_usleep(100000 * 200);
    if(j >= 320)
    {
        vars->keycode = 0;
        vars->keypress = 0;
        vars->person.moviment += 1;
        j = 0;
    }
    return  (j);
}

int left_animation(t_vars *vars, int d, int j)
{
    if(j == 0)
        j = 320;
    paint_floor(vars,vars->floor.curr_sx , vars->floor.curr_sy);
    vars->person.curr_sx -= 8;
    vars->person.img[d].curr_sx = vars->person.curr_sx + 16;
	vars->person.img[d].curr_sy = vars->person.curr_sy + 10;
    vars->person.img[d].tamsprite = j + TAM_P;
    vars->person.img[d].curr_sprite = j;
    paint_flooranimated(vars,&vars->floor,(vars->floor.curr_sx - 64),vars->floor.curr_sy);
    paint_canvaw(vars, &vars->person.img[d] ,width, heigth);
    j -= TAM_P;
    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
    ft_usleep(TIME_ANIM);
    if(j == 0)
    {
        vars->keycode = 0;
        vars->keypress = 0;
        vars->person.moviment += 1;
    }
    return  (j);
}

int up_animation(t_vars *vars, int d, int j)
{
    if(j == 0)
        j = 320;
    paint_floor(vars,vars->floor.curr_sx , vars->floor.curr_sy);
    vars->person.curr_sy -= 8;
    vars->person.img[d].curr_sx = vars->person.curr_sx + 16;
	vars->person.img[d].curr_sy = vars->person.curr_sy + 10;
    vars->person.img[d].tamsprite = j + TAM_P;
    vars->person.img[d].curr_sprite = j;
    paint_flooranimated(vars,&vars->floor,vars->floor.curr_sx,(vars->floor.curr_sy - 64));
    paint_canvaw(vars, &vars->person.img[d] ,width, heigth);
    j -= TAM_P;
    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
    ft_usleep(TIME_ANIM);
    if(j == 0)
    {
        vars->keycode = 0;
        vars->keypress = 0;
        vars->person.moviment += 1;
    }
    return  (j);
}
int down_animation(t_vars *vars, int d, int j)
{
        if(j == 0)
            j = 320;
        paint_floor(vars,vars->floor.curr_sx , vars->floor.curr_sy);
        vars->person.curr_sy += 8;
        vars->person.img[d].curr_sx = vars->person.curr_sx + 16;
	    vars->person.img[d].curr_sy = vars->person.curr_sy + 10;
        vars->person.img[d].tamsprite = j + TAM_P;
        vars->person.img[d].curr_sprite = j;
        paint_flooranimated(vars,&vars->floor,vars->floor.curr_sx,(vars->floor.curr_sy + 64));
        paint_canvaw(vars, &vars->person.img[d] ,width, heigth);
        j -= TAM_P;
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
        ft_usleep(TIME_ANIM);
        if(j == 0)
        {
            vars->keycode = 0;
            vars->keypress = 0;
            vars->person.moviment += 1;
        } 
        return  (j);
}


