/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_placeholder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:29:27 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/14 20:55:13 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_ph_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	is_percent_char(char c)
{
	if (c == '%')
		return (1);
	return (0);
}

int	ft_is_placeholder(char a, char b)
{
	if (is_percent_char(a) && is_ph_char(b))
		return (1);
	return (0);
}
