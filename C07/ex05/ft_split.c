/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoh <seyoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 09:40:52 by seyoh             #+#    #+#             */
/*   Updated: 2022/06/09 09:56:50 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separate(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (is_separate(str[i + 1], charset) == 1 \
			&& is_separate(str[i], charset) == 0)
			word++;
		i++;
	}
	return (word);
}

void	print_word(char *split, char *start, char *charset)
{
	int	i;

	i = 0;
	while (is_separate(start[i], charset) == 0)
	{
		split[i] = start[i];
		i++;
	}
	split[i] = '\0';
}

void	print_split(char **split, char *str, char *charset)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (is_separate(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (is_separate(str[i + j], charset) == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * j + 1);
			print_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		word;

	word = count_word(str, charset);
	split = (char **)malloc(sizeof(char *) * (word + 1));
	split[word] = 0;
	print_split(split, str, charset);
	return (split);
}
