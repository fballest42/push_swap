/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:11:18 by fballest          #+#    #+#             */
/*   Updated: 2022/03/08 23:22:19 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	insert_up(t_stack *stack, int pos)
{
	while (pos++ <= stack->a_len)
		rev_rotate_a(stack->a, stack->a_len);
	push_a(stack);
}

void	insert_down(t_stack *stack, int pos)
{
	while (pos-- > 1)
		rotate_a(stack->a, stack->a_len);
	push_a(stack);
}

void	insert_switch(t_stack *stack, int pos)
{
	if (pos == 0)
	{
		push_b(stack);
		return ;
	}
	if ((stack->b_len / 2) <= pos)
	{
		while (pos++ < stack->b_len)
			rev_rotate_b(stack->b, stack->b_len);
	}
	else
	{
		while (pos-- > 0)
			rotate_b(stack->b, stack->b_len);
	}
	push_b(stack);
}

void	push_up(t_stack *stack, int pos)
{
	int	position;

	while (pos-- > 0)
		rotate_a(stack->a, stack->a_len);
	position = get_num_position(stack->b, first_inf(stack->b, stack->b_len, \
													stack->a[0]), stack->b_len);
	if (position == -1)
		position = get_max_pos(stack->b, stack->b_len);
	insert_switch(stack, position);
}

void	push_down(t_stack *stack, int pos)
{
	int	position;

	while (pos-- >= 0)
		rev_rotate_a(stack->a, stack->a_len);
	position = get_num_position(stack->b, first_inf(stack->b, stack->b_len, \
								stack->a[0]), stack->b_len);
	if (position == -1)
		position = get_max_pos(stack->b, stack->b_len);
	insert_switch(stack, position);
}
