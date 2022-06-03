/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:57:52 by seyoh             #+#    #+#             */
/*   Updated: 2022/05/26 14:21:26 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	cvt_hexa(char *str)
{
	write(1, &"0123456789abcdef"[(unsigned char)(*str) / 16], 1);
	write(1, &"0123456789abcdef"[(unsigned char)(*str) % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (! (*str >= 32 && *str <= 126))
		{
			write(1, "\\", 1);
			cvt_hexa(str);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
}
