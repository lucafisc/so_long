/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:27:24 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/10 19:17:24 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	random_number(void)
{
	static unsigned int	i = 1;

	i = 1103515245 * i + 12345;
	return ((unsigned int)(i / 65536) % 32768 % 4);
}

t_window	new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	return (window);
}
