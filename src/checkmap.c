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


int    put_map(t_map *s_map, char **map, int column)
{
    int j;
    int i;
    int k;
    k = 0;
    i  = 0;
    while(i < column)
    {
        j = 0;
        while(map[i][j] != '\0')
        {
            s_map->mapins[k].value = map[i][j];
            s_map->mapins[k].sx = i;
            s_map->mapins[k].sy = j;
            k++;
            j++;
        }
        i++;
    }

}


int checkmap(char **map, int column,int len, t_map *smap)
{
    int j;put_map(t_map *s_map, char **map)
    while(map[0][j] != '\0')
    {
        if(map[0][j] != '1')
            return(0);
        j++;
    }
    while(i < column - 1)
    {
        j = 0;
        while(map[i][j] != '\0')
        {
            if(map[i][j] == 'C')
                smap->coletables += 1;
            if(map[i][j] == 'E')
                smap->exit += 1;
            if(map[i][j] == 'P')
                smap->player += 1;
            j++;
        }
        i++;
    }
    j = 0;
    while(map[column - 1][j] != '\0')
    {
        if(map[column - 1][j] != '1')
            return(0);
        j++;
    }
    put_map(smap, map, column);
    return(1);
}




