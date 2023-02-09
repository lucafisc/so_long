/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:34:51 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/09 22:46:41 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_animation(t_program *app)
{

	if (app->player.counter > app->player.total_frames)
		app->player.current_img = app->player.player_img_1;
	else
		app->player.current_img = app->player.player_img_2;
	if (app->player.counter > app->player.total_frames * 2)
		app->player.counter = 0;
	app->player.counter += 1;
	mlx_put_image_to_window(app->mlx, app->window.reference,
	 app->player.current_img, app->player.position.x, app->player.position.y);
}

void	egg_animation(t_egg *egg)
{
	if (egg->counter < egg->total_frames / 3)
		egg->current_img = egg->egg_img_1;
	else if (egg->counter <  egg->total_frames / 3 * 2)
		egg->current_img = egg->egg_img_2;
	else
		egg->current_img = egg->egg_img_3;
	if (egg->counter > egg->total_frames)
		egg->counter = 0;
	egg->counter += 1;
}

void	heart_animation(t_heart *heart)
{
	if (heart->counter < heart->total_frames / 4)
		heart->current_img = heart->heart_img_2;
	else if (heart->counter <  heart->total_frames / 4 * 2)
		heart->current_img = heart->heart_img_1;
	else if (heart->counter <  heart->total_frames / 4 * 3)
		heart->current_img = heart->heart_img_3;
	else
		heart->current_img = heart->heart_img_1;
	if (heart->counter > heart->total_frames)
		heart->counter = 0;
	heart->counter += 1;
}
