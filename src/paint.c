#include "../includes/so_long.h"

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
void   paintback(t_vars *varg, t_img *img, int sx, int sy, float w, float h)
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
void    paintwall(t_vars *vars)
{
        int h;
    h = 0;
    while(h <= 448)
    {   
         paintcanvaW(vars,&vars->walls,0,h, TAM_P, TAM_P);
         h += TAM_P;
    }
    int j;
    j = 0;
    while(j < 960)
    {   
         paintcanvaW(vars,&vars->walls,j,h, TAM_P, TAM_P);
         j += TAM_P;
    }
    while(h >= 0 )
    {
           paintcanvaW(vars,&vars->walls,j,h, TAM_P, TAM_P);
         h -= TAM_P;
    }
    while(j > 0)
    {
            paintcanvaW(vars,&vars->walls,j,0, TAM_P, TAM_P);
            j -= TAM_P;
    }
}
