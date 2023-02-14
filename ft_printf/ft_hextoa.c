/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:14 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/16 15:48:04 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_len_hex(unsigned long n)
{
	int	i;

	i = 1;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char	is_caps(char caps)
{
	if (caps == 'X')
		return ('A');
	else
		return ('a');
}

char	convert_to_hex(unsigned long n, char c)
{
	if (n % 16 <= 9)
		return ((n % 16) + '0');
	else
		return ((n % 16) - 10 + c);
}

char	*ft_hextoa(unsigned long n, char caps)
{
	int		i;
	int		len;
	char	*pt;
	char	c;

	len = get_len_hex(n);
	pt = malloc(sizeof(char) * (len));
	c = is_caps(caps);
	if (!pt)
		return (0);
	i = 0;
	while (n > 15)
	{
		pt[i++] = convert_to_hex(n, c);
		n = n / 16;
	}
	pt[i] = convert_to_hex(n, c);
	pt[++i] = '\0';
	ft_str_rev(pt);
	return (pt);
}
