/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:05:08 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/19 16:05:09 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void map_flags(char cmap, t_map *smap, int sy, int sx)
{
    if(cmap == 'C')
        smap->coletables[0] += 1;
    if(cmap == 'E')
    {
        smap->exit[0] += 1;
        smap->sx[1] = sx;
        smap->sy[1] = sy;
    }
    if(cmap == 'P')
    {
        smap->player += 1;
        smap->sx[0] = sx;
        smap->sy[0] = sy;
    }
}

int  map_walls(char *map)
{
    int sy;
    sy = 0;
    while(map[sy] != '\0')
    {
        if(map[sy] != '1')
            return(0);
    sy++;
    }
    return(sy);
}

int mid_wall(char **map, int len, int column)
{
    int sy;
    sy = 0;
    while (sy < column)
    {
        if(map[sy][0] != '1' || map[sy][len - 1] != '1')
            return(0);
        sy++;
    }
    return(1);
}

int check_charmap(t_map *smap)
{
    if(smap->coletables[0] != 0 && smap->exit[0] == 1 && smap->player == 1)
        return(1);
    else
        return(0);
}

int checkmap(char **map, int column,int len, t_map *smap)
{
    int sx;
    int sy;
    int fwall;

    sx = 0;
    fwall = map_walls(map[0]);
    sy = 0;
    while(sy < column - 1)
    {
        sx = 0;
        while(map[sy][sx] != '\0')
        {
           map_flags(map[sy][sx], smap,sy,sx);
            sx++;
        }
        sy++;
    }
    sy = map_walls(map[column - 1]);
    sx = mid_wall(map,len, column);
    if(fwall == 0 || sy == 0 || sx == 0)
        return(0);
    return(check_charmap(smap));
}





