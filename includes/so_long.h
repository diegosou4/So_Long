
#ifndef SO_LONG_H
#define SO_LONG_H

#include "../minilibx_linux/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
#include <time.h>

#define ESC 65307
# define KEY_D 100
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119
# define TAM_C 32
# define TAM_P 144



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
    t_img img[50];
    char *relative_path[50];
    int    img_width[50];
    int    img_height[50];
    int     curr_sx;
    int     curr_sy;
}   t_character;



typedef struct	s_vars {
	void	*mlx;
	void	*win;
    int     keypress;
    int     keycode;
    int     action;
    t_character person;
    t_img   img;
    t_img   canva;
    t_img   walls;
}				t_vars;

// Pixel and Img
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int    my_mlx_pixel_get(t_img *data, int x, int y);
t_img load_img(char  *path, t_vars *varg);
void loadallimg(t_vars *vars);

// Paint
void    paintcanva(t_vars *varg, t_img *img, int sx, int sy);
void   paintback(t_vars *varg, t_img *img, int sx, int sy, float w, float h);
void    paintcanvaW(t_vars *varg, t_img *img, int sx, int sy, float w, float h);
void    paintwall(t_vars *vars);

// Event Key
int key_event(int keycode, t_vars *vars);
int     keynotpress(t_vars *vars);



#endif