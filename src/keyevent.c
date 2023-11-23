#include "../includes/so_long.h"


int key_event(int keycode, t_vars *vars)
{
     static int i;
     i = 0;
     int j;
     vars->keypress = 1;
    if(keycode == ESC)
        mlx_destroy_window(vars->mlx, vars->win);
     if(keycode == KEY_D )
    {
        vars->keycode = KEY_D;
        vars->keypress = 1;
    }
    if(keycode == KEY_A)
    {
        vars->keycode = KEY_A;
        vars->keypress = 1;
    }
     if(keycode == KEY_S)
    {
        vars->keycode = KEY_S;
        vars->keypress = 1;
    }
    if(keycode == KEY_W)
    {
        vars->keycode = KEY_W;
        vars->keypress = 1;
    }
}


int     keynotpress(t_vars *vars)
{
    static int i;
    static int j;
     if(vars->keypress == 0)
    {
        paintback(vars,&vars->person.img[i],vars->person.curr_sx,vars->person.curr_sy, TAM_C, TAM_C);
        paintcanva(vars,&vars->img,0,0);
        paintwall(vars);
        if(i == 1)
        {
            i = 0;
        }else{
                    i++;
        }
        paintcanvaW(vars,&vars->person.img[i], vars->person.curr_sx,vars->person.curr_sy,TAM_C,TAM_C);
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
     usleep(100000);
    }
     
     if(vars->keycode == KEY_D && vars->keypress == 1)
    {
        paintback(vars,&vars->person.img[j],vars->person.curr_sx,vars->person.curr_sy, TAM_C, TAM_C);
        paintcanva(vars,&vars->img,0,0);
        paintwall(vars);
        if(j + 1 == 10)
             j = 0;
        vars->person.curr_sx += 16;
        paintcanvaW(vars,&vars->person.img[j + 1], vars->person.curr_sx ,vars->person.curr_sy,TAM_C,TAM_C);
        j++;
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
        usleep(100000);
        if(j + 1 == 10)
            vars->keypress = 0;
 
    }
       if(vars->keycode == KEY_A && vars->keypress == 1)
        { 
        paintback(vars,&vars->person.img[j + 10],vars->person.curr_sx,vars->person.curr_sy, TAM_C, TAM_C);
        paintcanva(vars,&vars->img,0,0);
           paintwall(vars);
        if(j + 1 == 10)
        {
         j = 0;
        }
         
            vars->person.curr_sx -= 16;
            paintcanvaW(vars,&vars->person.img[(j + 10) + 1], vars->person.curr_sx ,vars->person.curr_sy,TAM_C,TAM_C);
            j++;
             mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
           usleep(100000);
        if(j + 1 == 10)
            vars->keypress = 0;
            //time_t now = time(NULL);
           // struct tm *t = localtime(&now);
           // printf("Current time: %02d:%02d:%02d\n", t->tm_hour, t->tm_min, t->tm_sec);
 
        }
        if(vars->keycode == KEY_S && vars->keypress == 1)
        { 
        paintback(vars,&vars->person.img[j + 20],vars->person.curr_sx,vars->person.curr_sy, TAM_C, TAM_C);
        paintcanva(vars,&vars->img,0,0);
           paintwall(vars);
        if(j + 1 == 10)
        {
         j = 0;
        }
         
         vars->person.curr_sy += 16;
        paintcanvaW(vars,&vars->person.img[(j + 20) + 1], vars->person.curr_sx ,vars->person.curr_sy,TAM_C,TAM_C);
        j++;
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
        usleep(100000);
        if(j + 1 == 10)
            vars->keypress = 0;
            //time_t now = time(NULL);
           // struct tm *t = localtime(&now);
           // printf("Current time: %02d:%02d:%02d\n", t->tm_hour, t->tm_min, t->tm_sec);
 
        }
        if(vars->keycode == KEY_W && vars->keypress == 1)
        { 
             paintback(vars,&vars->person.img[j],vars->person.curr_sx,vars->person.curr_sy, TAM_C, TAM_C);
        paintcanva(vars,&vars->img,0,0);
        paintwall(vars);
        if(j + 1 == 10)
             j = 0;
        vars->person.curr_sy -= 16;
        printf("%i numero do jota aqui \n", j + 29 + 1);
        paintcanvaW(vars,&vars->person.img[(j + 29) + 1], vars->person.curr_sx ,vars->person.curr_sy,TAM_C,TAM_C);
        j++;
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
        usleep(100000);
        if(j + 1 == 10)
            vars->keypress = 0;
        }
        if(vars->keypress == 0)
            usleep(100000);
        //vars->keypress = 0;
    }
