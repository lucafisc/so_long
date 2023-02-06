/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:54:15 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/06 17:24:43 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_map_size(char *str, t_map *map)
{
	int	i;
	int	x;
	int	y;

	x = 0;
	i = 0;
	y = 1;
	while (str[x] != '\n')
		x++;
	while (str[i])
	{
		if (str[i] == '\n')
			y++;
		i++;
	}
	(*map).size.x = x;
	(*map).size.y = y;
}

t_bool	is_map_valid(char *str, t_map *map)
{
	int	fd;
	char *all;
	char **map;

	fd = open(str, O_RDONLY);
	//get_map_size(str, map);
	//ft_printf("map width is: %d and height is: %d", (*map).size.x, (*map).size.y);
	
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));

	return (false);
}