/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:54:15 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/07 21:25:07 by lde-ross         ###   ########.fr       */
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

t_bool	has_char(t_map *map, char c)
{
	int	i;
	int	j;
	char **matrix;

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
	else
		return (false);
}

t_bool	is_map_valid(char *str, t_map *map)
{
	if (!ft_strnstr(str, ".ber", ft_strlen(str)))
		return (false);
	get_map(str, map);
	if (!has_char(map, 'C') || !has_char(map, 'E') || !has_char(map, 'P'))
		return (false);
	if (!has_only_one(map, 'E') || !has_only_one(map, 'P'))
		return (false);
	return (true);
}