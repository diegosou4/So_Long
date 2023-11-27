#include "../includes/so_long.h"



void    ft_usleep(long long time)
{
    long long i;
    i = 0;
    while(i < time)
        i++;
}