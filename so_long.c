/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:12:55 by diegmore          #+#    #+#             */
/*   Updated: 2024/01/04 13:12:58 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	printef(void)
{
	write(1, "Informe o caminho do mapa\n", 26);
	return (0);
}

int	printmem(void)
{
	write(1, "Falha ao alocar memoria no jogo\n", 32);
	return (0);
}

int	printfilerror(void)
{
	write(1, "Arquivo invalido\n", 18);
	return (0);
}

int	main(int argc, char **argv)
{
	int		j;
	t_vars	vars;

	j = 0;
	if (argc == 2)
	{
		j = namemap(argv[1]);
		if (j == 4)
			j = read_map(argv[1], &vars.game);
		else
			return (printfilerror());
		if (j == 0)
			return (0);
		if (draw_window(vars.game, &vars) == 0)
			printmem();
		draw_wall(vars.game, &vars);
		mlx_put_image_to_window(vars.mlx, vars.win, vars.canva.img, 0, 0);
		mlx_hook(vars.win, 2, 1L << 0, key_event, &vars);
		mlx_hook(vars.win, 17, 0, destroy_game, &vars);
		mlx_loop_hook(vars.mlx, keynotpress, &vars);
		mlx_loop(vars.mlx);
		return (0);
	}
	return (printef());
}
