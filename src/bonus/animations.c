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

#include "../../includes/so_long.h"

void    charstop(t_vars *vars)
{
    static int i;
   
    if(i == 0)
        i = 320;
    if(is_exit(vars,vars->curr_sx,vars->curr_sy) == 0)
        paint(vars, &vars->assets[FLOOR], vars->curr_sx - MIDDLE,  vars->curr_sy - MIDDLE);
    vars->assets[vars->pdirection].img.curr_sx = vars->curr_sx;
    vars->assets[vars->pdirection].img.curr_sy = vars->curr_sy;
    vars->assets[vars->pdirection].img.tamsprite = i + TAM_P;
    vars->assets[vars->pdirection].img.curr_sprite  = i;
    paint_canvaw(vars, &vars->assets[vars->pdirection].img, 400,40);
    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
    i += TAM_P;
    ft_usleep(TIME_ANIM * 4);
    if(i == 400)
        i = 0;
}


void	where_mov(t_vars *vars)
{
	if (vars->pdirection == 0)
		vars->curr_sx += 8;
	if (vars->pdirection == 1)  
		vars->curr_sx -= 8;
	if (vars->pdirection == 2)
		vars->curr_sy += 8;
	if (vars->pdirection == 3)
		vars->curr_sy -= 8;
}

void where_bonus(t_vars *vars)
{
    if (vars->pdirection == 0)
		vars->assets[FLOOR].img.curr_sx += 64;
	if (vars->pdirection == 1)  
		vars->assets[FLOOR].img.curr_sx -= 64;
	if (vars->pdirection == 2)
		vars->assets[FLOOR].img.curr_sy += 64;
	if (vars->pdirection == 3)
		vars->assets[FLOOR].img.curr_sy -= 64;

}

int is_exit(t_vars *vars, int sx, int sy)
{
    int i;
    int j;
    i = sx / 64;
    j = sy / 64;
    if(vars->game.map[j][i] == 'E')
    {
        vars->assets[DOOR].img.curr_sprite = 0;
		vars->assets[DOOR].img.tamsprite = 64;
		paint_canvaw(vars, &vars->assets[DOOR].img,256, 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->canva.img, 0, 0);
		count_move(vars);
        return(1);
    }
    else 
        return(0);
}
void paint_anim(t_vars *vars, int j)
{
    static int sx;
    static int sy;
    if(j == 0)
    {
        sx = vars->curr_sx - MIDDLE;
        sy = vars->curr_sy - MIDDLE;
    }
    if(is_exit(vars,sx,sy) == 0)
        paint(vars,&vars->assets[FLOOR],sx,sy);
    if(j >= 200)
    {
        vars->assets[FLOOR].img.curr_sx = sx;
        vars->assets[FLOOR].img.curr_sy = sy;
        where_bonus(vars);
    }
    if(is_exit(vars,vars->assets[FLOOR].img.curr_sx,vars->assets[FLOOR].img.curr_sy) == 0)
        paint(vars,&vars->assets[FLOOR],vars->assets[FLOOR].img.curr_sx,vars->assets[FLOOR].img.curr_sy);
    where_mov(vars);
    vars->assets[vars->pdirection].img.curr_sx = vars->curr_sx;
    vars->assets[vars->pdirection].img.curr_sy = vars->curr_sy;
    vars->assets[vars->pdirection].img.tamsprite = j + TAM_P;
    vars->assets[vars->pdirection].img.curr_sprite  = j;
	paint_canvaw(vars, &vars->assets[vars->pdirection].img, 400,40);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->canva.img, 0, 0);
}

void	mov(t_vars *vars)
{
    static int j;
    paint_anim(vars, j);
    j += TAM_P;

    ft_usleep(TIME_ANIM * 2);
    if(j == 320)
    {
        vars->curr_sx =  vars->assets[vars->pdirection].img.curr_sx;
        vars->curr_sy =  vars->assets[vars->pdirection].img.curr_sy;
        vars->keypress = 0;
        vars->keycode = 0;
        vars->nmov += 1;
        j = 0;
    }
    
}
