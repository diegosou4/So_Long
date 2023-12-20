/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicializemap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:05:15 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/19 18:05:17 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void    init_smap(t_map *smap, char **map)
{
    int i;
    int j;
    int k;
    i = 0;
    j = 0;
    k = 0;
    smap->map = map;
    smap->coletables = 0;
    smap->exit = 0;
    smap->player = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j] != '\0')
        {
        j++;
        k++;
        }
        i++;
    }
    smap->mapins = malloc(sizeof(smap->mapins) * k);
}

