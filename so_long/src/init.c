/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:59:17 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/10 17:59:49 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_setup(t_program *app)
{
	app->finish = false;
	app->collected = false;
	app->exit.exit_vector = get_exit_position(app);
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

void	imgs_setup_1(t_program *app)
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
}

void	imgs_setup_2(t_program *app)
{
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
	app->window = new_window(app->mlx, app->map.size.x * app->img_size,
			app->map.size.y * app->img_size, "so_long");
	imgs_setup_1(app);
	imgs_setup_2(app);
}
