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
vars->person.img[10] = load_img("img/character/L/08.xpm",vars);
vars->person.img[11] = load_img("img/character/L/09.xpm",vars);
vars->person.img[12] = load_img("img/character/L/00.xpm",vars);
vars->person.img[13] = load_img("img/character/L/01.xpm",vars);
vars->person.img[14] = load_img("img/character/L/02.xpm",vars);
vars->person.img[15] = load_img("img/character/L/03.xpm",vars);
vars->person.img[16] = load_img("img/character/L/04.xpm",vars);
vars->person.img[17] = load_img("img/character/L/05.xpm",vars);
vars->person.img[18] = load_img("img/character/L/06.xpm",vars);
vars->person.img[19] = load_img("img/character/L/07.xpm",vars);
vars->person.img[20] = load_img("img/character/D/08.xpm",vars);
vars->person.img[21] = load_img("img/character/D/09.xpm",vars);
vars->person.img[22] = load_img("img/character/D/00.xpm",vars);
vars->person.img[23] = load_img("img/character/D/01.xpm",vars);
vars->person.img[24] = load_img("img/character/D/02.xpm",vars);
vars->person.img[25] = load_img("img/character/D/03.xpm",vars);
vars->person.img[26] = load_img("img/character/D/04.xpm",vars);
vars->person.img[27] = load_img("img/character/D/05.xpm",vars);
vars->person.img[28] = load_img("img/character/D/06.xpm",vars);
vars->person.img[29] = 
/*
vars->person.img[30] = load_img("img/character/U/08.xpm",vars);
vars->person.img[31] = load_img("img/character/U/09.xpm",vars);
vars->person.img[32] = load_img("img/character/U/00.xpm",vars);
vars->person.img[33] = load_img("img/character/U/01.xpm",vars);
vars->person.img[34] = load_img("img/character/U/02.xpm",vars);
vars->person.img[35] = load_img("img/character/U/03.xpm",vars);
vars->person.img[36] = load_img("img/character/U/04.xpm",vars);
vars->person.img[37] = load_img("img/character/U/05.xpm",vars);
vars->person.img[38] = load_img("img/character/U/06.xpm",vars);
vars->person.img[39] = load_img("img/character/U/07.xpm",vars);
*/
vars->person.img[30] = load_img("img/character/D/08.xpm",vars);
vars->person.img[31] = load_img("img/character/D/09.xpm",vars);
vars->person.img[32] = load_img("img/character/D/00.xpm",vars);
vars->person.img[33] = load_img("img/character/D/01.xpm",vars);
vars->person.img[34] = load_img("img/character/D/02.xpm",vars);
vars->person.img[35] = load_img("img/character/D/03.xpm",vars);
vars->person.img[36] = load_img("img/character/D/04.xpm",vars);
vars->person.img[37] = load_img("img/character/D/05.xpm",vars);
vars->person.img[38] = load_img("img/character/D/06.xpm",vars);
vars->person.img[39] = load_img("img/character/D/07.xpm",vars);

}