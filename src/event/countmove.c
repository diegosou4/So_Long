/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:29:55 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/19 12:29:57 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	count_move(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 8, 20, 16777215, "Moviment:  ");
	mlx_string_put(vars->mlx, vars->win, 65, 20, 16777215,
		ft_itoa(vars->person.moviment));
}
