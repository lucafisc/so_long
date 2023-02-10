/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:55:00 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/10 19:15:22 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	collect(t_program *app)
{
	int		x;
	int		y;
	char	**matrix;

	matrix = app->map.matrix;
	x = app->player.position.x;
	y = app->player.position.y;
	if (matrix[y][x] == 'C')
		matrix[y][x] = '0';
}

void	open_exit(t_program *app)
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
			if (matrix[i][j] == 'E')
			{
				matrix[i][j] = 'e';
				return ;
			}
			j++;
		}
		i++;
		j = 0;
	}
	app->collected = true;
}

void	place_enemy(t_program *app)
{
	if (app->map.matrix[app->exit.exit_vector.y]
		[app->exit.exit_vector.x + 1] == '0')
	{
		app->enemy.position.y = app->exit.exit_vector.y;
		app->enemy.position.x = app->exit.exit_vector.x + 1;
	}
	else if (app->map.matrix[app->exit.exit_vector.y]
		[app->exit.exit_vector.x - 1] == '0')
	{
		app->enemy.position.y = app->exit.exit_vector.y;
		app->enemy.position.x = app->exit.exit_vector.x - 1;
	}
	else if (app->map.matrix[app->exit.exit_vector.y + 1]
		[app->exit.exit_vector.x] == '0')
	{
		app->enemy.position.y = app->exit.exit_vector.y + 1;
		app->enemy.position.x = app->exit.exit_vector.x ;
	}
	else if (app->map.matrix[app->exit.exit_vector.y - 1]
		[app->exit.exit_vector.x] == '0')
	{
		app->enemy.position.y = app->exit.exit_vector.y - 1;
		app->enemy.position.x = app->exit.exit_vector.x ;
	}
}

void	move_enemy(t_program *app)
{
	char	**matrix;
	int		move;

	move = random_number();
	matrix = app->map.matrix;
	if (move == 0
		&& matrix[app->enemy.position.y][app->enemy.position.x + 1] == '0')
		app->enemy.position.x++;
	else if (move == 1
		&& matrix[app->enemy.position.y][app->enemy.position.x - 1] == '0')
		app->enemy.position.x--;
	else if (move == 2
		&& matrix[app->enemy.position.y + 1][app->enemy.position.x] == '0')
		app->enemy.position.y++;
	else if (move == 3
		&& matrix[app->enemy.position.y - 1][app->enemy.position.x] == '0')
		app->enemy.position.y--;
	else
		move_enemy(app);
}
