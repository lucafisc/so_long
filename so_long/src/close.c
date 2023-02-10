/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:27:38 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/10 19:37:12 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_images(t_program *app)
{
	mlx_destroy_image(app->mlx, app->player.player_img_1);
	mlx_destroy_image(app->mlx, app->player.player_img_2);
	mlx_destroy_image(app->mlx, app->egg.egg_img_1);
	mlx_destroy_image(app->mlx, app->egg.egg_img_2);
	mlx_destroy_image(app->mlx, app->egg.egg_img_3);
	mlx_destroy_image(app->mlx, app->wall.wall_img_1);
	mlx_destroy_image(app->mlx, app->wall.wall_img_2);
	mlx_destroy_image(app->mlx, app->wall.frame_img);
	mlx_destroy_image(app->mlx, app->exit.exit_closed_img);
	mlx_destroy_image(app->mlx, app->exit.exit_open_img);
	mlx_destroy_image(app->mlx, app->heart.heart_img_1);
	mlx_destroy_image(app->mlx, app->heart.heart_img_2);
	mlx_destroy_image(app->mlx, app->heart.heart_img_3);
	mlx_destroy_image(app->mlx, app->enemy.enemy_img_1);
	mlx_destroy_image(app->mlx, app->enemy.enemy_img_2);
}

int	close_app(void *param)
{
	t_program	*app;

	app = (t_program *)param;
	app->player.current_img = NULL;
	app->egg.current_img = NULL;
	free_map(&app->map);
	free_images(app);
	mlx_destroy_window(app->mlx, app->window.reference);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	exit(0);
	return (0);
}
