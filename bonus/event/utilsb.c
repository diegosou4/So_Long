/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:30:42 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/19 12:30:44 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	ft_countwordls(unsigned int n)
{
	int	wordls;

	wordls = 0;
	if (n == 0)
		wordls++;
	while (n != 0)
	{
		n = n / 10;
		wordls++;
	}
	return (wordls);
}

static char	*ft_putintchar(unsigned int n, char *str, size_t len, int negative)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		str[0] = '0';
	}
	while (n != 0)
	{
		i = n % 10;
		str[len] = i + '0';
		n = n / 10;
		len--;
	}
	if (negative == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len_str;
	int				negative;
	unsigned int	num;

	num = n;
	len_str = 0;
	negative = 0;
	if (n < 0)
	{
		negative = 1;
		len_str = 1;
		num *= -1;
	}
	len_str += (ft_countwordls(num) + 1);
	str = (char *)malloc(len_str * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_putintchar(num, str, (len_str - 2), negative);
	str[len_str - 1] = '\0';
	return (str);
}

void	update_p(t_vars *vars, int j)
{
	vars->assets[vars->pdirection].img.curr_sx = vars->curr_sx;
	vars->assets[vars->pdirection].img.curr_sy = vars->curr_sy;
	vars->assets[vars->pdirection].img.tamsprite = j + TAM_P;
	vars->assets[vars->pdirection].img.curr_sprite = j;
}

int	is_exit(t_vars *vars, int sx, int sy)
{
	int	i;
	int	j;

	i = sx / 64;
	j = sy / 64;
	if (vars->game.map[j][i] == 'E')
	{
		vars->assets[DOOR].img.curr_sprite = 0;
		vars->assets[DOOR].img.tamsprite = 64;
		paint_canvaw(vars, &vars->assets[DOOR].img, 256, 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->canva.img, 0, 0);
		count_move(vars);
		return (1);
	}
	else
		return (0);
}
