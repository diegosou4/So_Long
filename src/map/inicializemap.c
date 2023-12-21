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
    smap->coletables = 0;
    smap->exit = 0;
    smap->player = 0;
    smap->direction = 'D';
}

