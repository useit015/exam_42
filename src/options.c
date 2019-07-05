/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: useit015 <useit015@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 01:01:43 by useit015          #+#    #+#             */
/*   Updated: 2019/07/05 02:09:55 by useit015         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_islower(char c)
{
	return c >= 'a' && c <= 'z';
}

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

int		ft_parse(int *o, char *s, int *err)
{
	if (s[0] == '-')
	{
		s++;
		while (*s)
		{
			if (!ft_islower(*s))
			{
				*err = 1;
				return 0;
			}
			o['z' - *s + 6] = 1;
			s++;
		}
	}
	return 1;
}

void	ft_print(int *o)
{
	for (int i = 0; i < 32; i++)
	{
		if (i && !(i % 8))
			ft_putstr(" ");
		ft_putstr(o[i] ? "1" : "0");
	}
	ft_putstr("\n");
}

int		main(int ac, char **av)
{
	int err = 0;
	int usage = 0;
	int o[32] = {0};
	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
			if (!ft_parse(o, av[i], &err))
				break;
		usage = o[24];
	}
	else
		usage = 1;
	if (!usage && !err)
		ft_print(o);
	else if (err)
		ft_putstr("Invalid Option\n");
	else if (usage)
		ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
	return 0;
}