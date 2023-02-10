/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:18:05 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/10 19:10:01 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_walls(t_program *app)
{
	int		i;
	int		j;
	char	**matrix;

	i = 0;
	j = 0;
	matrix = (*app).map.matrix;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == '1')
			{
				if ((*app).map.size.y == i + 1 || matrix[i + 1][j] != '1')
					mlx_put_image_to_window(app->mlx, app->window.reference,
						app->wall.wall_img_2, j * app->img_size,
						i * app->img_size);
				else
				{
					if (i == 0 && j == 0)
						mlx_put_image_to_window(app->mlx, app->window.reference,
							app->wall.frame_img, j * app->img_size,
							i * app->img_size);
					else
						mlx_put_image_to_window(app->mlx, app->window.reference,
							app->wall.wall_img_1, j * app->img_size,
							i * app->img_size);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_eggs(t_program *app)
{
	int		i;
	int		j;
	char	**matrix;

	i = 0;
	j = 0;
	matrix = (*app).map.matrix;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'C')
			{
				mlx_put_image_to_window(app->mlx, app->window.reference,
					app->egg.current_img, j * app->img_size, i * app->img_size);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_enemy(t_program *app)
{
	static int	move = 1000;

	if (move < 0)
	{
		move_enemy(app);
		mlx_clear_window(app->mlx, app->window.reference);
		move = 1000;
	}
	move--;
	mlx_put_image_to_window(app->mlx, app->window.reference,
		app->enemy.current_img, app->enemy.position.x * app->img_size,
		app->enemy.position.y * app->img_size);
}

void	draw_hearts(t_program *app)
{
	int		i;
	int		j;
	char	**matrix;

	i = 0;
	j = 0;
	matrix = (*app).map.matrix;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (i != app->exit.exit_vector.y || j != app->exit.exit_vector.x)
			{
				mlx_put_image_to_window(app->mlx, app->window.reference,
					app->heart.current_img, j * app->img_size,
					i * app->img_size);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_exit(t_program *app)
{
	char		**matrix;
	t_vector	vector;

	vector = app->exit.exit_vector;
	matrix = (*app).map.matrix;
	if (app->collected)
	{
		mlx_put_image_to_window(app->mlx, app->window.reference,
			app->exit.exit_open_img, vector.x * app->img_size,
			vector.y * app->img_size);
	}
	else
	{
		mlx_put_image_to_window(app->mlx, app->window.reference,
			app->exit.exit_closed_img, vector.x * app->img_size,
			vector.y * app->img_size);
	}
	return ;
}
