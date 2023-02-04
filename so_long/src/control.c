/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:45:36 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/04 17:35:56 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int	key_event(int keycode, void *param)
{
	ft_printf("key pressed: %d\n", keycode);
	return ((*(int*)param));
}

void	hooks(t_program *app)
{
	mlx_key_hook(app->window.reference, key_event, &app);
}