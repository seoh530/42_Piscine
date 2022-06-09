/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 01:41:06 by chanheki          #+#    #+#             */
/*   Updated: 2022/05/29 01:48:05 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_common.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	index;
	int	result;
	int	direction;

	index = 0;
	result = 0;
	direction = 1;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == ' ')
		index++;
	while (str[index] == '-' || str[index] == '+')
		if (str[index++] == '-')
			direction *= -1;
	while (str[index] >= '0' && str[index] <= '9')
		result = result * 10 + (str[index++] - '0');
	return (result * direction);
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr / 10 != 0)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}
