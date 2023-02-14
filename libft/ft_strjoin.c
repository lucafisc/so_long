/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:55:47 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/16 15:02:37 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*pt;
	int		i;

	if (!s1)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	pt = malloc(sizeof(char) * len);
	if (!pt)
		return (0);
	i = 0;
	while (*s1)
	{
		pt[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		pt[i] = *s2;
		i++;
		s2++;
	}
	pt[i] = '\0';
	return (pt);
}
