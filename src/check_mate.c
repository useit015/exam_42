/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: useit015 <useit015@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 03:33:29 by useit015          #+#    #+#             */
/*   Updated: 2019/07/22 00:56:22 by useit015         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *s)
{
	int i = -1;
	while (s[++i]);
	return i;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int		piece(char c)
{
	return c == 'K' || c == 'P' || c == 'R' || c == 'B' || c == 'Q';
}

int		pawn(char **b, int size, int x, int y, char c)
{
	if (y + 1 < size)
	{
		if (x + 1 < size && b[y + 1][x + 1] == c)
			return 1;
		if (x - 1 >= 0 && b[y + 1][x - 1] == c)
			return 1;
	}
	return 0;
}

int		rook(char **b, int size, int x, int y, char c)
{
	for (int i = y + 1; i < size; i++)
		if (piece(b[i][x]))
		{
			if (b[i][x] == c)
				return 1;
			else
				break;
		}
	for (int i = y - 1; i >= 0; i--)
		if (piece(b[i][x]))
		{
			if (b[i][x] == c)
				return 1;
			else
				break;
		}
	for (int i = x + 1; i < size; i++)
		if (piece(b[y][i]))
		{
			if (b[y][i] == c)
				return 1;
			else
				break;
		}
	for (int i = x - 1; i >= 0; i--)
		if (piece(b[y][i]))
		{
			if (b[y][i] == c)
				return 1;
			else
				break;
		}
	return 0;
}

int		bishop(char **b, int size, int x, int y, char c)
{
	for (int i = 1; i + y < size; i++)
		for (int j = 1; j + x < size; j++)
			if (i == j && piece(b[i + y][j + x]))
			{
				if (b[i + y][j + x] == c)
					return 1;
				else
					break;
			}
	for (int i = 1; i + y < size; i++)
		for (int j = 1; x - j >= 0; j++)
			if (i == j && piece(b[i + y][x - j]))
			{
				if (b[i + y][x - j] == c)
					return 1;
				else
					break;
			}
	for (int i = 1; y - i >= 0; i++)
		for (int j = x + 1; j < size; j++)
			if (i == j && piece(b[y - i][j + x]))
			{
				if (b[y - i][j + x] == c)
					return 1;
				else
					break;
			}
	for (int i = 1; y - i >= 0; i++)
		for (int j = 1; x - j >= 0; j++)
			if (i == j && piece(b[y - i][x - j]))
			{
				if (b[y - i][x - j] == c)
					return 1;
				else
					break;
			}
	return 0;
}

int		check_mate(char **b, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (b[i][j] == 'K')
			{
				if (pawn(b, size, j, i, 'P'))
					return 1;
				if (rook(b, size, j, i, 'R'))
					return 1;
				if (bishop(b, size, j, i, 'B'))
					return 1;
				if (bishop(b, size, j, i, 'Q') || rook(b, size, j, i, 'Q'))
					return 1;
			}
	return 0;
}

int		main(int ac, char **av)
{
	if (ac > 1)
		ft_putstr(check_mate(av + 1, ac - 1) ? "Success" : "Fail");
	ft_putchar(10);
}
