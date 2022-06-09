/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:59:19 by seyoh             #+#    #+#             */
/*   Updated: 2022/06/06 11:46:23 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}

void	ft_putnbr(int nb)
{
	int		num;
	char	c_num;

	num = nb % 10;
	nb /= 10;
	if (num < 0 || nb < 0)
	{
		nb = nb * (-1);
		write(1, "-", 1);
		num = num * (-1);
	}
	c_num = num + '0';
	if (nb > 0)
		ft_putnbr(nb);
	write(1, &c_num, 1);
}

void	ft_show_tab(struct s_stock_str *str)
{
	int	i;

	i = 0;
	while (str[i].str)
	{
		ft_putstr(str[i].str);
		ft_putchar('\n');
		ft_putnbr(str[i].size);
		ft_putchar('\n');
		ft_putstr(str[i].copy);
		ft_putchar('\n');
		i++;
	}
}
