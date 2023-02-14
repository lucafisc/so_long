/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:54:15 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/13 16:27:45 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_bool	has_char(t_map *map, char c)
{
	int		i;
	int		j;
	char	**matrix;

	matrix = map->matrix;
	i = 0;
	j = 0;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == c)
				return (true);
			j++;
		}
		i++;
		j = 0;
	}
	return (false);
}

t_bool	has_only_one(t_map *map, char c)
{
	int		i;
	int		j;
	int		counter;
	char	**matrix;

	matrix = map->matrix;
	i = 0;
	j = 0;
	counter = 0;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == c)
				counter++;
			j++;
		}
		i++;
		j = 0;
	}
	if (counter == 1)
		return (true);
	return (false);
}

t_bool	is_rectangular(t_map *map)
{
	int		i;
	int		j;
	char	**matrix;

	matrix = map->matrix;
	i = 0;
	j = 0;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			j++;
		}
		if (j != map->size.x)
			return (false);
		i++;
		j = 0;
	}
	if (i != map->size.y)
		return (false);
	return (true);
}

t_bool	has_walls(t_map *map)
{	
	int		i;
	int		j;
	char	**matrix;

	matrix = map->matrix;
	i = 0;
	j = -1;
	while (++j < map->size.x)
	{
		if (matrix[0][j] != '1')
			return (false);
	}
	while (++i < map->size.y - 1)
	{
		if (matrix[i][0] != '1' || matrix[i][map->size.x - 1] != '1')
			return (false);
	}
	j = -1;
	while (matrix[i][++j])
	{
		if (matrix[i][j] != '1')
			return (false);
	}
	return (true);
}

t_bool	map_is_valid(char *str, t_map *map)
{
	map->allocated = false;
	if (!ft_strnstr(str, ".ber", ft_strlen(str)))
		return (false);
	get_map(str, map);
	if (!map->allocated || !has_char(map, 'C') || !has_char(map, 'E')
		|| !has_char(map, 'P') || !has_only_one(map, 'E')
		|| !has_only_one(map, 'P') || !is_rectangular(map) || !has_walls(map)
		|| has_invalid_char(map) || has_closed_path(map))
		return (false);
	return (true);
}
