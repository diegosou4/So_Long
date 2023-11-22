#include "../includes/so_long.h"


int key_event(int keycode, t_vars *vars)
{
     static int i;
     int j;
     vars->keypress = 1;
    if(keycode == ESC)
        mlx_destroy_window(vars->mlx, vars->win);
     while(keycode == KEY_D && vars->keypress == 1)
    {
          usleep(15000);
         if(i % 2 == 1)
        {
        paintback(vars,&vars->person.img[i + 2],vars->person.curr_sx,vars->person.curr_sy, TAM_C, TAM_C);
          //  paintcanva(vars,&vars->img,0,0);
       //     paintwall(vars);
         
            vars->person.curr_sx += TAM_C;
            paintcanvaW(vars,&vars->person.img[i + 2], vars->person.curr_sx ,vars->person.curr_sy,TAM_C,TAM_C);
        }else{
        paintback(vars,&vars->person.img[i],vars->person.curr_sx,vars->person.curr_sy, TAM_C, TAM_C);
          //  paintcanva(vars,&vars->img,0,0);
         //   paintwall(vars);
            vars->person.curr_sx += TAM_C;
            paintcanvaW(vars,&vars->person.img[i + 2], vars->person.curr_sx ,vars->person.curr_sy,TAM_C,TAM_C);
           
        }  
        if(i + 2 == 10)
            i = 0;
         vars->keypress = 0;
         vars->keycode = 0;
         mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
    }
     if(keycode == KEY_A)
     {
          if(i % 2 == 1)
        {
        paintback(vars,&vars->person.img[2],vars->person.curr_sx,vars->person.curr_sy, TAM_C, TAM_C);
            paintcanva(vars,&vars->img,0,0);
         //   paintwall(vars);
            vars->person.curr_sx -= TAM_C;
            paintcanvaW(vars,&vars->person.img[2], vars->person.curr_sx ,vars->person.curr_sy,TAM_C,TAM_C);
        }else{
        paintback(vars,&vars->person.img[2],vars->person.curr_sx,vars->person.curr_sy, TAM_C, TAM_C);    
           paintcanva(vars,&vars->img,0,0);
        //    paintwall(vars);
            vars->person.curr_sx -= TAM_C;
            paintcanvaW(vars,&vars->person.img[3], vars->person.curr_sx ,vars->person.curr_sy,TAM_C,TAM_C);
        }       
     }
     if(keycode == KEY_S)
     {
            if(i % 2 == 1)
        {
        paintback(vars,&vars->person.img[6],vars->person.curr_sx,vars->person.curr_sy, TAM_C, TAM_C);
            paintcanva(vars,&vars->img,0,0);
             //   paintwall(vars);
            vars->person.curr_sy += TAM_C;
            paintcanvaW(vars,&vars->person.img[6], vars->person.curr_sx ,vars->person.curr_sy,TAM_C,TAM_C);
        }else{
        paintback(vars,&vars->person.img[7],vars->person.curr_sx,vars->person.curr_sy, TAM_C, TAM_C);    
           paintcanva(vars,&vars->img,0,0);
             //  paintwall(vars);
            vars->person.curr_sy += TAM_C;
            paintcanvaW(vars,&vars->person.img[7], vars->person.curr_sx ,vars->person.curr_sy,TAM_C,TAM_C);
        }      
     }
     if(keycode == KEY_W)
     {
        if(i % 2 == 1)
        {
        paintback(vars,&vars->person.img[4],vars->person.curr_sx,vars->person.curr_sy, TAM_C, TAM_C);
            paintcanva(vars,&vars->img,0,0);
            //    paintwall(vars);
            vars->person.curr_sy -= TAM_C;
            paintcanvaW(vars,&vars->person.img[4], vars->person.curr_sx ,vars->person.curr_sy,TAM_C,TAM_C);
        }else{
        paintback(vars,&vars->person.img[5],vars->person.curr_sx,vars->person.curr_sy, TAM_C, TAM_C);    
           paintcanva(vars,&vars->img,0,0);
            //   paintwall(vars);
            vars->person.curr_sy -= TAM_C;
            paintcanvaW(vars,&vars->person.img[5], vars->person.curr_sx ,vars->person.curr_sy,TAM_C,TAM_C);
        }       
     
    }
     vars->keypress = 0;
       i++;
       if(i == 10)
        i = 0;

    mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
}


int     keynotpress(t_vars *vars)
{
    static int i;
    static int j;
         usleep(150000);
    if(vars->keypress == 0)
    {
   
        paintback(vars,&vars->person.img[i],vars->person.curr_sx,vars->person.curr_sy, TAM_C, TAM_C);
      //  paintcanva(vars,&vars->img,0,0);
        if(i == 1)
        {
            i = 0;
        }else{
                    i++;
        }

        paintcanvaW(vars,&vars->person.img[i], vars->person.curr_sx,vars->person.curr_sy,TAM_C,TAM_C);
        mlx_put_image_to_window(vars->mlx, vars->win,vars->canva.img, 0, 0);
  
    }
 
}