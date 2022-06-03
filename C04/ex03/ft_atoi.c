/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:35:57 by seyoh             #+#    #+#             */
/*   Updated: 2022/05/31 22:37:18 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char *str)
{
	if ((*str >= 9 && *str <= 13) || *str == 32)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	result;
	int	minus_count;

	result = 0;
	minus_count = 0;
	while (is_space(str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus_count = !minus_count;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (minus_count == 1)
		return (-result);
	return (result);
}
