/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reachable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:28:09 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/13 16:33:16 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_vector	get_p(t_map *map)
{
	int			i;
	int			j;
	char		**matrix;
	t_vector	position;

	i = -1;
	j = -1;
	position.x = -1;
	position.y = -1;
	matrix = map->matrix;
	while (matrix[++i])
	{
		while (matrix[i][++j])
		{
			if (matrix[i][j] == 'P')
			{
				position.x = j;
				position.y = i;
				return (position);
			}
		}
		j = 0;
	}
	return (position);
}

void	fill_all_collectibles(char **matrix, t_vector size, t_vector vector)
{
	if (vector.y < 1 || vector.y >= size.y - 1 || vector.x < 1
		|| vector.x >= size.x - 1
		|| matrix[vector.y][vector.x] == 'c'
		|| matrix[vector.y][vector.x] == 'o'
		|| matrix[vector.y][vector.x] == 'p'
		|| matrix[vector.y][vector.x] == 'S'
		|| matrix[vector.y][vector.x] == '1')
		return ;
	if (matrix[vector.y][vector.x] == 'C')
		matrix[vector.y][vector.x] = 'c';
	else if (matrix[vector.y][vector.x] == '0')
		matrix[vector.y][vector.x] = 'o';
	else if (matrix[vector.y][vector.x] == 'P')
		matrix[vector.y][vector.x] = 'p';
	else if (matrix[vector.y][vector.x] == 'E')
		matrix[vector.y][vector.x] = 'S';
	fill_all_collectibles(matrix, size, (t_vector){vector.x - 1, vector.y});
	fill_all_collectibles(matrix, size, (t_vector){vector.x + 1, vector.y});
	fill_all_collectibles(matrix, size, (t_vector){vector.x, vector.y - 1});
	fill_all_collectibles(matrix, size, (t_vector){vector.x, vector.y + 1});
}

t_bool	has_closed_path(t_map *map)
{
	t_vector	position;

	position = get_p(map);
	fill_all_collectibles(map->matrix, map->size, position);
	if (has_char(map, 'C') || has_char(map, 'E'))
		return (true);
	return (false);
}

t_bool	has_invalid_char(t_map *map)
{
	int			i;
	int			j;
	char		**matrix;

	i = -1;
	j = -1;
	matrix = map->matrix;
	while (matrix[++i])
	{
		while (matrix[i][++j])
		{
			if (!(matrix[i][j] == 'P'
				|| matrix[i][j] == 'E'
				|| matrix[i][j] == '1'
				|| matrix[i][j] == '0'
				|| matrix[i][j] == 'C'))
				return (true);
		}
		j = 0;
	}
	return (false);
}
