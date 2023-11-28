#include "../includes/so_long.h"



int    charstop(t_vars *vars, int d, int i)
{
    if(i == 0)
        i = TAM_P * 8;
    paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , i + TAM_P, i, width, heigth);
    //paintcanva(vars,&vars->img,0,0);
   
    paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , i + TAM_P, i, width, heigth);
    paintcanvaW(vars, &vars->assets.img ,64, 64 , 64, 0, 64, 64);
    paintcanvaW(vars, &vars->assets.img ,128, 64 , 64, 0, 64, 64);
    paintcanvaW(vars, &vars->assets.img ,192, 64 , 64, 0, 64, 64);
    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
    i += TAM_P;
    if(i == 400)
        i = 0;
     usleep(200000);
     return  (i);
}

int right_animation(t_vars *vars, int d, int j)
{
   if(j >= 320)
            j = 0;
    paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , (j + TAM_P) , j, width, heigth);
    vars->person.curr_sx += 8;
   // paintcanva(vars,&vars->img,0,0);
    paintcanvaW(vars, &vars->assets.img ,64, 0 , 64, 64, 64, 64);
    paintcanvaW(vars, &vars->assets.img ,128, 0 , 64, 64, 64, 64);
    paintcanvaW(vars, &vars->assets.img ,192, 0 , 64, 64, 64, 64);
    paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , (j + TAM_P), (j), width, heigth);
    j += TAM_P;
   
    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
    ft_usleep(100000 * 200);
    if(j >= 320)
    {
        vars->keypress = 0;
        vars->person.moviment += 1;
    }
      
    return  (j);
}

int left_animation(t_vars *vars, int d, int j)
{
    if(j == 0)
        j = 320;
    paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , (j + TAM_P) , j, width, heigth);
    vars->person.curr_sx -= 8;
    paintcanva(vars,&vars->img,0,0);
    paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , (j + TAM_P), (j), width, heigth);
    j -= TAM_P;
    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
    ft_usleep(100000 * 200);
    if(j == 0)
    {
        vars->keypress = 0;
        vars->person.moviment += 1;
    }
    return  (j);
}

int up_animation(t_vars *vars, int d, int j)
{
        if(j == 0)
            j = TAM_P * 8;
        paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , (j + TAM_P) , j, width, heigth);
        vars->person.curr_sy -= 8;
        paintcanva(vars,&vars->img,0,0);
        paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , (j + TAM_P), (j), width, heigth);
        j -= TAM_P;
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
        ft_usleep(100000 * 200);
        if(j == 0)
        {
              vars->keypress = 0;
              vars->person.moviment += 1;
        }
        return  (j);
}
int down_animation(t_vars *vars, int d, int j)
{
        if(j == 0)
            j = TAM_P * 8;
        paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , (j + TAM_P) , j, width, heigth);
        vars->person.curr_sy += 8;
        paintcanva(vars,&vars->img,0,0);
        paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , (j + TAM_P), (j), width, heigth);
        j -= TAM_P;
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
        ft_usleep(100000 * 200);
        if(j == 0)
        {
              vars->keypress = 0;
              vars->person.moviment += 1;
        } 
        return  (j);
}
