
#include "includes/so_long.h"



int	main(int argc,char **argv)
{
  int j;
  t_map gamemap;
  t_vars  vars;
  if(argc == 2)
  {  
    j = read_map(argv[1],&gamemap);
    if(j == 0)
      return(0);
    draw_window(gamemap,&vars);
    paintcanvaW(&vars, &vars.person.img[0] ,vars.person.curr_sx, vars.person.curr_sy, 360, 320, width, heigth);
    
   
    mlx_hook(vars.win, 2, 1L<<0, key_event, &vars);
    mlx_loop_hook(vars.mlx, keynotpress, &vars);
    mlx_loop(vars.mlx);
       return (0 );
  }
    
  
}





