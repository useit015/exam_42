/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: useit015 <useit015@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:22:04 by useit015          #+#    #+#             */
/*   Updated: 2019/07/05 00:57:13 by useit015         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_isop(char c)
{
	return c == '+' || c == '*' || c == '-' || c == '/' || c == '%';
}

int		ft_isdigit(char c)
{
	return c >= '0' && c <= '9';
}

int		ft_isspace(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f';
}

int		ft_valid(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && !ft_isop(*s) && !ft_isspace(*s))
			return 0;
		s++;
	}
	return 1;
}

int		ft_calc(int *stack, int i, char op)
{
	int a = stack[i - 1];
	int b = stack[i];
	if (i < 1 || ((op == '/' || op == '%') && !b))
		return 0;
	switch (op)
	{
		case '+':
			stack[i - 1] = a + b;
			break;
		case '*':
			stack[i - 1] = a * b;
			break;
		case '-':
			stack[i - 1] = a - b;
			break;
		case '/':
			stack[i - 1] = a / b;
			break;
		case '%':
			stack[i - 1] = a % b;
			break;
	}
	stack[i] = 0;
	return 1;
}

void	ft_rpn_calc(char *s)
{
	int i = -1;
	int stack[1024] = {0};
	if (!ft_valid(s))
	{
		printf("Error\n");
		return;
	}
	while (*s)
	{
		if (ft_isdigit(*s))
		{
			stack[++i] = atoi(s);
			while (ft_isdigit(*s))
				s++;
		}
		else if (ft_isop(*s) && !ft_calc(stack, i--, *s))
		{
			printf("Error\n");
			return;
		}
		s++;
	}
	if (i)
		printf("Error\n");
	else
		printf("%d\n", stack[0]);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_rpn_calc(av[1]);
	else
		printf("Error\n");
	return 0;
}
