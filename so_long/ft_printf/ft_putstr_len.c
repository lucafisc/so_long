/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:08:34 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/14 19:43:18 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_len(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr_len("(null)"));
	while (s[i])
		i += ft_putchar_len(s[i]);
	return (i);
}
