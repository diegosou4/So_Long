


#include "../includes/so_long.h"


void which_key(int keycode, t_vars *vars)
{
    if(keycode == KEY_D)
    {
        vars->keycode = KEY_D;
        vars->person.direction = 0;
    }
    if(keycode == KEY_A)
    {
        vars->keycode = KEY_A;
        vars->person.direction = 1;
    }
     if(keycode == KEY_S)
    {
        vars->keycode = KEY_S;
        vars->person.direction = 2;
    }
    if(keycode == KEY_W)
    {
        vars->keycode = KEY_W;
        vars->person.direction = 3;
    }
       vars->keypress = 1;
}


int key_event(int keycode, t_vars *vars)
{
    if(keycode == ESC && vars->keypress == 0)
       exit_game(vars);
    if(keycode == KEY_D && vars->keypress == 0)
    {
        vars->keycode = KEY_D;
        vars->person.direction = 0;
    }
    if(keycode == KEY_A && vars->keypress == 0)
    {
        vars->keycode = KEY_A;
        vars->person.direction = 1;
    }
     if(keycode == KEY_S && vars->keypress == 0)
    {
        vars->keycode = KEY_S;
        vars->person.direction = 2;
    }
    if(keycode == KEY_W && vars->keypress == 0)
    {
        vars->keycode = KEY_W;
        vars->person.direction = 3;
    }
    vars->keypress = 1;
    if(is_exit(vars) == 0 || is_wall(vars) == 0)
        vars->keypress = 0;
        
    return(0);
}


int     keynotpress(t_vars *vars)
{
    int j;
    j = 360;
    if(vars->game.coletables[1] == 0)
        paintcanvaW(vars, &vars->door , vars->door.curr_sx, vars->door.curr_sy, 256, 192, 256, 64 );
    if(vars->keypress == 1 && vars->keycode == KEY_D)
        j = right_animation(vars, vars->person.direction , j);
    if(vars->keypress == 1 && vars->keycode == KEY_A)
        j = left_animation(vars, vars->person.direction , j);
    if(vars->keypress == 1 && vars->keycode == KEY_S)
        j = down_animation(vars, vars->person.direction , j);
    if(vars->keypress == 1 && vars->keycode == KEY_W)
        j = up_animation(vars, vars->person.direction , j);
    return(1);
}