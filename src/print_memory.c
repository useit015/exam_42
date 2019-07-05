/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: useit015 <useit015@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:50:09 by useit015          #+#    #+#             */
/*   Updated: 2019/07/05 02:06:27 by useit015         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(unsigned char c)
{
	char *s = "0123456789abcdef";
	ft_putchar(s[c / 16]);
	ft_putchar(s[c % 16]);
}

void	ft_ascii_line(unsigned char *s, size_t size)
{
	for (size_t i = 0; i < size; i++)
		ft_putchar(s[i] > 31 && s[i] < 127 ? s[i] : '.');
	ft_putchar('\n');
}

void	ft_padding(int left)
{
	int len = left * 2 + left / 2 + left % 2;
	for (int i = 0; i < len; i++)
		ft_putchar(' ');
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char *s = (unsigned char *)addr;
	for (size_t i = 0; i < size; i++)
	{
		ft_puthex(s[i]);
		if (!((i + 1) % 16))
		{
			ft_putchar(' ');
			ft_ascii_line(s + i - 15, 16);
		}
		else if (i % 2)
			ft_putchar(' ');
	}
	int done = size % 16;
	if (done)
	{
		ft_padding(16 - done);
		ft_ascii_line(s + size - done, done);
	}
}

int		main(void)
{
	int	tab[10] = {0, 23, 150, 255, 12, 16,  21, 42};
	print_memory(tab, sizeof(tab));
	return 0;
}