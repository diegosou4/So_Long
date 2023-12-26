/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:57:40 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/23 16:57:42 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void    free_game(t_vars *vars)
{

    int i;
    i = 0;
    while(i < vars->game.column)
    {
        free(vars->game.map[i]);
        free(vars->game.cpymap[i]);
        i++;
    }
    free(vars->game.map);
    free(vars->game.cpymap);

}

void exit_game(t_vars *vars)
{
        free_game(vars);
  
        mlx_clear_window(vars->mlx, vars->win);
        mlx_destroy_image(vars->mlx, vars->canva.img); // Destroi uma imagem
        mlx_destroy_display(vars->mlx); // Encerra a conexao com Xserve
        mlx_destroy_window(vars->mlx, vars->win); // Destroi a janela
        free(vars->mlx); // Free no mlx
        exit(0);
}