/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:17:40 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/08 19:01:13 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	invalid_map(t_map *map)
{
	free_map(map);
	ft_printf(BRED"Error\n", COLOR_RESET);
	ft_printf(BYEL"Invalid map\n", COLOR_RESET);
}

void	invalid_args(char *str)
{
	ft_printf(BRED"Error\n", str, COLOR_RESET);
	ft_printf(BYEL"Try ./%s <map.ber>\n", str, COLOR_RESET);
}
