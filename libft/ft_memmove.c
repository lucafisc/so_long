/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:33:31 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/16 15:02:37 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pt_d;
	unsigned char	*pt_s;

	if (!dst && !src)
		return (NULL);
	pt_d = (unsigned char *)dst;
	pt_s = (unsigned char *)src;
	if (pt_d <= pt_s)
	{
		return (ft_memcpy(pt_d, pt_s, len));
	}
	while (len > 0)
	{
		pt_d[len - 1] = pt_s[len - 1];
		len--;
	}
	return (dst);
}
