
#include "includes/so_long.h"



int	main(void)
{
    t_vars  vars;
  
    
    vars.mlx = mlx_init();
    vars.img = load_img("img/back/Background_space.xpm",&vars);
    vars.win = mlx_new_window(vars.mlx, vars.img.img_width, vars.img.img_height, "Amoung us");
    // Load personagem
    
    vars.walls  = load_img("img/walls/f.xpm",&vars);
     loadallimg(&vars);

    // Colocando imagem
   // mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
    // Tamanho da imagem
    vars.canva.img = mlx_new_image(vars.mlx,1280,600);
    vars.canva.addr = mlx_get_data_addr(vars.canva.img, &vars.canva.bits_per_pixel, &vars.canva.line_length,
								&vars.canva.endian);

    vars.person.img->curr_sx = 0;
    vars.person.img->curr_sy = 0;
    // Pintando plano
    paintcanva(&vars,&vars.img,0,0);
    // Pintando Personagem
    int i;
    i = 0;
    while(i <= 448)
    {   
         paintcanvaW(&vars,&vars.walls,0,i, 32, 32);
         i += 32;
    }
    int j;
    j = 0;
    while(j < 960)
    {   
         paintcanvaW(&vars,&vars.walls,j,i, 32, 32);
         j += 32;
    }
    while(i >= 0 )
    {
           paintcanvaW(&vars,&vars.walls,j,i, 32, 32);
         i -= 32;
    }
    while(j > 0)
    {
            paintcanvaW(&vars,&vars.walls,j,0, 32, 32);
            j -= 32;
    }
     vars.keypress = 0;
   paintcanvaW(&vars,&vars.person.img[0],0,0, TAM_C, TAM_C);
   // printf("%i--------  \n", my_mlx_pixel_get(&vars.person.img[0], 0 ,0));
    mlx_put_image_to_window(vars.mlx, vars.win,vars.canva.img, 0, 0);
     mlx_hook(vars.win, 2, 1L<<0, key_event, &vars);
     mlx_loop_hook(vars.mlx, keynotpress, &vars);
    mlx_loop(vars.mlx);
}



