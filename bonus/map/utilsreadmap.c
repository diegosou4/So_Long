/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsreadmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:10:39 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/27 14:10:42 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	len_map(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*open_read(int fd)
{
	char	*buffer;
	int		sizestr;
	char	*str;

	sizestr = 1;
	str = NULL;
	while (sizestr != 0)
	{
		buffer = get_next_line(fd);
		sizestr = ft_strlen(buffer);
		if (sizestr == 0)
		{
			free(buffer);
			break ;
		}
		str = ftjoinmap(str, buffer);
	}
	return (str);
}

int	print_error(t_map *smap, int column, int i)
{
	while (column > 0)
	{
		column--;
		free(smap->map[column]);
		free(smap->cpymap[column]);
	}
	free(smap->map);
	free(smap->cpymap);
	write(1, "Mapa Invalido\n", 15);
	if (i == 1)
		write(1, "Mapa muito grande\n", 19);
	return (0);
}

int	print_e(void)
{
	write(1, "Mapa Invalido\n", 15);
	return (0);
}

int	print_d(void)
{
	write(1, "Mapa carregado com sucesso ;) bom jogo \n", 41);
	return (1);
}
