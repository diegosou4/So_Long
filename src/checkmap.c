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

#include "../includes/so_long.h"

void map_flags(char cmap, t_map *smap)
{
    if(cmap == 'C')
        smap->coletables += 1;
    if(cmap == 'E')
        smap->exit += 1;
    if(cmap == 'P')
        smap->player += 1;

}

int  map_walls(char *map)
{
    int i;
    i = 0;
    while(map[i] != '\0')
    {
        if(map[i] != '1')
            return(0);
    i++;
    }
    return(i);
}
int checkmap(char **map, int column,int len, t_map *smap)
{
    int j;
    int i;
    int fwall;

    j = 0;
    fwall = map_walls(map[0]);
    i = 0;
    while(i < column - 1)
    {
        j = 0;
        while(map[i][j] != '\0')
        {
           map_flags(map[i][j], smap);
            j++;
        }
        i++;
    }
    i = map_walls(map[column - 1]);
    if(fwall == 0 || i == 0)
        return(0);
    return(1);
}





