/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:59:17 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/08 19:22:41 by lde-ross         ###   ########.fr       */
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
	matrix = app->map.matrix;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'P')
			{
				position.x = j * app->img_size;
				position.y = i * app->img_size;
				return (position);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	game_setup(t_program *app)
{
	app->moves = 0;
	app->img_size = 64;
	app->egg.counter = 0;
	app->egg.total_frames = 1500;
	app->player.counter = 0;
	app->player.total_frames = 1500;
	app->player.position = get_player_position(app);
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
	app->egg.egg_img_1 = mlx_xpm_file_to_image(app->mlx,
		"sprites/egg1.xpm", &app->img_size, &app->img_size);
	app->egg.egg_img_2 = mlx_xpm_file_to_image(app->mlx,
		"sprites/egg2.xpm", &app->img_size, &app->img_size);
	app->egg.egg_img_3 = mlx_xpm_file_to_image(app->mlx,
		"sprites/egg3.xpm", &app->img_size, &app->img_size);
	app->exit.exit_open_img = mlx_xpm_file_to_image(app->mlx,
		"sprites/exitopen.xpm", &app->img_size, &app->img_size);
	app->exit.exit_closed_img = mlx_xpm_file_to_image(app->mlx,
		"sprites/exitclosed.xpm", &app->img_size, &app->img_size);
}

void	init_game(t_program *app)
{
	game_setup(app);
	app->mlx = mlx_init();
	app->window = new_window(app->mlx, app->map.size.x * app->img_size + app->img_size , app->map.size.y * app->img_size , "so_long");
	imgs_setup(app);
}