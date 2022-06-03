/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:12:38 by seyoh             #+#    #+#             */
/*   Updated: 2022/05/28 16:22:56 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;

	src_len = 0;
	while (*src)
	{
		if (src_len + 1 < size)
		{
			*dest = *src;
			dest++;
		}
		src++;
		src_len++;
	}
	*dest = '\0';
	return (src_len);
}
