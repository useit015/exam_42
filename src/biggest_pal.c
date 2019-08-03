/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: useit015 <useit015@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 01:34:55 by useit015          #+#    #+#             */
/*   Updated: 2019/08/03 04:55:55 by useit015         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *s)
{
	int i = -1;
	while (s[++i]);
	return i;
}

void	*ft_memset(void *b, int c, size_t len)
{
	for (size_t i = 0; i < len; i++)
		((unsigned char*)b)[i] = c;
	return (b);
}

void	expand_palindrome(int index, int len, int *start, int *pal, char *s)
{
	int newLen, high, low;
	for (int i = 0; i < 2; i++)
	{
		low = index;
		high = index - i;
		while (--low >= 0 && ++high < len && s[low] == s[high])
		{
			newLen = high - low + 1;
			if (newLen > *pal)
			{
				*start = low;
				*pal = newLen;
			}
		}
	}
}

void	ft_palindrome(char *s)
{
	int pal = 1;
	int start = 0;
	int len = ft_strlen(s);
	for (int i = 1; i < len; ++i)
		expand_palindrome(i, len, &start, &pal, s);
	write(1, s + start, pal);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_palindrome(av[1]);
	ft_putchar(10);
}