/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:37:27 by diegmore          #+#    #+#             */
/*   Updated: 2024/01/04 15:37:31 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "macros.h"

typedef struct s_map
{
	char		**map;
	char		**cpymap;
	int			column;
	int			lenchar;
	int			coletables[2];
	int			exit[2];
	int			player;
	int			sx[2];
	int			sy[2];

}				t_map;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*relative_path;
	int			img_width;
	int			tamsprite;
	int			img_height;
	int			curr_sprite;
	int			curr_sx;
	int			curr_sy;
}				t_img;

typedef struct s_assets
{
	t_img		img;
	char		*relative_path;
	int			img_width;
	int			img_height;

}				t_assets;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			keypress;
	int			keycode;
	int			action;
	int			numassets;
	int			pdirection;
	int			curr_sx;
	int			curr_sy;
	int			nmov;
	t_map		game;
	t_img		canva;
	t_assets	*assets;
}				t_vars;

// Pixel and Img
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
int				my_mlx_pixel_get(t_img *data, int x, int y);
t_img			load_img(char *path, t_vars *varg);
void			loadallimg(t_vars *vars);
void			givevalues(t_assets *assets, int img_with, int img_height);

// Paint
void			paintcanva(t_vars *varg, t_img *img, int sx, int sy);
void			case_map(char map, t_vars *vars, int i, int j);
void			paint_canvaw(t_vars *varg, t_img *img, float w, float h);
void			paintwall(t_vars *vars);
void			paint(t_vars *vars, t_assets *assets, int sx, int sy);

// Event Key
int				key_event(int keycode, t_vars *vars);
int				keynotpress(t_vars *vars);
void			which_key(int keycode, t_vars *vars);
int				destroy_game(t_vars *vars);
void			valuesforkey(t_vars *vars, int keycode);

// Event char
void			where_mov(t_vars *vars);
void			where_bonus(t_vars *vars);
void			mov(t_vars *vars);
void			ft_usleep(long long time);
void			charstop(t_vars *vars);
void			paint_anim(t_vars *vars, int j);
void			update_p(t_vars *vars, int j);
// Bonus
void			diff_key(t_vars *vars);
void			count_move(t_vars *vars);
int				is_exit(t_vars *vars, int sx, int sy);

// Utils

char			*ft_strdup(const char *src);
char			**ft_split(char const *s, char c, int len, int column);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_itoa(int n);
int				printef(void);
int				printmem(void);
int				printfilerror(void);
// Count move

void			ft_putnbr(int n);
void			print_mov(int mov);

// Map
int				namemap(char *pathname);
int				read_map(char *map, t_map *smap);
int				validate_map(char *str, t_map *smap);
int				validate_map2(char *str, int len);
char			*ftjoinmap(char *str, char *buffer);
void			ftjoinmap2(char *str, char *buffer, char *new_str);
char			*joinmap(char *new_str, char *buffer);
int				checkmap(char **map, int column, int len, t_map *smap);
void			init_smap(t_map *smap);
void			free_mapst(char **map, int i);
int				len_map(char *str);
char			*open_read(int fd);
int				put_map(t_map *smap, char **map, int column);
int				print_error(t_map *smap, int column, int i);
int				print_e(void);
int				print_d(void);
void			map_flags(char cmap, t_map *smap, int sy, int sx);
int				mid_wall(char **map, int len, int column);
int				check_charmap(t_map *smap);
void			flood_fill(int sy, int sx, t_map *smap);
int				values_strongmap(char **map);
int				end_valid(t_map *smap);

// Window

int				draw_window(t_map smapi, t_vars *vars);
void			draw_wall(t_map smapi, t_vars *vars);
void			free_game(t_vars *vars);
void			free_img(t_vars *vars);
void			exit_game(t_vars *vars);
int				locale_sx(t_vars *vars, int i);
int				locale_sy(t_vars *vars, int j);
int				is_wall(t_vars *vars);

#endif
