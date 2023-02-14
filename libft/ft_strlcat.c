/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:20:03 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/16 15:02:37 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;

	slen = ft_strlen(src);
	if (dstsize == 0)
		return (slen);
	dlen = ft_strlen(dst);
	if (dstsize <= dlen)
		return (dstsize + slen);
	while (*dst && dstsize > 0)
	{
		dst++;
		dstsize--;
	}
	while (*src && dstsize > 1)
	{
		*dst = *src;
		dstsize--;
		dst++;
		src++;
	}
	*dst = '\0';
	return (slen + dlen);
}
