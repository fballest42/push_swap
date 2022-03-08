/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:10:48 by fballest          #+#    #+#             */
/*   Updated: 2022/03/08 23:22:21 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	parse_duplicate(int *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isnum(int ch)
{
	if (ch <= 57 && ch >= 48)
		return (1);
	return (0);
}

int	check_atoi(const char *str, int *bool)
{
	int	i;
	int	nb;
	int	neg;

	i = 0;
	nb = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	neg = 1;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isnum(str[i]))
		nb = nb * 10 + (str[i++] - 48);
	if (str[i] != '\0' && !ft_isnum(str[i]))
		*bool = 1;
	return (nb * neg);
}

int	init_a(int *stack, char **operation, int len)
{
	int	i;
	int	bool;

	i = 0;
	bool = 0;
	while (i < len)
	{
		stack[i] = check_atoi(operation[i], &bool);
		if (bool)
		{
			return (1);
		}
		i++;
	}
	if (parse_duplicate(stack, len))
		return (1);
	return (0);
}

int	init_stack(t_stack *stack, int nb, char **operation)
{
	stack->chunk = NULL;
	stack->a = (int *)malloc(sizeof(int) * (nb + 1));
	if (!stack->a)
		return (1);
	stack->b = (int *)malloc(sizeof(int) * (nb + 1));
	if (!stack->b)
		return (1);
	ft_bzero(stack->a, nb + 1);
	ft_bzero(stack->b, nb + 1);
	stack->a_len = nb;
	if (init_a(stack->a, operation, stack->a_len))
		return (1);
	stack->b_len = 0;
	return (0);
}
