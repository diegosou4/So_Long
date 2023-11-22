#include "../includes/so_long.h"

t_img load_img(char  *path, t_vars *varg)
{
    t_img img;
    img.relative_path = path;
    img.img = mlx_xpm_file_to_image(varg->mlx,img.relative_path,&img.img_width,&img.img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    return(img);
}

void loadallimg(t_vars *vars)
{
vars->person.img[0] = load_img("img/character/R/08.xpm",vars);
vars->person.img[1] = load_img("img/character/R/09.xpm",vars);
vars->person.img[2] = load_img("img/character/R/00.xpm",vars);
vars->person.img[3] = load_img("img/character/R/01.xpm",vars);
vars->person.img[4] = load_img("img/character/R/02.xpm",vars);
vars->person.img[5] = load_img("img/character/R/03.xpm",vars);
vars->person.img[6] = load_img("img/character/R/04.xpm",vars);
vars->person.img[7] = load_img("img/character/R/05.xpm",vars);
vars->person.img[8] = load_img("img/character/R/06.xpm",vars);
vars->person.img[9] = load_img("img/character/R/07.xpm",vars);


    
}