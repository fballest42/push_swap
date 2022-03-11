/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_std3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:02:12 by fballest          #+#    #+#             */
/*   Updated: 2022/03/10 22:05:28 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rrb(int *stack, int len)
{
	int	tmp;

	ft_putstr_fd("rrb\n", 1);
	tmp = stack[len - 1];
	while (len > 0)
	{
		swapper(&(stack[len]), &(stack[len - 1]));
		len--;
	}
	stack[0] = tmp;
}

void	swapper(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_last_five(t_data *stack)
{
	int	ref;

	ref = getpos_max(stack->a, stack->len_a);
	if (ref <= (stack->len_a / 2))
		while (ref-- >= 0)
			ra(stack->a, stack->len_a);
	else
	{
		while (ref++ < stack->len_a - 1)
			rra(stack->a, stack->len_a);
	}
}
