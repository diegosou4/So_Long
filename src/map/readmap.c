/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:30:25 by diegmore          #+#    #+#             */
/*   Updated: 2023/12/19 12:30:27 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/so_long.h"
#include <string.h>


int read_map(char *map)
{
    int fd;
    char *str;
    int i;
    fd = open(map, O_RDONLY);
    if(fd < 0)
        return(0);
    else{
        str = open_read(fd);
    }
    i = validate_map(str);
    free(str);
    close(fd);
    return(i);
}
int validate_map(char *str)
{
    int lenchar;
    int i;
    t_map smap;
    int column;

    lenchar = len_map(str);
    column = validate_map2(str,lenchar);
   
    if(column < 3)
        return(print_e());
    smap.map = ft_split(str, '\n', lenchar, column);
    init_smap(&smap);
    i = checkmap(smap.map,column,lenchar,&smap);
    if(i == 0)
        print_error(smap, column);
//   flood_fill( smap.sy[0],smap.sx[0], smap);
    while(column > 0)
    {
        column--;
        free(smap.map[column]);
    }
    free(smap.map);
    return(column);
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

void flood_fill(int sy, int sx, t_map smap)
{
    static int colletables;
    static int exit;


    if(smap.map[sy][sx] == '1')
        return;
    
    if(smap.map[sy][sx] == 'C')
        colletables++;
    if(smap.map[sy][sx] == 'E')
        exit++;

    flood_fill(sy + 1, sx,smap);
    flood_fill(sy - 1, sx,smap);
    flood_fill(sy, sx + 1,smap);
    flood_fill(sy, sx - 1,smap);

    printf("%i coletavies, %i saida \n", colletables, exit );

}