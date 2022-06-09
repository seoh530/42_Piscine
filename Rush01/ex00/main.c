/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:04:05 by chanheki          #+#    #+#             */
/*   Updated: 2022/05/29 08:23:05 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_common.h"

int	check_row_col(int **board, int pos, int num, int length)
{
	int	i;

	i = 0;
	while (i < (pos / length))
	{
		if (board[i][pos % length] == num)
			return (1);
		i++;
	}
	i = 0;
	while (i < (pos % length))
	{
		if (board[pos / length][i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	check_col_up(int **board, int pos, int *game, int length)
{
	int	i;
	int	max;
	int	visible_boxs;

	i = 0;
	max = 0;
	visible_boxs = 0;
	if ((pos / length) == (length - 1))
	{
		while (i < length)
		{
			if (board[i][pos % length] > max)
			{
				max = board[i][pos % length];
				visible_boxs++;
			}
			i++;
		}
		if (game[pos % length] != visible_boxs)
			return (1);
	}
	return (0);
}

int	check_row_right(int **board, int pos, int *game, int length)
{
	int	i;
	int	max_size;
	int	visible_boxs;

	i = length;
	max_size = 0;
	visible_boxs = 0;
	if (pos % length == length - 1)
	{
		while (--i >= 0)
		{
			if (board[pos / length][i] > max_size)
			{
				max_size = board[pos / length][i];
				visible_boxs++;
			}
		}
		if (game[(length * 3) + pos / length] != visible_boxs)
			return (1);
	}
	return (0);
}

int	check_col_down(int **board, int pos, int *game, int length)
{
	int	i;
	int	max;
	int	visible_boxs;

	i = length - 1;
	max = 0;
	visible_boxs = 0;
	if ((pos / length) == (length - 1))
	{
		while (i >= 0)
		{
			if (board[i][pos % length] > max)
			{
				max = board[i][pos % length];
				visible_boxs++;
			}
			i--;
		}
		if (game[length + pos % length] != visible_boxs)
			return (1);
	}
	return (0);
}

int	check_row_left(int **board, int pos, int *game, int length)
{
	int	i;
	int	max;
	int	visible_boxs;

	i = 0;
	max = 0;
	visible_boxs = 0;
	if (pos % length == length - 1)
	{
		while (i < length)
		{
			if (board[pos / length][i] > max)
			{
				max = board[pos / length][i];
				visible_boxs++;
			}
			i++;
		}
		if (game[(length * 2) + (pos / length)] != visible_boxs)
			return (1);
	}
	return (0);
}

int	check_case(int **board, int pos, int *game, int length)
{
	if (check_row_left(board, pos, game, length) == 1)
		return (1);
	if (check_row_right(board, pos, game, length) == 1)
		return (1);
	if (check_col_down(board, pos, game, length) == 1)
		return (1);
	if (check_col_up(board, pos, game, length) == 1)
		return (1);
	return (0);
}


// solve 함수
// row, col 에서 내가 넣을 번호가 중복되는지 확인.
// 한 라인이 다 채워졌을 경우 해당하는 번호가 맞게 들어가 있는지 확인.
// 다음 가능한 번호가 있는지 확인
// 재귀로 모든경우 무한반복.

int	solve(int **board, int *game, int pos, int length)
{
	int	size;

	if (pos == (length * length))
		return (1);
	size = 1;
	while (size <= length)
	{
		if (check_row_col(board, pos, size, length) == 0)
		{
			board[pos / length][pos % length] = size;
			if (check_case(board, pos, game, length) == 0)
			{
				if (solve(board, game, pos + 1, length) == 1)
					return (1);
			}
			else
				board[pos / length][pos % length] = 0;
		}
		size++;
	}
	return (0);
}

/* ============= main ============== */

int	ft_check_argument(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (ft_strlen(argv[1]) == 31)
		return (4);
	if (ft_strlen(argv[1]) == 39)
		return (5);
	if (ft_strlen(argv[1]) == 47)
		return (6);
	if (ft_strlen(argv[1]) == 56)
		return (7);
	if (ft_strlen(argv[1]) == 63)
		return (8);
	if (ft_strlen(argv[1]) == 71)
		return (9);
	return (0);
}

int	*get_numbers(char *str, int length)
{
	int	i;
	int	j;
	int	*line;

	line = (int *) malloc(sizeof(int) * (length * length));
	if (!(line))
		return (0);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			line[j] = ft_atoi(str + i);
			j++;
		}
		i++;
	}
	return (line);
}

void	display_solution(int **board, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length)
		{
			ft_putnbr(board[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	board_init(int **board, int length)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < length)
	{
		while (j < length)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

void ft_progress(int **board, int length, char **argv)
{
	int *game;
	
	board_init(board, length);
	game = get_numbers(argv[1], length);
	if (solve(board, game, 0, length))
		display_solution(board, length);
	else
		write(1, "Error \n", 8);
}

int	main(int argc, char **argv)
{
	int	**board;
	int	length;
	int	i;

	length = ft_check_argument(argc, argv);
	if (length == 0)
		return (0);
	board = (int **)malloc(sizeof(int *) * length);
	i = 0;
	while (i < length)
	{
		board[i] = (int *)malloc(sizeof(int) * length);
		i++;
	}
	ft_progress(board, length, argv);
	i = 0;
	while (i < length)
	{
		free(board[i]);
		i++;
	}
	free(board);
	return (0);
}
