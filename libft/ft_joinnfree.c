/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinnfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:23:34 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/06 19:24:11 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinnfree(char *stash, char *buff)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	if (!buff)
		return (NULL);
	new_str = ft_calloc((ft_strlen(stash) + ft_strlen(buff) + 1), sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (stash[++i])
		new_str[i] = stash[i];
	while (buff[j])
	{
		new_str[i] = buff[j];
		i++;
		j++;
	}
	free(stash);
	return (new_str);
}
