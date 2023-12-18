
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
        {
            free(buffer);
            break;
        }
   
       str = ftjoinmap(str, buffer);
    }
    i = validate_map(str);
    free(str);
    close(fd);
    return(i);
}
int validate_map(char *str)
{
    int len;
    int i;
    char **map;
    len = 0;
    while(str[len] != '\n' && str[len] != '\0')
        len++;
    if(validate_map2(str,len) < 3)
        return(0);
    i = validate_map2(str,len);
   map = ft_split(str, '\n', len, validate_map2(str,len));
    while((i - 1) != 0)
    {
        free(map[i - 1]);
        i--;
    }
    free(map);
    return(1);
}

int  validate_map2(char *str, int len)
{
    int line_len;
    int i;   
    int column;
    column = 0;
    i = 0;
    while(str[i] != '\0' && str)
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
        if(str[i] == '\0')
            break;
        i++;
    }
    column++;
    return(column);
}
