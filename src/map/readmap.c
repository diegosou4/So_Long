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
    int i;
    t_map smap;
    smap.lenchar = len_map(str);
    smap.column = validate_map2(str,smap.lenchar);
    if(smap.column < 3)
        return(print_e());
    smap.map = ft_split(str, '\n', smap.lenchar, smap.column);
    smap.cpymap = ft_split(str, '\n', smap.lenchar, smap.column);
    init_smap(&smap);
    i = checkmap(smap.map,smap.column,smap.lenchar,&smap);
    if(i == 0)
        print_error(smap, smap.column);
    flood_fill( smap.sy[0],smap.sx[0], smap);
    i = end_valid(smap);
    if(i == 0)
    {
    while (smap.column > 0)
    {
        smap.column--;
        free(smap.map[smap.column]);
        free(smap.cpymap[smap.column]);
    }
         free(smap.cpymap);
         free(smap.map);
    print_error(smap, smap.column);
    }
        
    else
    {
        write(1, "O pai passou aqui bebe\n",23);
    }
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



void flood_fill(int sy, int sx, t_map smap)
{

    if(smap.cpymap[sy][sx] == '1' || smap.cpymap[sy][sx] == '3')
        return;
    if(smap.cpymap[sy][sx] == 'C')
        smap.coletables[1] += 1;
    if(smap.cpymap[sy][sx] == 'E')
        smap.exit[1] += 1;

    smap.cpymap[sy][sx] = '3';
    flood_fill(sy + 1, sx,smap);
    flood_fill(sy - 1, sx,smap);
    flood_fill(sy, sx + 1,smap);
    flood_fill(sy, sx - 1,smap);
}
