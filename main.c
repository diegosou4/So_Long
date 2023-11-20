
#include "includes/so_long.h"

#include <stdio.h>


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


void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;
    if(color == -16777216)
        return;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int    my_mlx_pixel_get(t_img *data, int x, int y)
{

	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return(*(unsigned int*)dst);
}



typedef struct s_character
{
    t_img img[8];
    char *relative_path[8];
    int    img_width[8];
    int    img_height[8];
    int     curr_sx;
    int     curr_sy;
}   t_character;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    t_character person;
    t_img   img;
    t_img   canva;
}				t_vars;








void    paintcanva(t_vars *varg, t_img *img, int sx, int sy)
{
    int x;
    int y;

    y = 0;
    while(y < img->img_height)
    {
        x = 0;
        while(x < img->img_width)
        {
            my_mlx_pixel_put(&varg->canva, sx + x, sy + y,my_mlx_pixel_get(img, x, y));
            x++;
        }
        y++;
    }

}
void    painttrans(t_vars *varg, t_img *img, int sx, int sy, float w, float h)
{
    float x;
    float y;
    int k;
    int j;
    k = 0;
    y = 0;
    w = img->img_width / w;
    h = img->img_height / h;
    t_vars  *p;
    p = varg;
    while(y < img->img_height )
    {
        j = 0;
        x = 0;
        while(x < img->img_width)
        {
            my_mlx_pixel_put(&p->canva, sx + j, sy + k,0);
            x += w;
            j++;
        }
        k++;
        y += h;
    }

}
void    paintcanvaW(t_vars *varg, t_img *img, int sx, int sy, float w, float h)
{
    float x;
    float y;
    int k;
    int j;
    k = 0;
    y = 0;
    w = img->img_width / w;
    h = img->img_height / h;
    t_vars  *p;
    p = varg;
    while(y < img->img_height )
    {
        j = 0;
        x = 0;
        while(x < img->img_width)
        {
            my_mlx_pixel_put(&p->canva, sx + j, sy + k,my_mlx_pixel_get(img, (int)x, (int)y));
            x += w;
            j++;
        }
        k++;
        y += h;
    }

}

t_img load_img(char  *path, t_vars *varg)
{
    t_img img;
    img.relative_path = path;
    img.img = mlx_xpm_file_to_image(varg->mlx,img.relative_path,&img.img_width,&img.img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    return(img);
}
int p_fuction(int keycode, t_vars *vars)
{
     static int i;
    if(keycode == ESC)
        mlx_destroy_window(vars->mlx, vars->win);
    if(keycode == KEY_D)
    {
        if(i % 2 == 1)
        {
            painttrans(vars,&vars->person.img[1],vars->person.curr_sx,vars->person.curr_sy, 64, 64);
            paintcanva(vars,&vars->img,0,0);
            vars->person.curr_sx += 64;
            paintcanvaW(vars,&vars->person.img[0], vars->person.curr_sx ,vars->person.curr_sy,64,64);
        }else{
            painttrans(vars,&vars->person.img[0],vars->person.curr_sx,vars->person.curr_sy, 64, 64);
            paintcanva(vars,&vars->img,0,0);
            vars->person.curr_sx += 64;
            paintcanvaW(vars,&vars->person.img[1], vars->person.curr_sx ,vars->person.curr_sy,64,64);
        }       
    }
     if(keycode == KEY_A)
     {
          if(i % 2 == 1)
        {
            painttrans(vars,&vars->person.img[2],vars->person.curr_sx,vars->person.curr_sy, 64, 64);
            paintcanva(vars,&vars->img,0,0);
            vars->person.curr_sx -= 64;
            paintcanvaW(vars,&vars->person.img[2], vars->person.curr_sx ,vars->person.curr_sy,64,64);
        }else{
            painttrans(vars,&vars->person.img[2],vars->person.curr_sx,vars->person.curr_sy, 64, 64);    
           paintcanva(vars,&vars->img,0,0);
            vars->person.curr_sx -= 64;
            paintcanvaW(vars,&vars->person.img[3], vars->person.curr_sx ,vars->person.curr_sy,64,64);
        }       
     }
     if(keycode == KEY_S)
     {
            if(i % 2 == 1)
        {
            painttrans(vars,&vars->person.img[7],vars->person.curr_sx,vars->person.curr_sy, 64, 64);
            paintcanva(vars,&vars->img,0,0);
            vars->person.curr_sy += 64;
            paintcanvaW(vars,&vars->person.img[7], vars->person.curr_sx ,vars->person.curr_sy,64,64);
        }else{
            painttrans(vars,&vars->person.img[6],vars->person.curr_sx,vars->person.curr_sy, 64, 64);    
           paintcanva(vars,&vars->img,0,0);
            vars->person.curr_sy += 64;
            paintcanvaW(vars,&vars->person.img[6], vars->person.curr_sx ,vars->person.curr_sy,64,64);
        }      
     }
     if(keycode == KEY_W)
     {
        if(i % 2 == 1)
        {
            painttrans(vars,&vars->person.img[5],vars->person.curr_sx,vars->person.curr_sy, 64, 64);
            paintcanva(vars,&vars->img,0,0);
            vars->person.curr_sy -= 64;
            paintcanvaW(vars,&vars->person.img[5], vars->person.curr_sx ,vars->person.curr_sy,64,64);
        }else{
            painttrans(vars,&vars->person.img[4],vars->person.curr_sx,vars->person.curr_sy, 64, 64);    
           paintcanva(vars,&vars->img,0,0);
            vars->person.curr_sy -= 64;
            paintcanvaW(vars,&vars->person.img[4], vars->person.curr_sx ,vars->person.curr_sy,64,64);
        }       
     
    }
       i++;
    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
}



int	main(void)
{
    t_vars  vars;
  
    vars.mlx = mlx_init();
    vars.img = load_img("img/back/Background_space.xpm",&vars);
    vars.win = mlx_new_window(vars.mlx, vars.img.img_width, vars.img.img_height, "Amoung us");
    // Load personagem
    vars.person.img[0] = load_img("img/character/R/r00.xpm",&vars);
    vars.person.img[1] = load_img("img/character/R/r01.xpm",&vars);
    vars.person.img[2] = load_img("img/character/L/r00.xpm",&vars);
    vars.person.img[3] = load_img("img/character/L/r01.xpm",&vars);
    vars.person.img[4] = load_img("img/character/U/r00.xpm",&vars);
    vars.person.img[5] = load_img("img/character/U/r01.xpm",&vars);
    vars.person.img[6] = load_img("img/character/D/r00.xpm",&vars);
    vars.person.img[7] = load_img("img/character/D/r01.xpm",&vars);
    

    // Colocando imagem
   // mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
    // Tamanho da imagem
    vars.canva.img = mlx_new_image(vars.mlx,1280,600);
    vars.canva.addr = mlx_get_data_addr(vars.canva.img, &vars.canva.bits_per_pixel, &vars.canva.line_length,
								&vars.canva.endian);

    vars.person.img->curr_sx = 0;
    vars.person.img->curr_sy = 0;
    // Pintando plano
    paintcanva(&vars,&vars.img,0,0);
    // Pintando Personagem
   paintcanvaW(&vars,&vars.person.img[0],0,0, 64, 64);
   // printf("%i--------  \n", my_mlx_pixel_get(&vars.person.img[0], 0 ,0));
   mlx_put_image_to_window(vars.mlx, vars.win,vars.canva.img, 0, 0);
    mlx_hook(vars.win, 2, 1L<<0, p_fuction, &vars);
    mlx_loop(vars.mlx);
}



