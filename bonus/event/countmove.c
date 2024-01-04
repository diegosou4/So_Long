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
	char	*p;

	p = ft_itoa(vars->nmov);
	mlx_string_put(vars->mlx, vars->win, 8, 20, 16777215, "Moviment:  ");
	mlx_string_put(vars->mlx, vars->win, 65, 20, 16777215, p);
	free(p);
}

int	destroy_game(t_vars *vars)
{
	write(1, "Jogo fechado\n", 13);
	exit_game(vars);
	return (1);
}
