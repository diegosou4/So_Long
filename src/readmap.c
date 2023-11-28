
#include "../includes/so_long.h"
#include <string.h>


int read_map(char *map)
{
    char    **line;
    char    *str;
    int fd = open(map, O_RDONLY);
    int i;
    int sizestr;
    sizestr = 1;
    i = 0;
    while(sizestr != 0)
    {
        printf("Entrou \n");
        str = get_next_line(fd);
        if(str == NULL)
            break;
        sizestr = strlen(str);
        if(sizestr != 0) 
            printf("%s\n",str);
        free(str);
    }
}
    