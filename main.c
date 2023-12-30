
#include "includes/so_long.h"



int	main(int argc,char **argv)
{
  int j;
  t_vars  vars;
  if(argc == 2)
  {  
    j = namemap(argv[1]);
    if(j == 4)
        j = read_map(argv[1],&vars.game);
    if(j == 0)
       return(0);
    if(draw_window(vars.game,&vars) == 0)
    {
      write(1, "Falha ao alocar memoria no jogo\n",32);
      return(0);
    }
    draw_wall(vars.game, &vars);
     mlx_put_image_to_window(vars.mlx, vars.win,vars.canva.img, 0, 0);
     mlx_hook(vars.win, 2, 1L<<0, key_event, &vars);
    mlx_hook(vars.win,  17, 0, destroy_game, &vars);
   mlx_loop_hook(vars.mlx, keynotpress, &vars);
    mlx_loop(vars.mlx);
    return (0);
  }
}


// Tenho que da free as coisas no final
// Criar funcao que coloca as paredes no game


