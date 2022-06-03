/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:03:03 by seyoh             #+#    #+#             */
/*   Updated: 2022/06/04 00:51:24 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	exception_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || \
		(base[i] >= 9 && base[i] <= 13) || base[i] == 32)
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

int	minus_check(char *str)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (sign);
}

int	check(char *base, char x)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (x == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	put_atoi(char *str, char *base, int base_len)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (*str)
	{
		i = 0;
		if (check(base, *str) >= 0)
			num = num * base_len + check(base, *str);
		else
			break ;
		str++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sign;
	int	num;

	base_len = 0;
	num = 0;
	while (*str)
	{
		if ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		else
			break ;
	}
	sign = minus_check(str);
	while (*str == '+' || *str == '-')
		str++;
	if (exception_check(base) == 1)
	{
		while (base[base_len])
			base_len++;
		num = put_atoi(str, base, base_len);
	}
	return (sign * num);
}
int main()
{
		printf("======ex05======\n");
		char base[20] = "0123456789";
		char base1[20] = "01";
		char base2[20] = "0123456789ABCDEF";
		char base3[20] = "poneyvif";
		char base4[20] = "poneyviff";
		printf("%d\n", ft_atoi_base("4523816", base));
		printf("%d\n", ft_atoi_base("10001010000011100101000", base1));
		printf("%d\n", ft_atoi_base("450728", base2));
		printf("%d\n", ft_atoi_base("nonpeyvp", base3));
		printf("%d\n", ft_atoi_base("nonpeyvp", base4));
		printf("%d\n", ft_atoi_base("-2147483648", base));
		printf("%d\n", ft_atoi_base("-10000000000000000000000000000000", base1));
		printf("%d\n", ft_atoi_base("-80000000", base2));
		printf("%d\n", ft_atoi_base("-npppppppppp", base3));
		printf("%d\n", ft_atoi_base(" ---++--123dk456", base));
		printf("%d\n", ft_atoi_base(" ---++22--123dk456", base));
	}