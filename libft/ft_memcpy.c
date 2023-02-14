/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:25:58 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/07 19:54:13 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pt_d;
	unsigned char	*pt_s;
	size_t			i;

	if (!dst && !src)
		return (0);
	pt_d = (unsigned char *)dst;
	pt_s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pt_d[i] = pt_s[i];
		i++;
	}
	return (dst);
}
