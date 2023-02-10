/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:55:04 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/10 19:17:17 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_program	app;

	if (argc != 2)
		invalid_args(argv[0]);
	else if (!map_is_valid(argv[1], &app.map))
		invalid_map(&app.map);
	else
	{
		init_game(&app);
		mlx_hook(app.window.reference, 17, 0, close_app, (void *)&app);
		mlx_key_hook(app.window.reference, *control, (void *)&app);
		mlx_loop_hook(app.mlx, update, (void *)&app);
		mlx_loop(app.mlx);
	}
	return (0);
}
