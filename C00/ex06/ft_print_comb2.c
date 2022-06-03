/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:11:52 by seyoh             #+#    #+#             */
/*   Updated: 2022/05/23 12:30:10 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	i;	
	int	j;	

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_put_char((i / 10) + '0');
			ft_put_char((i % 10) + '0');
			ft_put_char(' ');
			ft_put_char((j / 10) + '0');
			ft_put_char((j % 10) + '0');
			if (i != 98)
			{
				ft_put_char(',');
				ft_put_char(' ');
			}
			j++;
		}
		i++;
	}
}
