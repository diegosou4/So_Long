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
                 paintcanvaW(vars, &vars->floor , (j * 64), (i  * 64), 64, 0, 64, 64);
            if(smapi.map[i][j] == 'E')
            {   
                vars->door.curr_sx = (j * 64);
                vars->door.curr_sy = (i * 64);
               paintcanvaW(vars, &vars->door , vars->door.curr_sx , vars->door.curr_sy, 64, 0, 256, 64 );
            }
               
            if(smapi.map[i][j] == '1')
                paintcanvaW(vars, &vars->walls , (j * 64), (i  * 64), 120, 0, 64, 64);
            if(smapi.map[i][j] == 'C')
            {
                paintcanvaW(vars, &vars->floor , (j * 64), (i  * 64), 64, 0, 64, 64);
                paintcanvaW(vars, &vars->coletables , (j * 64), (i  * 64), 32, 0, 32, 32);
            }
               
        j++;
        }
        i++;
    }

}
