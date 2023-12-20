
#include "../../includes/so_long.h"

int len_map(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\n' && str[i] != '\0')
    {
        i++;
    }
    return(i);
 
}


char *open_read(int fd)
{
    char    *buffer;
    int sizestr;
    char *str;
    sizestr = 1;
    str = NULL;
    while(sizestr != 0)
    {
        buffer = get_next_line(fd);
        sizestr = ft_strlen(buffer);
        if(sizestr == 0)
        {
            free(buffer);
            break;
        }
       str = ftjoinmap(str, buffer);
    }
    return(str);
}

int print_error(t_map smap, int column)
{
    while (column > 0)
    {
        column--;
        free(smap.map[column]);
    }
    free(smap.map);
    
    write(1,"Deu erro nesse mapa ai chefe", 30);

    return(0);
}
