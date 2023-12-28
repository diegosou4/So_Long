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
        i = TAM_P * 8;
    paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , i + TAM_P, i, width, heigth);
    paintcanva(vars,&vars->img,0,0);

   
    paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , i + TAM_P, i, width, heigth);
    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
    i += TAM_P;
    if(i == 400)
        i = 0;
     usleep(200000);
     return  (i);
}

int right_animation(t_vars *vars, int d, int j)
{
   if(j >= 320)
            j = 0;
    paint_floor(vars,vars->floor.curr_sx, vars->floor.curr_sy);
    vars->person.curr_sx += 8;
    paintcanva(vars,&vars->img,0,0);
    paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , (j + TAM_P), (j), width, heigth);
    j += TAM_P;
   
    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
    ft_usleep(100000 * 200);
    if(j >= 320)
    {
        vars->keycode = 0;
        vars->keypress = 0;
        vars->person.moviment += 1;
    }
    return  (j);
}

int left_animation(t_vars *vars, int d, int j)
{
    if(j == 0)
        j = 320;
    paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , (j + TAM_P) , j, width, heigth);
    vars->person.curr_sx -= 8;
    paintcanva(vars,&vars->img,0,0);
    paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , (j + TAM_P), (j), width, heigth);
    j -= TAM_P;
    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
    ft_usleep(100000 * 200);
    if(j == 0)
    {
        vars->keypress = 0;
        vars->person.moviment += 1;
    }
    return  (j);
}

int up_animation(t_vars *vars, int d, int j)
{
        if(j == 0)
            j = TAM_P * 8;
        paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , (j + TAM_P) , j, width, heigth);
        vars->person.curr_sy -= 8;
        paintcanva(vars,&vars->img,0,0);
        paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , (j + TAM_P), (j), width, heigth);
        j -= TAM_P;
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
        ft_usleep(100000 * 200);
        if(j == 0)
        {
              vars->keypress = 0;
              vars->person.moviment += 1;
        }
        return  (j);
}
int down_animation(t_vars *vars, int d, int j)
{
        if(j == 0)
            j = TAM_P * 8;
        paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , (j + TAM_P) , j, width, heigth);
        vars->person.curr_sy += 8;
        paintcanva(vars,&vars->img,0,0);
        paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , (j + TAM_P), (j), width, heigth);
        j -= TAM_P;
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
        ft_usleep(100000 * 200);
        if(j == 0)
        {
              vars->keypress = 0;
              vars->person.moviment += 1;
        } 
        return  (j);
}
