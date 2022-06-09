/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 00:20:37 by seyoh             #+#    #+#             */
/*   Updated: 2022/06/06 22:41:02 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*str;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	str = (int *)malloc(sizeof(int) * (max - min));
	if (!str)
		return (-1);
	while (min < max)
		str[i++] = min++;
	*range = str;
	return (i);
}
