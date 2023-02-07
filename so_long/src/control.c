/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:45:36 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/07 20:45:10 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_bool	move_is_allowed(t_program *app, int	key)
{
	int	x;
	int	y;
	char **matrix;
	
	matrix = app->map.matrix;
	x = app->player.position.x / 64;
	y = app->player.position.y / 64;
	if ((key == 100 || key == 65363) && matrix[y][x + 1] != '1')
		return (true);
	else if ((key == 97 || key == 65361) && matrix[y][x - 1] != '1')
		return (true);
	else if ((key == 115 || key == 65364) && matrix[y + 1][x] != '1')
		return (true);
	else if ((key == 119 || key == 65362) && matrix[y - 1][x] != '1')
		return (true);
	return (false);
}

t_bool	all_eggs_collected(t_program *app)
{
	int	i;
	int	j;
	char **matrix;

	matrix = app->map.matrix;
	i = 0;
	j = 0;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'C')
				return (false);
			j++;
		}
		
		i++;
		j = 0;
	}
	return (true);
}

void	collect_egg(t_program *app)
{
	int	x;
	int	y;
	char **matrix;

	matrix = app->map.matrix;
	x = app->player.position.x / 64;
	y = app->player.position.y / 64;
	if (matrix[y][x] == 'C')
		matrix[y][x] = '0';
}

void	open_exit(t_program *app)
{
	int	i;
	int	j;
	char **matrix;

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
}

int	control(int key, void *param)
{
	t_program *app;

	app = (t_program *)param;
	mlx_clear_window(app->mlx, app->window.reference);
	if (move_is_allowed(app, key))
	{	
		if (key == 100 || key == 65363)
			app->player.position.x += app->img_size;
		else if (key == 97 || key == 65361)
			app->player.position.x -= app->img_size;
		else if (key == 115 || key == 65364)
			app->player.position.y += app->img_size;
		else if (key == 119 || key == 65362)
			app->player.position.y -= app->img_size;
		collect_egg(app);
		if (all_eggs_collected(app))
			open_exit(app);
		app->moves += 1;
	}
	return (0);
}