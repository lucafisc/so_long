/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:45:36 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/07 17:56:36 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_bool	allowed_move(t_map *map, )
{
	
}

int	control(int key, void *param)
{
	t_program *app;
	app = (t_program *)param;
	mlx_clear_window(app->mlx, app->window.reference);
	if (key == 100)
		app->player.position.x += app->img_size;
	else if (key == 97)
		app->player.position.x -= app->img_size;
	else if (key == 115)
		app->player.position.y += app->img_size;
	else if (key == 119)
		app->player.position.y -= app->img_size;
	app->moves += 1;
	printf("Key pressed -> %d\n", key);
	return (0);
}