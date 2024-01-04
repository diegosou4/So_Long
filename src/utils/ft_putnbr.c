/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:56:00 by diegmore          #+#    #+#             */
/*   Updated: 2023/10/16 22:27:55 by diemorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	ft_countwordls(int n)
{
	int	wordls;

	wordls = 0;
	if (n < 0)
	{
		wordls++;
		n *= -1;
	}
	if (n == 0)
		wordls++;
	while (n != 0)
	{
		n = n / 10;
		wordls++;
	}
	return (wordls);
}

void	ft_putnbr(int n)
{
	int	i;
	int	worlds;

	worlds = 0;
	i = 0;
	worlds = ft_countwordls(n);
	if (n > 9)
	{
		i = i + (n % 10);
		ft_putnbr(n / 10);
		i = i + '0';
		write(1, &i, 1);
		return ;
	}
	else
	{
		n += '0';
		write(1, &n, 1);
	}
}
