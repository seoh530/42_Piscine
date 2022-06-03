/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:31:03 by seyoh             #+#    #+#             */
/*   Updated: 2022/05/28 20:18:20 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = 0;
	src_len = 0;
	while (*dest)
	{
		dest++;
		dest_len++;
	}
	while (*src && dest_len + src_len + 1 < size)
	{
		*dest++ = *src++;
		src_len++;
	}
	while (*src++ != '\0')
		src_len++;
	*dest = '\0';
	if (size <= dest_len)
		return (src_len + size);
	else
		return (src_len + dest_len);
}
