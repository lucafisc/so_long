/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:25:16 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/01 17:27:17 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_bintoi(int binary[])
{
	int	n;
	int	i;
	int	power;

	n = 0;
	i = 0;
	power = 1;
	while (i < 32)
	{
		n += binary[i] * power;
		power *= 2;
		i++;
	}
	return (n);
}
