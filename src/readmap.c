
#include "../includes/so_long.h"
#include <string.h>


int read_map(char *map)
{
    char    *str;
    char    *buffer;
    int fd = open(map, O_RDONLY);
    int i;
    int sizestr;
    sizestr = 1;
    str = NULL;
    while(sizestr != 0)
    {
        buffer = get_next_line(fd);
        sizestr = ft_strlen(buffer);
        if(sizestr == 0)
            break;
        str = ft_strjoin(str, buffer);
    }
    i = validate_map(str);
    close(fd);
    return(i);
}
int validate_map(char *str)
{
    int i;
    int j;
    int len;
    j = 0;
    i = 0;
    len = 0;
    char **map;
    while(str[len] != '\n')
        len++;
    while(str[i] != '\0')
    {
        if(str[i] == '\n')
            j++;  
        i++;
    }
    if(i < 3)
        return(0);
    j++;
    map = ft_split(str, '\n');
    printf("%i deu certo \n" ,validate_map2(map, len));
    return(1);
}

int     validate_map2(char **map, int len)
{
    int i;

    i = 0;
    while(map[i] != NULL)
    {
        if(ft_strlen(map[i]) != len)
            return(0);
        i++;
    }
    return(1);
}