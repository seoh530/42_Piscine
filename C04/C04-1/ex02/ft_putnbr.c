/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:45:52 by seyoh             #+#    #+#             */
/*   Updated: 2022/05/30 18:22:46 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

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
	return ;
}
