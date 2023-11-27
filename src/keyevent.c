#include "../includes/so_long.h"


int key_event(int keycode, t_vars *vars)
{

     static int j;
     // vars->keypress = 1;
    if(keycode == ESC && vars->keypress == 0)
    {
        mlx_destroy_window(vars->mlx, vars->win);
     }
     if(keycode == KEY_D && vars->keypress == 0)
    {
       vars->keycode = KEY_D;
        vars->keypress = 1;
        vars->person.direction = 0;
    }
    if(keycode == KEY_A && vars->keypress == 0)
    {
        vars->keycode = KEY_A;
        vars->keypress = 1;
        vars->person.direction = 1;
    }
     if(keycode == KEY_S && vars->keypress == 0)
    {
        vars->keycode = KEY_S;
        vars->keypress = 1;
        vars->person.direction = 2;
    }
    if(keycode == KEY_W && vars->keypress == 0)
    {
        vars->keycode = KEY_W;
        vars->keypress = 1;
        vars->person.direction = 3;
    }
    
}


int     keynotpress(t_vars *vars)
{
    static int j;
    static int i;
    int d;
    d = vars->person.direction;
    if(vars->keypress == 0)
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
    }
    if(vars->keypress == 1 && vars->keycode == KEY_D)
    {
        if(j >= 320)
            j = 0;
        paintback(vars, &vars->person.img[0], vars->person.curr_sx,vars->person.curr_sy , (j + 40) , j, width, heigth);
        vars->person.curr_sx += 15;
        paintcanva(vars,&vars->img,0,0);
        paintcanvaW(vars, &vars->person.img[0] ,vars->person.curr_sx, vars->person.curr_sy , (j + 40), (j), width, heigth);
        j += 40;
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
        ft_usleep(100000 * 350);
         if(j >= 320)
            vars->keypress = 0;
        

    }
    if(vars->keypress == 1 && vars->keycode == KEY_A)
    {
        if(j == 0)
            j = 320;
        paintback(vars, &vars->person.img[1], vars->person.curr_sx,vars->person.curr_sy , (j + 40) , j, width, heigth);
        vars->person.curr_sx -= 15;
        paintcanva(vars,&vars->img,0,0);
        paintcanvaW(vars, &vars->person.img[1] ,vars->person.curr_sx, vars->person.curr_sy , (j + 40), (j), width, heigth);
        j -= 40;
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
        ft_usleep(100000 * 350);
        if(j == 0)
            vars->keypress = 0;
    }
    if(vars->keypress == 1 && vars->keycode == KEY_S)
    {
        if(j == 0)
            j = 320;
        paintback(vars, &vars->person.img[2], vars->person.curr_sx,vars->person.curr_sy , (j + 40) , j, width, heigth);
        vars->person.curr_sy += 15;
        paintcanva(vars,&vars->img,0,0);
        paintcanvaW(vars, &vars->person.img[2] ,vars->person.curr_sx, vars->person.curr_sy , (j + 40), (j), width, heigth);
        j -= 40;
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
        ft_usleep(100000 * 350);
        if(j == 0)
            vars->keypress = 0;
    }
    if(vars->keypress == 1 && vars->keycode == KEY_W)
    {
        if(j == 0)
            j = 320;
        paintback(vars, &vars->person.img[3], vars->person.curr_sx,vars->person.curr_sy , (j + 40) , j, width, heigth);
        vars->person.curr_sy -= 15;
        paintcanva(vars,&vars->img,0,0);
        paintcanvaW(vars, &vars->person.img[3] ,vars->person.curr_sx, vars->person.curr_sy , (j + 40), (j), width, heigth);
        j -= 40;
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
        ft_usleep(100000 * 350);
        if(j == 0)
            vars->keypress = 0;
    }
    }