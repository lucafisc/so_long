/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:53:22 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/10 19:18:42 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_vector	get_player_position(t_program *app)
{
	int			i;
	int			j;
	char		**matrix;
	t_vector	position;

	i = -1;
	j = -1;
	position.x = -1;
	position.y = -1;
	matrix = app->map.matrix;
	while (matrix[++i])
	{
		while (matrix[i][++j])
		{
			if (matrix[i][j] == 'P')
			{
				position.x = j;
				position.y = i;
				matrix[i][j] = '0';
				return (position);
			}
		}
		j = 0;
	}
	return (position);
}

t_vector	get_exit_position(t_program *app)
{
	t_vector	vector;
	char		**matrix;

	matrix = app->map.matrix;
	vector.y = 0;
	vector.x = 0;
	while (matrix[vector.y])
	{
		while (matrix[vector.y][vector.x])
		{
			if (matrix[vector.y][vector.x] == 'E')
			{
				return (vector);
			}
			vector.x++;
		}
		vector.y++;
		vector.x = 0;
	}
	return (vector);
}

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
	if (fd < 0)
		return ;
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
	map->allocated = true;
	free(all);
}

void	free_map(t_map *map)
{
	int		i;
	char	**matrix;

	if (!map->allocated)
		return ;
	i = 0;
	matrix = map->matrix;
	while (i < map->size.y)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
