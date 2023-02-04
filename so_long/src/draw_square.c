/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:52:47 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/04 17:35:39 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_square(t_program *app, int x, int y, int width, int height, int color)
{
	int	save_x;
	int	save_y;

	save_y = y;
	save_x = x;
	while (x++ < width + save_x)
	{
		while (y++ < height + save_y)
			mlx_pixel_put(app->mlx, app->window.reference, x, y, color);
		y = save_y;
	}
}