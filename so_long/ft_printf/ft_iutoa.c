/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:01:33 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/14 19:46:59 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_ulen(unsigned int n)
{
	unsigned int	i;

	i = 1;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_iutoa(unsigned int n)
{
	unsigned int	len;
	int				i;
	char			*pt;

	len = get_ulen(n);
	pt = malloc(sizeof(char) * (len));
	if (!pt)
		return (0);
	i = 0;
	while (n > 9)
	{
		pt[i++] = (n % 10) + '0';
		n = n / 10;
	}
	pt[i] = n + '0';
	pt[++i] = '\0';
	ft_str_rev(pt);
	return (pt);
}
