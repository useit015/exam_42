/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: useit015 <useit015@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 01:34:55 by useit015          #+#    #+#             */
/*   Updated: 2019/07/22 00:41:24 by useit015         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_palindrome(char *s)
{
	int len = ft_strlen(s);
	char tab[len][len];
	(void)ft_memset(tab, 0, sizeof(tab));
	for (int i = 0; i < len; i++)
		tab[i][i] = 1;
	int start = 0;
	int pal = 1;
	for (int i = 0; i < len - 1; i++)
		if (s[i] == s[i + 1])
		{
			tab[i][i + 1] = 1;
			start = i;
			pal = 2;
		}
	for (int k = 3; k <= len; k++)
		for (int i = 0; i <= len - k; i++)
		{
			int j = i + k - 1;
			if (tab[i + 1][j - 1] && s[i] == s[j])
			{
				tab[i][j] = 1;
				if (k > pal)
				{
					start = i;
					pal = k;
				}
			}
		}
	write(1, s + start, pal);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_palindrome(av[1]);
	ft_putchar(10);
}