#include "../includes/so_long.h"



int    charstop(t_vars *vars, int d, int i)
{
    if(i == 0)
        i = 320;
    paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , i + 40, i, width, heigth);
    paintcanva(vars,&vars->img,0,0);
   
    paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , i + 40, i, width, heigth);

    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
    i += 40;
    if(i == 400)
        i = 0;
     usleep(200000);
     return  (i);
}

int right_animation(t_vars *vars, int d, int j)
{
   if(j >= 320)
            j = 0;
    paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , (j + 40) , j, width, heigth);
    vars->person.curr_sx += 4;
    paintcanva(vars,&vars->img,0,0);
    paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , (j + 40), (j), width, heigth);
    j += 40;
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
    paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , (j + 40) , j, width, heigth);
    vars->person.curr_sx -= 4;
    paintcanva(vars,&vars->img,0,0);
    paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , (j + 40), (j), width, heigth);
    j -= 40;
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
            j = 320;
        paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , (j + 40) , j, width, heigth);
        vars->person.curr_sy -= 4;
        paintcanva(vars,&vars->img,0,0);
        paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , (j + 40), (j), width, heigth);
        j -= 40;
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
            j = 320;
        paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , (j + 40) , j, width, heigth);
        vars->person.curr_sy += 4;
        paintcanva(vars,&vars->img,0,0);
        paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , (j + 40), (j), width, heigth);
        j -= 40;
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
        ft_usleep(100000 * 200);
        if(j == 0)
        {
              vars->keypress = 0;
              vars->person.moviment += 1;
        } 
        return  (j);
}
