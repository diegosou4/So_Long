#include "../includes/so_long.h"


int key_event(int keycode, t_vars *vars)
{
     static int i;
     int j;
    if(keycode == ESC)
        mlx_destroy_window(vars->mlx, vars->win);
    if(keycode == KEY_D)
    {
        if(i % 2 == 1)
        {
        paintback(vars,&vars->person.img[i],vars->person.curr_sx,vars->person.curr_sy, 32, 32);
            paintcanva(vars,&vars->img,0,0);
            paintwall(vars);
            
            vars->person.curr_sx += 32;
            paintcanvaW(vars,&vars->person.img[i], vars->person.curr_sx ,vars->person.curr_sy,32,32);
        }else{
        paintback(vars,&vars->person.img[i],vars->person.curr_sx,vars->person.curr_sy, 32, 32);
            paintcanva(vars,&vars->img,0,0);
            paintwall(vars);
            vars->person.curr_sx += 32;
            paintcanvaW(vars,&vars->person.img[i], vars->person.curr_sx ,vars->person.curr_sy,32,32);
            usleep(10000);
        }       
    }
     if(keycode == KEY_A)
     {
          if(i % 2 == 1)
        {
        paintback(vars,&vars->person.img[2],vars->person.curr_sx,vars->person.curr_sy, 32, 32);
            paintcanva(vars,&vars->img,0,0);
            paintwall(vars);
            vars->person.curr_sx -= 32;
            paintcanvaW(vars,&vars->person.img[2], vars->person.curr_sx ,vars->person.curr_sy,32,32);
        }else{
        paintback(vars,&vars->person.img[2],vars->person.curr_sx,vars->person.curr_sy, 32, 32);    
           paintcanva(vars,&vars->img,0,0);
            paintwall(vars);
            vars->person.curr_sx -= 32;
            paintcanvaW(vars,&vars->person.img[3], vars->person.curr_sx ,vars->person.curr_sy,32,32);
        }       
     }
     if(keycode == KEY_S)
     {
            if(i % 2 == 1)
        {
        paintback(vars,&vars->person.img[6],vars->person.curr_sx,vars->person.curr_sy, 32, 32);
            paintcanva(vars,&vars->img,0,0);
                paintwall(vars);
            vars->person.curr_sy += 32;
            paintcanvaW(vars,&vars->person.img[6], vars->person.curr_sx ,vars->person.curr_sy,32,32);
        }else{
        paintback(vars,&vars->person.img[7],vars->person.curr_sx,vars->person.curr_sy, 32, 32);    
           paintcanva(vars,&vars->img,0,0);
               paintwall(vars);
            vars->person.curr_sy += 32;
            paintcanvaW(vars,&vars->person.img[7], vars->person.curr_sx ,vars->person.curr_sy,32,32);
        }      
     }
     if(keycode == KEY_W)
     {
        if(i % 2 == 1)
        {
        paintback(vars,&vars->person.img[4],vars->person.curr_sx,vars->person.curr_sy, 32, 32);
            paintcanva(vars,&vars->img,0,0);
                paintwall(vars);
            vars->person.curr_sy -= 32;
            paintcanvaW(vars,&vars->person.img[4], vars->person.curr_sx ,vars->person.curr_sy,32,32);
        }else{
        paintback(vars,&vars->person.img[5],vars->person.curr_sx,vars->person.curr_sy, 32, 32);    
           paintcanva(vars,&vars->img,0,0);
               paintwall(vars);
            vars->person.curr_sy -= 32;
            paintcanvaW(vars,&vars->person.img[5], vars->person.curr_sx ,vars->person.curr_sy,32,32);
        }       
     
    }
       i++;
       if(i == 10)
        i = 0;
    
    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
}