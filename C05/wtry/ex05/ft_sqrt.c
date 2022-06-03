/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:59:41 by seyoh             #+#    #+#             */
/*   Updated: 2022/06/01 13:26:09 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	i;
	long long	result;

	i = 1;
	result = 1;
	if (nb == 0 || nb == 1)
		return (nb);
	while (result <= nb)
	{
		i++;
		result = i * i;
		if (result == nb)
			return (i);
	}
	return (0);
}
