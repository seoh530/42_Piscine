/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:05:49 by seyoh             #+#    #+#             */
/*   Updated: 2022/06/09 15:07:39 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	while (cmp(*tab, *tab))
	{
		return (0);
	}
}
