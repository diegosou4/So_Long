
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
    int len;
    int i;
    char **map;
    i = 0;
    len = 0;
    while(str[len] != '\n' && str[len] != '\0')
        len++;
    if(validate_map2(str,len) < 3)
        return(0);
    map = ft_split(str, '\n');
    return(1);
}

int validate_map2(char *str, int len)
{
    int line_len;
    int i;   
    int column;
    column = 0;
    i = 0;
    while(str[i] != '\0')
    {
        line_len = 0;
        while(str[i] != '\n' && str[i] != '\0')
        {
            line_len++;
            i++;
        }
        if(line_len != len)
            return 0;
        if(str[i] == '\n')
            column++;  
        i++;
    }
    column++;
    return(column);
}
