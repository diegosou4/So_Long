/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:26:32 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/30 16:26:35 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	namemap(char *pathname)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = ft_strlen(pathname);
	if (i <= 4)
	{
		write(1, "Formato de mapa invalido\n", 25);
		return (0);
	}
	if (pathname[i - 1] == 'r')
		j = 1;
	if (pathname[i - 2] == 'e')
		j += 1;
	if (pathname[i - 3] == 'b')
		j += 1;
	if (pathname[i - 4] == '.')
		j += 1;
	if (j == 0)
		write(1, "Formato de mapa invalido\n", 25);
	return (j);
}
