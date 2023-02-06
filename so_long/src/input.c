/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:54:15 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/06 20:17:02 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_vector	get_map_size(char *str)
{
	int			i;
	t_vector	dim;

	dim.x = 0;
	dim.y = 1;
	i = 0;
	while (str[i] != '\n')
	{
		dim.x++;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			dim.y++;
		i++;
	}
	return (dim);
}

void	get_map(char *str, t_map *map)
{
	int		fd;
	char	*all;
	char	*temp;

	fd = open(str, O_RDONLY);
	all = ft_strdup("");
	temp = get_next_line(fd);
	while (temp)
	{
		all = ft_joinnfree(all, temp);
		free(temp);
		temp = get_next_line(fd);
	}
	map->matrix = ft_split(all, '\n');
	map->size = get_map_size(all);
	//free(all);
}

t_bool	is_map_valid(char *str, t_map *map)
{
	if (!ft_strnstr(str, ".ber", ft_strlen(str)))
		return (false);
	get_map(str, map);
	
	return (true);
}