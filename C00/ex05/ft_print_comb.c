/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:49:27 by seyoh             #+#    #+#             */
/*   Updated: 2022/05/20 08:03:09 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_comb(void)
{
	char	hund;
	char	ten;
	char	one;

	hund = '0';
	while (hund <= '7')
	{
		ten = hund + 1;
		while (ten <= '8')
		{
			one = ten +1;
			while (one <= '9')
			{
				write(1, &hund, 1);
				write(1, &ten, 1);
				write(1, &one, 1);
				if (hund == '7' )
					return ;
				write(1, ", ", 2);
				one++;
			}
			ten++;
		}
		hund++;
	}
}
