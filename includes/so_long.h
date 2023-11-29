
#ifndef SO_LONG_H
#define SO_LONG_H

#include "../minilibx_linux/mlx.h"
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


typedef struct s_img
{
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    char    *relative_path;
    int		img_width;
	int		img_height;
    int     curr_sx;
    int     curr_sy;
}  t_img;


typedef struct s_character
{
    t_img img[10];
    char *relative_path[10];
    int    img_width[10];
    int    img_height[10];
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
    t_assets    assets;
    t_character person;
    t_img   img;
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
void   paintback(t_vars *varg, t_img *img, int sx, int sy,int tamsprite,int start, float w, float h);
void    paintcanvaW(t_vars *varg, t_img *img, int sx, int sy, int tamsprite , int start ,float w, float h);
void    paintwall(t_vars *vars);
void    paintchar(t_vars *varg, t_img *img, int sx, int sy, int tamsprite , int start,float w, float h);
// Event Key
int key_event(int keycode, t_vars *vars);
int     keynotpress(t_vars *vars);

// Time

// Event char
int    charstop(t_vars *vars, int d, int i);
int right_animation(t_vars *vars, int d, int j);
int left_animation(t_vars *vars, int d, int j);
int up_animation(t_vars *vars, int d, int j);
int down_animation(t_vars *vars, int d, int j);


// Utils

char	*ft_itoa(int n);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
// Count move
void count_move(t_vars *vars);

// Map
int read_map(char *map);
int validate_map(char *str);
int validate_map2(char **map, int len);

#endif