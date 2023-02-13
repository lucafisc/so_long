/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:22:56 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/13 16:07:14 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	has_won(t_program *app)
{
	if (app->player.position.y == app->exit.exit_vector.y
		&& app->player.position.x == app->exit.exit_vector.x)
		app->finish = true;
	if (collected_all(app))
		open_exit(app);
}

t_bool	has_lost(t_program *app)
{
	if (app->enemy.position.x == app->player.position.x
		&& app->enemy.position.y == app->player.position.y)
		return (true);
	return (false);
}

t_bool	collected_all(t_program *app)
{
	int		i;
	int		j;
	char	**matrix;

	matrix = app->map.matrix;
	i = 0;
	j = 0;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'c')
				return (false);
			j++;
		}
		i++;
		j = 0;
	}
	return (true);
}

t_bool	move_is_allowed(t_program *app, int key)
{
	int		x;
	int		y;
	char	**matrix;

	matrix = app->map.matrix;
	x = app->player.position.x;
	y = app->player.position.y;
	if (app->finish)
		return (false);
	else if ((key == 100 || key == 65363) && matrix[y][x + 1] != '1'
		&& matrix[y][x + 1] != 'S')
		return (true);
	else if ((key == 97 || key == 65361) && matrix[y][x - 1] != '1'
		&& matrix[y][x - 1] != 'S')
		return (true);
	else if ((key == 115 || key == 65364) && matrix[y + 1][x] != '1'
		&& matrix[y + 1][x] != 'S')
		return (true);
	else if ((key == 119 || key == 65362) && matrix[y - 1][x] != '1'
		&& matrix[y - 1][x] != 'S')
		return (true);
	return (false);
}
