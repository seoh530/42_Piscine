/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:39:06 by seyoh             #+#    #+#             */
/*   Updated: 2022/05/28 10:55:14 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int		type_num(char c);
char	ft_strupcase(char c);
char	ft_strlowcase(char c);

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 || !(type_num(str[i - 1])))
			str[i] = ft_strupcase(str[i]);
		else
			str[i] = ft_strlowcase(str[i]);
		i++;
	}
	return (str);
}

char	ft_strupcase(char c)
{
	if (c <= 'z' && c >= 'a')
		c -= 32;
	return (c);
}

char	ft_strlowcase(char c)
{
	if (c <= 'Z' && c >= 'A')
		c += 32;
	return (c);
}

int	type_num(char c)
{
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
		return (1);
	else if (c <= '9' && c >= '0')
		return (1);
	else
		return (0);
}
