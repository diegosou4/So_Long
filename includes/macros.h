/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:35:53 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/29 17:35:54 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MACROS
#define MACROS

#include "../minilibx-linux/mlx.h"
#include "../src/externfunc/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
#include <time.h>
#include <stdlib.h>

#define ESC 65307
# define KEY_D 100
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119
# define TAM_P 40
# define width 400
# define heigth 40
# define MAX_X 10
# define MAX_Y 20
# define TAM_B 64
# define TIME_ANIM 100000 * 200

// Assets Map

# define CHAR_R 0
# define CHAR_L 1
# define CHAR_D 2
# define CHAR_U 3
# define COIN 4
# define WALLS 5
# define DOOR 6
# define FLOOR 7


// Common numbers

# define middle 16
//
#define New malloc
#define Class sizeof(t_assets)

#endif