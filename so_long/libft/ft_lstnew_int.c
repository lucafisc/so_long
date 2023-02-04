/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:52:45 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/19 17:04:20 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_int(int content)
{
	t_list	*pt;

	pt = malloc(sizeof(t_list));
	if (!pt)
		return (0);
	pt->content = malloc(sizeof(int));
	if (!pt->content)
	{
		free(pt);
		return (0);
	}
	*(int *)pt->content = content;
	pt->next = 0;
	return (pt);
}
