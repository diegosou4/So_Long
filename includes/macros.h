/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:35:53 by diegmore          #+#    #+#             */
/*   Updated: 2024/01/04 15:36:34 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H
# include "../minilibx-linux/mlx.h"
# include "../src/externfunc/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define ESC 65307
# define KEY_D 100
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119
# define TAM_P 40
# define WIDTH 400
# define HEIGTH 40
# define MAX_X 10
# define MAX_Y 20
# define TAM_B 64
# define TIME_ANIM 20000000

typedef enum e_type
{
	CHAR_R,
	CHAR_L,
	CHAR_D,
	CHAR_U,
	COIN,
	WALLS,
	DOOR,
	FLOOR
}	t_type;

# define MIDDLE 16

#endif
