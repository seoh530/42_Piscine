/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:42:27 by seyoh             #+#    #+#             */
/*   Updated: 2022/06/09 11:44:00 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag;

	i = -1;
	flag = 1;
	while (++i < length - 1 && flag)
		if (f(tab[i], tab[i + 1]) < 0)
			flag = 0;
	if (!flag)
	{
		flag = 1;
		i = -1;
		while (++i < length - 1)
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
	}
	return (1);
}
