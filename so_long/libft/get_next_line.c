/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:59:32 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/06 16:15:32 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_newline_index(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*trim_after_newline(char *src)
{
	int		i;
	char	*new_str;
	int		extra;

	if (!src[0])
		return (NULL);
	i = get_newline_index(src);
	extra = 1;
	if (src[i] == '\n')
		extra++;
	new_str = malloc(sizeof(char) * (i + extra));
	if (!new_str)
		return (NULL);
	i = -1;
	while (src[++i] != '\n' && src[i])
		new_str[i] = src[i];
	if (src[i] == '\n')
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*trim_before_newline(char *src)
{
	int		i;
	int		len;
	int		j;
	char	*new_str;

	i = get_newline_index(src);
	if (src[i] == '\n')
		i++;
	if (!src[i])
	{
		free(src);
		return (NULL);
	}
	len = ft_strlen(src);
	new_str = malloc(sizeof(char) * (len - i + 1));
	if (!new_str)
		return (NULL);
	j = 0;
	while (src[i])
		new_str[j++] = src[i++];
	new_str[j] = '\0';
	free(src);
	return (new_str);
}

char	*read_file(char *stash, int fd)
{
	int		i;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	i = 1;
	while (i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
		{
			free(stash);
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		stash = ft_joinnfree(stash, buff);
		if (ft_strchr_nl(stash))
			break ;
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr_nl(stash))
		stash = read_file(stash, fd);
	if (!stash)
		return (NULL);
	line = trim_after_newline(stash);
	stash = trim_before_newline(stash);
	return (line);
}

