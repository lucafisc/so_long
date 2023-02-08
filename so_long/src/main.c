/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:55:04 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/08 21:14:43 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

typedef	struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;


static void	draw_walls(t_program *app)
{
	int	i;
	int	j;
	char **matrix;

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
					app->wall.wall_img_2, j * app->img_size, i * app->img_size);
				else
				{
					if (i == 0 && j == 0)
						mlx_put_image_to_window(app->mlx, app->window.reference,
						app->wall.frame_img, j * app->img_size, i * app->img_size);
					else
						mlx_put_image_to_window(app->mlx, app->window.reference,
						app->wall.wall_img_1, j * app->img_size, i * app->img_size);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void	draw_eggs(t_program *app)
{
	int	i;
	int	j;
	char **matrix;

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

static void	draw_exit(t_program *app)
{
	int	i;
	int	j;
	char **matrix;

	i = 0;
	j = 0;
	matrix = (*app).map.matrix;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'E')
			{
				mlx_put_image_to_window(app->mlx, app->window.reference,
				app->exit.exit_closed_img, j * app->img_size, i * app->img_size);
				return ;
			}
			if (matrix[i][j] == 'e')
			{
				mlx_put_image_to_window(app->mlx, app->window.reference,
				app->exit.exit_open_img, j * app->img_size, i * app->img_size);
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	update(t_program *app)
{
	char	*moves;

	moves = ft_itoa(app->moves);
	player_animation(&app->player);
	egg_animation(&app->egg);
	draw_walls(app);
	draw_eggs(app);
	draw_exit(app);
	mlx_put_image_to_window(app->mlx, app->window.reference,
	 app->player.current_img, app->player.position.x, app->player.position.y);
	mlx_string_put(app->mlx, app->window.reference, app->img_size / 2 - 2, app->img_size / 2, 0xFFFFFF, moves);
	free(moves);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_program	app;

	if (argc != 2)
		invalid_args(argv[0]);
	else if (!map_is_valid(argv[1], &app.map))
		invalid_map(&app.map);
	else
	{
		init_game(&app);
		mlx_hook(app.window.reference, 17, 0, close_app, (void *)&app);
		mlx_key_hook(app.window.reference, *control, (void *)&app);
		mlx_loop_hook(app.mlx, update, (void *)&app);
		mlx_loop(app.mlx);
	}
	return (0);
}
