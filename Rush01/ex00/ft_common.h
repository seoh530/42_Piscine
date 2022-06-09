/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 01:47:24 by chanheki          #+#    #+#             */
/*   Updated: 2022/05/29 16:05:35 by seyoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __COMMON_H__
#define __COMMON_H__

#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int	ft_atoi(char *str);
int	ft_strlen(char *str);
int	*get_numbers(char *str, int length);
int	check(int ac, char **av);

int	check_row_col(int **board, int pos, int num, int length);
int	check_case(int **board, int pos, int *game, int length);

#endif
