#include "../includes/so_long.h"


void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;
    if(color == -16777216)
        return;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int    my_mlx_pixel_get(t_img *data, int x, int y)
{

	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return(*(unsigned int*)dst);
}


