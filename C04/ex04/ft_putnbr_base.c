/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:42:33 by seyoh             #+#    #+#             */
/*   Updated: 2022/05/30 18:41:10 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(char x)
{
	write(1, &x, 1);
}

int	exception_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	base_print(unsigned int nbr, char *base, unsigned int base_len)
{
	if (nbr >= base_len)
		base_print((nbr / base_len), base, base_len);
	print_char(base[nbr % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				i;
	unsigned int	nbr_2;

	i = 0;
	if (exception_check(base) == 1)
	{
		if (nbr < 0)
		{
			print_char('-');
			nbr_2 = (unsigned int)nbr * -1;
		}
		else
			nbr_2 = (unsigned int)nbr;
		while (base[i])
			i++;
		base_print(nbr_2, base, i);
	}
}
