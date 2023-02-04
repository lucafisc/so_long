/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:43:02 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/16 15:29:08 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptrtoa(unsigned long i)
{
	char	*str;
	char	*pt;

	if (!i)
		return (ft_strdup("(nil)"));
	else
	{
		str = ft_hextoa(i, 0);
		pt = ft_strjoin("0x", str);
		free(str);
		return (pt);
	}
}
