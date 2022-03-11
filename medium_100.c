/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:37:56 by fballest          #+#    #+#             */
/*   Updated: 2022/03/10 22:18:02 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_references(int *chunk, int len, int num)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (chunk[i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	lookfor_bigger(int *stack, int *ref, int len_s, int len_r)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = -2147483648;
	search_num(len_s, stack, &tmp, len_r);
	if (len_r)
	{
		while (i < len_s)
		{
			if (stack[i] > tmp && get_references(ref, len_r, stack[i]))
			{
				tmp = stack[i];
				i = -1;
			}
			i++;
		}
	}
	return (tmp);
}

void	chunk_start(t_data *stack)
{
	int			len;
	static int	rest;
	static int	div;
	static int	bool = 0;

	len = -1;
	start_order(&rest, &div, &bool, stack);
	stack->len_c = div;
	if (div + rest == stack->len_a)
		stack->len_c += rest;
	stack->chunk = (int *)malloc(sizeof(int) * (stack->len_c + 1));
	if (!stack->chunk)
		freeexit(stack, 0);
	while (++len < stack->len_c)
		stack->chunk[len] = lookfor_bigger(stack->a, stack->chunk, \
										stack->len_a, len);
	return ;
}

int	reserve_first(t_data *stack)
{
	int	i;

	i = 0;
	while (i < stack->len_a)
	{
		if (!get_references(stack->chunk, stack->len_c, stack->a[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	reserve_second(t_data *stack)
{
	int	i;

	i = stack->len_a - 1;
	while (i >= 0)
	{
		if (!get_references(stack->chunk, stack->len_c, stack->a[i]))
			return (i);
		i--;
	}
	return (-1);
}
