/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:31:21 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/19 12:31:22 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ftjoinmap2(char *str, char *buffer, char *new_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str)
	{
		new_str[i] = str[i];
		i++;
	}
	while (buffer[j] && buffer)
	{
		new_str[i + j] = buffer[j];
		j++;
	}
	new_str[i + j] = '\0';
}

char	*ftjoinmap(char *str, char *buffer)
{
	char	*new_str;
	int		len_s;
	int		len_b;

	len_s = ft_strlen(str);
	len_b = ft_strlen(buffer);
	if (!str)
	{
		new_str = (char *)malloc(sizeof(char) * (len_b + 1));
		joinmap(new_str, buffer);
		return (new_str);
	}
	new_str = (char *)malloc(sizeof(char) * (len_s + len_b + 1));
	if (new_str == NULL)
	{
		free(buffer);
		free(str);
		return (NULL);
	}
	ftjoinmap2(str, buffer, new_str);
	free(buffer);
	free(str);
	return (new_str);
}

char	*joinmap(char *new_str, char *buffer)
{
	int	j;

	j = 0;
	while (buffer[j] != '\0')
	{
		new_str[j] = buffer[j];
		j++;
	}
	new_str[j] = '\0';
	free(buffer);
	return (new_str);
}

int	values_strongmap(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && 
				map[i][j] != 'C' && map[i][j] != 'E'
				&& map[i][j] != 'P')
			{
				write(1, "Algum valor inserido no mapa e invalido\n", 40);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
