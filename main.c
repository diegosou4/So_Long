
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
    paintcanvaW(&vars, &vars.person.img[0] ,0, 0, 360, 320, width, heigth);
   // vars.keypress = 0;
 //   mlx_put_image_to_window(vars.mlx, vars.win,vars.canva.img, 0, 0);
  // paintcanvaW(&vars, &vars.person.img[0] ,vars.person.curr_sx , vars.person.curr_sy , 360, 320, width, heigth);
    mlx_loop(vars.mlx);
    return(0);
  }

    
    // Load personagem
   /*
    vars.walls  = load_img("img/walls/f.xpm",&vars);
    loadallimg(&vars);
  
    // Colocando imagem
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
    // Tamanho da imagem
    
   vars.canva.img = mlx_new_image(vars.mlx,1280,600);
    vars.canva.addr = mlx_get_data_addr(vars.canva.img, &vars.canva.bits_per_pixel, &vars.canva.line_length,
								&vars.canva.endian);

    vars.person.img->curr_sx = 0;
    vars.person.img->curr_sy = 0;
    vars.person.direction = 0;
    // Pintando plano
   paintcanva(&vars,&vars.img,0,0);
    // Pintando Personagem
    
   
    vars.keypress = 0;
  
    paintcanvaW(&vars, &vars.person.img[0] ,0, 0, 360, 320, width, heigth);
    paintcanvaW(&vars, &vars.person.img[0], 0, 0, 160, 120, width, heigth);
    

   // printf("%i--------  \n", my_mlx_pixel_get(&vars.person.img[0], 0 ,0));
    mlx_put_image_to_window(vars.mlx, vars.win,vars.canva.img, 0, 0);
    mlx_hook(vars.win, 2, 1L<<0, key_event, &vars);
    mlx_loop_hook(vars.mlx, keynotpress, &vars);
    mlx_loop(vars.mlx);
  */
 
   return (0 );
}





