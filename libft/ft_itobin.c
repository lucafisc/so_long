/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:25:28 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/01 17:27:08 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_itobin(int n)
{
	int	*binary;
	int	i;

	i = 0;
	binary = ft_calloc(32, sizeof(int));
	ft_memset(binary, 0, sizeof(binary));
	while (n > 0)
	{
		binary[i] = n % 2;
		n = n / 2;
		i++;
	}
	return (binary);
}
