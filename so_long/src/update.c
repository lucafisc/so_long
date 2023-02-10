/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:16:53 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/10 18:45:30 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	update(t_program *app)
{
	char	*moves;

	has_won(app);
	player_animation(app);
	if (has_lost(app))
		close_app(app);
	else if (!app->finish)
	{
		moves = ft_itoa(app->moves);
		egg_animation(&app->egg);
		enemy_animation(app);
		draw_walls(app);
		draw_exit(app);
		draw_eggs(app);
		draw_enemy(app);
		mlx_string_put(app->mlx, app->window.reference, app->img_size / 2 - 2,
			app->img_size / 2, 0xFFFFFF, moves);
		free(moves);
	}
	else
	{
		heart_animation(&app->heart);
		draw_hearts(app);
	}
	return (1);
}
