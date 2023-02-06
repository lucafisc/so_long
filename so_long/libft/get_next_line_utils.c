/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:13:26 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/06 16:14:30 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strchr_nl(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

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

