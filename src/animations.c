
#include "../includes/so_long.h"

int    charstop(t_vars *vars, int d, int i)
{
    paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , TAM_P , i, width, heigth);
    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
    return  (i);
}

int right_animation(t_vars *vars, int d, int j)
{
    paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy ,400, j, width, heigth);
    paint_floor(vars, vars->person.curr_sx, vars->person.curr_sy);
    vars->person.curr_sx += 64;
    paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy ,400 ,j, width, heigth);
   
    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
    vars->keypress = 0;
    vars->person.moviment += 1;
    return  (j);
}

int left_animation(t_vars *vars, int d, int j)
{
    paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , 400  , j, width, heigth);
    paint_floor(vars, vars->person.curr_sx, vars->person.curr_sy);
    vars->person.curr_sx -= 64;
    paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , 400 , j, width, heigth);
    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
    vars->keypress = 0;
    vars->person.moviment += 1;
    return  (j);
}

int up_animation(t_vars *vars, int d, int j)
{
        paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , 400  , j, width, heigth);
        paint_floor(vars, vars->person.curr_sx, vars->person.curr_sy);
        vars->person.curr_sy -= 64;
        paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy ,400 , j, width, heigth);
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
        vars->keypress = 0;
        vars->person.moviment += 1;
        return  (j);
}
int down_animation(t_vars *vars, int d, int j)
{
        paintback(vars, &vars->person.img[d], vars->person.curr_sx,vars->person.curr_sy , 400  , j, width, heigth);
        paint_floor(vars, vars->person.curr_sx, vars->person.curr_sy);
        vars->person.curr_sy += 64;
        paintcanvaW(vars, &vars->person.img[d] ,vars->person.curr_sx, vars->person.curr_sy , 400 , j, width, heigth);
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
        vars->keypress = 0;
        vars->person.moviment += 1;
        return  (j);
}