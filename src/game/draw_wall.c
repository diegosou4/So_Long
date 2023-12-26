/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:14:29 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/23 15:14:31 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void    paint_floor(t_vars *vars, int sx, int sy)
{
     paintcanvaW(vars, &vars->floor , sx, sy, 64, 0, 64, 64);
}
void paint_exit(t_vars *vars, int sx, int sy)
{
        vars->door.curr_sx = sx;
        vars->door.curr_sy = sy;
        paintcanvaW(vars, &vars->door , vars->door.curr_sx , vars->door.curr_sy, 64, 0, 256, 64 );
}
void paint_coletables(t_vars *vars, int sx, int sy)
{
    paintcanvaW(vars, &vars->floor , sx, sy, 64, 0, 64, 64);
    paintcanvaW(vars, &vars->coletables , sx, sy, 32, 0, 32, 32);

}
void  paint_player(t_vars *vars, int sx, int sy)
{
    vars->person.curr_sx = sx;
    vars->person.curr_sy = sy;
    paintcanvaW(vars, &vars->floor , sx, sy, 64, 0, 64, 64);
    paintcanvaW(vars, &vars->person.img[0] ,vars->person.curr_sx, vars->person.curr_sy, 360, 320, width, heigth);

}

void draw_wall(t_map smapi, t_vars *vars)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < smapi.column)
    {
        j = 0;
        while(j < smapi.lenchar)
        {
            if(smapi.map[i][j] == '0')
                  paint_floor(vars, (j * 64),(i  * 64)) ;
            if(smapi.map[i][j] == 'E')
                paint_exit(vars,(j * 64), (i * 64));
            if(smapi.map[i][j] == '1')
                paintcanvaW(vars, &vars->walls , (j * 64), (i  * 64), 120, 0, 64, 64);
            if(smapi.map[i][j] == 'C')
                paint_coletables(vars,(j * 64), (i * 64));
            if(smapi.map[i][j] == 'P')
                paint_player(vars,(j * 64), (i * 64));
        j++;
        }
        i++;
    }
}


