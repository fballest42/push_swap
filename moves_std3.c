/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_std3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:02:12 by fballest          #+#    #+#             */
/*   Updated: 2022/03/08 23:13:45 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rev_rotate_b(int *stack, int len)
{
	int	tmp;

	ft_putstr_fd("rrb\n", 1);
	tmp = stack[len - 1];
	while (len > 0)
	{
		ft_swap(&(stack[len]), &(stack[len - 1]));
		len--;
	}
	stack[0] = tmp;
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	end_five_sort(t_stack *stack)
{
	int	ref;

	ref = get_max_pos(stack->a, stack->a_len);
	if (ref <= (stack->a_len / 2))
		while (ref-- >= 0)
			rotate_a(stack->a, stack->a_len);
	else
	{
		while (ref++ < stack->a_len - 1)
			rev_rotate_a(stack->a, stack->a_len);
	}
}
