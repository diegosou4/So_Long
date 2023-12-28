#include "../../includes/so_long.h"


int destroy_game(t_vars *vars)
{
    write(1,"Jogo fechado\n",13);
    exit_game(vars);
    return(1);
}