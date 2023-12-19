/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:30:32 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/19 12:30:33 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/so_long.h"


static int	ft_numberchar(char *s, char sep)
{
	int	i;
	int	numberchar;

	numberchar = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == sep && s[i])
			i++;
		while (s[i] != sep && s[i])
		{
			i++;
			numberchar++;
		}
		if (s[i] == sep)
			return (numberchar);
	}
	return (numberchar);
}

static int	ft_givestring(char *s, char sep, char *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == sep && s[i])
			i++;
		while (s[i] != sep && s[i])
		{
			dest[j] = s[i];
			i++;
			j++;
		}
		if (s[i] == sep)
		{
			dest[j] = '\0';
			return (i);
		}
			
	}
	dest[j] = '\0';
	return (i);
}

static void	*free_malloc(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c, int len, int column)
{
    char	**str;
    int		i;
    int		k;
    int		p;

    if (!s)
        return (0);
    p = 0;
    k = 0;
    i = 0;
    str = (char **) malloc ((column + 1)* sizeof(char *));
    if (!str)
        return (0);
    while (i < column)
    {
        str[i] = (char *)malloc ((len + 1 ) *
                sizeof(char));
        if (!str[i])
            return (free_malloc(str, i - 1 ));
        k = ft_givestring((char *)(s + p), c, str[i]);	
		p = p + k;
        i++;
    }
    str[column] = NULL;
    return (str);
}
