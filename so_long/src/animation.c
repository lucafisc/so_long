/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:34:51 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/08 19:35:23 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_animation(t_player *player)
{
	if (player->counter > player->total_frames)
		player->current_img = player->player_img_1;
	else
		player->current_img = player->player_img_2;
	if (player->counter > player->total_frames * 2)
		player->counter = 0;
	player->counter += 1;
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
