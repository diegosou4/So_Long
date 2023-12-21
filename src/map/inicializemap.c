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

void    init_smap(t_map *smap)
{
    int i;
    i = 0;
    while(i < 2)
    {
        smap->coletables[i] = 0;
        smap->exit[i] = 0;
      i++;
    }
         smap->player = 0;

}

