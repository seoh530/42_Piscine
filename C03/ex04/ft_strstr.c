/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:16:48 by seyoh             #+#    #+#             */
/*   Updated: 2022/05/28 20:13:10 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		while (str[i] == to_find[i])
		{
			if (to_find[++i] == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}
