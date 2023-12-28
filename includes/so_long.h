
#ifndef SO_LONG_H
#define SO_LONG_H

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


typedef struct s_map
{
    char **map;
    char **cpymap;
    int column;
    int lenchar;
    int coletables[2];
    int exit[2];
    int player;
    int sx[2];
    int sy[2];
    
} t_map;



typedef struct s_img
{
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    char    *relative_path;
    int		img_width;
    int     tamsprite;
	int		img_height;
    int     curr_sprite;
    int     curr_sx;
    int     curr_sy;
}  t_img;


typedef struct s_character
{
    t_img img[4];
    char *relative_path;
    int    img_width;
    int    img_height;
    int     direction;
    int     moviment;
    int     curr_sx;
    int     curr_sy;

}   t_character;

typedef struct s_assets
{
    t_img img;
    char *relative_path;
    int    img_width;
    int    img_height;

}   t_assets;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    int     keypress;
    int     keycode;
    int     action;
    t_map  game;
    t_assets    assets;
    t_character person;
    t_img      coletables;
    t_img   door;
    t_img   img;
    t_img   floor;
    t_img   canva;
    t_img   walls;
}				t_vars;
void    ft_usleep(long long time);

// Pixel and Img
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int    my_mlx_pixel_get(t_img *data, int x, int y);
t_img load_img(char  *path, t_vars *varg);
void loadallimg(t_vars *vars);

// Paint
void    paintcanva(t_vars *varg, t_img *img, int sx, int sy);
void	paint_canvaw(t_vars *varg, t_img *img,float w,float h);
void    paintwall(t_vars *vars);
void    paint_floor(t_vars *vars, int sx, int sy);
void    paint_exit(t_vars *vars, int sx, int sy);
void    paint_coletables(t_vars *vars, int sx, int sy);
void  paint_player(t_vars *vars, int sx, int sy);
void  paint_wall(t_vars *vars, int sx, int sy);


// Event Key
int key_event(int keycode, t_vars *vars);
int     keynotpress(t_vars *vars);
void which_key(int keycode, t_vars *vars);
int destroy_game(t_vars *vars);
// Time

// Event char

int right_animation(t_vars *vars, int d, int j);
int left_animation(t_vars *vars, int d, int j);
int up_animation(t_vars *vars, int d, int j);
int down_animation(t_vars *vars, int d, int j);


// Utils

char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c, int len, int column);
void	*ft_calloc(size_t nmemb, size_t size);
// Count move
void	ft_putnbr(int n);
void print_mov(t_vars *vars);

// Map
int read_map(char *map, t_map *smap);
int validate_map(char *str, t_map *smap);
int validate_map2(char *str, int len);
char    *ftjoinmap(char *str, char *buffer);
void ftjoinmap2(char *str, char *buffer, char *new_str);
char *joinmap(char *new_str, char *buffer);
int checkmap(char **map, int column,int len, t_map *smap);
void    init_smap(t_map *smap);
void    free_mapst(char **map, int i);
int len_map(char *str);
char *open_read(int fd);
int    put_map(t_map *smap, char **map, int column);
int print_error(t_map *smap, int column, int i);
int print_e(void);
int print_d(void);
void map_flags(char cmap, t_map *smap, int sy, int sx);
int mid_wall(char **map, int len, int column);
int check_charmap(t_map *smap);
void flood_fill(int sy, int sx, t_map *smap);
int end_valid(t_map *smap);

// Window

void    draw_window(t_map smapi, t_vars *vars);
void draw_wall(t_map smapi, t_vars *vars);
void    free_game(t_vars *vars);
void free_img(t_vars *vars);
void exit_game(t_vars *vars);
int	locale_sx(t_vars *vars, int i);
int	locale_sy(t_vars *vars, int j);
int     is_wall(t_vars *vars);
#endif