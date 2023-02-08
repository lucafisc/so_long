/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:27:24 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/08 18:54:13 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_app(void *param)
{
	t_program *app;

	app = (t_program *)param;

	// mlx_destroy_image(app->mlx, app->player.player_img_1);
	// mlx_destroy_image(app->mlx, app->player.player_img_2);
	// mlx_destroy_image(app->mlx, app->player.current_img);
	// mlx_destroy_image(app->mlx, app->egg.egg_img_1);
	// mlx_destroy_image(app->mlx, app->egg.egg_img_2);
	// mlx_destroy_image(app->mlx, app->egg.egg_img_3);
	// mlx_destroy_image(app->mlx, app->egg.current_img);
	// mlx_destroy_image(app->mlx, app->wall.wall_img_1);
	// mlx_destroy_image(app->mlx, app->wall.wall_img_2);
	// mlx_destroy_image(app->mlx, app->exit.exit_closed_img);
	// mlx_destroy_image(app->mlx, app->exit.exit_open_img);
	mlx_destroy_window(app->mlx, app->window.reference);
	//free(app->mlx);
	exit(0);
	return ((*(int*)param));
}

t_window	new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	return (window);
}
