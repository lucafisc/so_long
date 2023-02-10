/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:45:36 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/10 17:56:15 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	control(int key, void *param)
{
	t_program	*app;
	char		**matrix;

	if (key == 65307)
		close_app(param);
	app = (t_program *)param;
	matrix = app->map.matrix;
	mlx_clear_window(app->mlx, app->window.reference);
	if (move_is_allowed(app, key))
	{	
		if (key == 100 || key == 65363)
			app->player.position.x += 1;
		else if (key == 97 || key == 65361)
			app->player.position.x -= 1;
		else if (key == 115 || key == 65364)
			app->player.position.y += 1;
		else if (key == 119 || key == 65362)
			app->player.position.y -= 1;
		collect(app);
		app->moves += 1;
	}
	return (0);
}
