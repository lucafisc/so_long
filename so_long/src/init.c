/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:59:17 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/10 16:52:28 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_vector	get_player_position(t_program *app)
{
	int			i;
	int			j;
	char		**matrix;
	t_vector	position;
	
	i = 0;
	j = 0;
	position.x = -1;
	position.y = -1;
	matrix = app->map.matrix;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'P')
			{
				position.x = j * app->img_size;
				position.y = i * app->img_size;
				matrix[i][j] = '0';
				return (position);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (position);
}

t_vector	get_exit_vector(t_program *app)
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

void	place_enemy(t_program *app)
{
	char	**matrix;
	static	int	i = 1;

	matrix = app->map.matrix;
	if (matrix[app->exit.exit_vector.y][app->exit.exit_vector.x + 1] == '0')
	{
		app->enemy.position.y = app->exit.exit_vector.y;
		app->enemy.position.x = app->exit.exit_vector.x + 1;
	}
	else if (matrix[app->exit.exit_vector.y][app->exit.exit_vector.x - 1] == '0')
	{
		app->enemy.position.y = app->exit.exit_vector.y;
		app->enemy.position.x = app->exit.exit_vector.x - 1;
	}
	else if (matrix[app->exit.exit_vector.y + 1][app->exit.exit_vector.x ] == '0')
	{
		app->enemy.position.y = app->exit.exit_vector.y + 1;
		app->enemy.position.x = app->exit.exit_vector.x ;
	}
	else if (matrix[app->exit.exit_vector.y - 1][app->exit.exit_vector.x ] == '0')
	{
		app->enemy.position.y = app->exit.exit_vector.y - 1;
		app->enemy.position.x = app->exit.exit_vector.x ;
	}
	else
	{
		i++;
		place_enemy(app);
	}
}

void	game_setup(t_program *app)
{
	app->finish = false;
	app->collected = false;
	app->exit.exit_vector = get_exit_vector(app);
	ft_printf("exit coordinates x: %d y: %d\n", app->exit.exit_vector.x, app->exit.exit_vector.y);
	ft_printf("%c\n", app->map.matrix[app->exit.exit_vector.y][app->exit.exit_vector.x]);
	app->moves = 0;
	app->img_size = 64;
	app->egg.counter = 0;
	app->egg.total_frames = 1500;
	app->player.counter = 0;
	app->player.total_frames = 1500;
	app->player.position = get_player_position(app);
	app->heart.counter = 0;
	app->heart.total_frames = 1500;
	app->enemy.counter = 0;
	app->enemy.total_frames = 1500;
	place_enemy(app);
}

void	imgs_setup(t_program *app)
{
	app->player.player_img_1 = mlx_xpm_file_to_image(app->mlx,
			"sprites/player01.xpm", &app->img_size, &app->img_size);
	app->player.player_img_2 = mlx_xpm_file_to_image(app->mlx,
			"sprites/player02.xpm", &app->img_size, &app->img_size);
	app->wall.wall_img_1 = mlx_xpm_file_to_image(app->mlx,
		"sprites/wall1.xpm", &app->img_size, &app->img_size);
	app->wall.wall_img_2 = mlx_xpm_file_to_image(app->mlx,
		"sprites/wall2.xpm", &app->img_size, &app->img_size);
	app->wall.frame_img = mlx_xpm_file_to_image(app->mlx,
		"sprites/frame.xpm", &app->img_size, &app->img_size);
	app->egg.egg_img_1 = mlx_xpm_file_to_image(app->mlx,
		"sprites/egg1.xpm", &app->img_size, &app->img_size);
	app->egg.egg_img_2 = mlx_xpm_file_to_image(app->mlx,
		"sprites/egg2.xpm", &app->img_size, &app->img_size);
	app->egg.egg_img_3 = mlx_xpm_file_to_image(app->mlx,
		"sprites/egg3.xpm", &app->img_size, &app->img_size);
	app->exit.exit_closed_img = mlx_xpm_file_to_image(app->mlx,
		"sprites/exitclosed.xpm", &app->img_size, &app->img_size);
	app->exit.exit_open_img = mlx_xpm_file_to_image(app->mlx,
		"sprites/exitopen.xpm", &app->img_size, &app->img_size);
	app->heart.heart_img_1 = mlx_xpm_file_to_image(app->mlx,
		"sprites/heart1.xpm", &app->img_size, &app->img_size);
	app->heart.heart_img_2 = mlx_xpm_file_to_image(app->mlx,
		"sprites/heart2.xpm", &app->img_size, &app->img_size);
	app->heart.heart_img_3 = mlx_xpm_file_to_image(app->mlx,
		"sprites/heart3.xpm", &app->img_size, &app->img_size);
	app->enemy.enemy_img_1 = mlx_xpm_file_to_image(app->mlx,
		"sprites/cat1.xpm", &app->img_size, &app->img_size);
	app->enemy.enemy_img_2 = mlx_xpm_file_to_image(app->mlx,
		"sprites/cat2.xpm", &app->img_size, &app->img_size);
}

void	init_game(t_program *app)
{
	game_setup(app);
	app->mlx = mlx_init();
	app->window = new_window(app->mlx, app->map.size.x * app->img_size, app->map.size.y * app->img_size , "so_long");
	imgs_setup(app);
}