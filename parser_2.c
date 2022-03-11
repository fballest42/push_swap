/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:10:48 by fballest          #+#    #+#             */
/*   Updated: 2022/03/11 10:16:54 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_duplicate(int *stack, int len)
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
	while (ft_isdigit(str[i]))
		nb = nb * 10 + (str[i++] - 48);
	if (str[i] != '\0' && !ft_isdigit(str[i]))
		*bool = 1;
	return (nb * neg);
}

int	stack_a_init(int *stack, char **action, int len)
{
	int	i;
	int	bool;

	i = 0;
	bool = 0;
	while (i < len)
	{
		stack[i] = check_atoi(action[i], &bool);
		if (bool)
		{
			return (1);
		}
		i++;
	}
	if (check_duplicate(stack, len))
		return (1);
	return (0);
}

int	initial_data(t_data *stack, char **action)
{
	int		nb;

	nb = ft_matrixlen(action);
	stack->chunk = NULL;
	stack->a = (int *)malloc(sizeof(int) * (nb + 1));
	if (!stack->a)
		return (1);
	stack->b = (int *)malloc(sizeof(int) * (nb + 1));
	if (!stack->b)
		return (1);
	ft_bzero(stack->a, nb + 1);
	ft_bzero(stack->b, nb + 1);
	stack->len_a = nb;
	if (stack_a_init(stack->a, action, stack->len_a))
		return (1);
	stack->len_b = 0;
	return (0);
}
