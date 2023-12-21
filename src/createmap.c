/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:31:05 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/19 12:31:06 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int end_valid(t_map smap)
{
    if(smap.coletables[0] == smap.coletables[1] 
        && smap.exit[0] == smap.exit[1]
    )
        return(1);
    else
    {
        return(0);
    }


}