/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:55:04 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/09 22:52:25 by lde-ross         ###   ########.fr       */
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

static void	draw_hearts(t_program *app)
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
			if (i != app->exit.exit_vector.x || j != app->exit.exit_vector.y)
			{
				mlx_put_image_to_window(app->mlx, app->window.reference,
				app->heart.current_img, j * app->img_size, i * app->img_size);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void	draw_exit(t_program *app)
{
	char **matrix;
	t_vector	vector;

	vector = app->exit.exit_vector;
	matrix = (*app).map.matrix;
	if (app->collected)
	{
		mlx_put_image_to_window(app->mlx, app->window.reference,
		app->exit.exit_open_img, vector.y * app->img_size, vector.x * app->img_size);
	}
	else
	{
		mlx_put_image_to_window(app->mlx, app->window.reference,
		app->exit.exit_closed_img, vector.y * app->img_size, vector.x * app->img_size);
	}
		return ;
}

void	finish_game(t_program *app)
{
	ft_printf("%d finish", app->moves);
}

void	check_finish(t_program *app)
{
	if (app->player.position.y / app->img_size == app->exit.exit_vector.x && app->player.position.x / app->img_size == app->exit.exit_vector.y)
		app->finish = true;
	if (all_eggs_collected(app))
		open_exit(app);

}

int random_number() {
    static unsigned int seed = 1;
    seed = 1103515245 * seed + 12345;
    return (unsigned int)(seed / 65536) % 32768 % 4;
}

int	update(t_program *app)
{
	char	*moves;

	check_finish(app);	
	player_animation(app);
	if (!app->finish)
	{
		moves = ft_itoa(app->moves);
		egg_animation(&app->egg);
		draw_walls(app);
		draw_exit(app);
		draw_eggs(app);
		mlx_string_put(app->mlx, app->window.reference, app->img_size / 2 - 2, app->img_size / 2, 0xFFFFFF, moves);
		free(moves);
	}
	else
	{
		heart_animation(&app->heart);
		draw_hearts(app);
	}
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
