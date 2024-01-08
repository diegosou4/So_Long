/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:30:25 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/19 12:30:27 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	read_map(char *map, t_map *smap)
{
	int		fd;
	char	*str;
	int		i;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Ocorreu um Erro ao abrir o mapa\n", 33);
		write(1, "Verifique se o Arquivo existe \n", 32);
		return (0);
	}
	else
	{
		str = open_read(fd);
	}
	i = validate_map(str, smap);
	free(str);
	close(fd);
	return (i);
}

int	validate_map(char *str, t_map *smap)
{
	int	i;

	smap->lenchar = len_map(str);
	smap->column = validate_map2(str, smap->lenchar);
	if (smap->column < 3 || smap->lenchar < 3)
		return (print_e());
	smap->map = ft_split(str, '\n', smap->lenchar, smap->column);
	smap->cpymap = ft_split(str, '\n', smap->lenchar, smap->column);
	init_smap(smap);
	i = checkmap(smap->map, smap->column, smap->lenchar, smap);
	if (i == 0)
		return (print_error(smap, smap->column, 0));
	i = values_strongmap(smap->map);
	if (i == 0)
		return (print_error(smap, smap->column, 0));
	flood_fill(smap->sy[0], smap->sx[0], smap);
	i = end_valid(smap);
	if (i == 0)
		return (print_error(smap, smap->column, 0));
	return (print_d());
}

int	validate_map2(char *str, int len)
{
	int	line_len;
	int	i;
	int	column;

	column = 0;
	i = 0;
	while (str && str[i] != '\0')
	{
		line_len = 0;
		while (str && str[i] != '\n' && str[i] != '\0')
		{
			line_len++;
			i++;
		}
		if (line_len != len)
			return (0);
		if (str[i] == '\n')
			column++;
		if (str[i] == '\0')
			break ;
		i++;
	}
	column++;
	return (column);
}

void	flood_fill(int sy, int sx, t_map *smap)
{
	if (smap->cpymap[sy][sx] == '1' || smap->cpymap[sy][sx] == '3')
		return ;
	if (smap->cpymap[sy][sx] == 'C')
		smap->coletables[1] += 1;
	if (smap->cpymap[sy][sx] == 'E')
		smap->exit[1] += 1;
	smap->cpymap[sy][sx] = '3';
	flood_fill(sy + 1, sx, smap);
	flood_fill(sy - 1, sx, smap);
	flood_fill(sy, sx + 1, smap);
	flood_fill(sy, sx - 1, smap);
}
