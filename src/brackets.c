/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: useit015 <useit015@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:50:01 by useit015          #+#    #+#             */
/*   Updated: 2019/07/15 03:27:32 by useit015         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int i = -1;
	while (s[++i]);
	return i;
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int		ft_open(char c)
{
	return c == '(' || c == '{' || c == '[';
}

int		ft_close(char c)
{
	return c == ')' || c == '}' || c == ']';
}

int		ft_match(char c, char d)
{
	switch (c)
	{
		case '(':
			return d == ')';
		case '[':
			return d == ']';
		case '{':
			return d == '}';
		default:
			return 0;
	}
}

int		ft_brackets(char *s)
{
	int stack[1024] = {0};
	int i = -1;
	while (*s)
	{
		if (ft_open(*s))
			stack[++i] = *s;
		else if (ft_close(*s))
		{
			if (i < 0 || !ft_match(stack[i], *s))
				return 0;
			else
				stack[i--] = 0;
		}
		s++;
	}
	return i == -1;
}

int		main(int ac, char **av)
{
	if (ac > 1)
		for (int i = 1; i < ac; i++)
			ft_putstr(ft_brackets(av[i]) ? "OK\n" : "Error\n");
	else
		ft_putstr("\n");
	return 0;
}