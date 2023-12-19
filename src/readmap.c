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
    if(fd < 0)
        return(0);
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
    t_map smap;
    len = 0;
    while(str[len] != '\n' && str[len] != '\0')
        len++;
    if(validate_map2(str,len) < 3)
        return(0);
    i = validate_map2(str,len);
    int k;
    k =  validate_map2(str,len);
   map = ft_split(str, '\n', len, k );
    smap.map = map;
    smap.coletables = 0;
    smap.exit = 0;
    smap.player = 0;
    k = checkmap(map,k,len,&smap);
    while(i > 0)
    {
        i--;
        free(map[i]);
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

