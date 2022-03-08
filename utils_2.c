/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 09:58:00 by fballest          #+#    #+#             */
/*   Updated: 2022/03/08 23:22:26 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	find_it(int slen, int *stack, int *tmp, int rlen)
{
	int	i;

	i = 0;
	if (!rlen)
	{
		while (i < slen)
		{
			if (stack[i] > *tmp)
			{
				*tmp = stack[i];
				i = -1;
			}
			i++;
		}
	}
}

void	init_op(int *rest, int *div, int *bool, t_stack *stack)
{
	if (!*bool)
	{
		*bool = 1;
		*rest = stack->a_len % 5;
		if (stack->a_len >= 500)
			*rest = stack->a_len % 11;
		*div = stack->a_len / 5;
		if (stack->a_len >= 500)
			*div = stack->a_len / 11;
	}
}
