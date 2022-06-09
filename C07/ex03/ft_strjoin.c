/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 02:21:28 by seyoh             #+#    #+#             */
/*   Updated: 2022/06/09 09:53:39 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	str_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	length;

	length = 0;
	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			j++;
			length++;
		}
		i++;
	}
	i = 0;
	while (sep[i] != '\0')
		i++;
	length = length + i * (size - 1);
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(char) * 1);
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (str_len(size, strs, sep)) + 1);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			str[k++] = sep[j++];
		i++;
	}
	str[k] = '\0';
	return (str);
}
