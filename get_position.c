/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:11:18 by fballest          #+#    #+#             */
/*   Updated: 2022/03/10 22:10:38 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	putit_up(t_data *stack, int pos)
{
	while (pos++ <= stack->len_a)
		rra(stack->a, stack->len_a);
	pa(stack);
}

void	putit_down(t_data *stack, int pos)
{
	while (pos-- > 1)
		ra(stack->a, stack->len_a);
	pa(stack);
}

void	switch_num(t_data *stack, int pos)
{
	if (pos == 0)
	{
		pb(stack);
		return ;
	}
	if ((stack->len_b / 2) <= pos)
	{
		while (pos++ < stack->len_b)
			rrb(stack->b, stack->len_b);
	}
	else
	{
		while (pos-- > 0)
			rb(stack->b, stack->len_b);
	}
	pb(stack);
}

void	up_number(t_data *stack, int pos)
{
	int	position;

	while (pos-- > 0)
		ra(stack->a, stack->len_a);
	position = getpos_number(stack->b, check_down(stack->b, stack->len_b, \
													stack->a[0]), stack->len_b);
	if (position == -1)
		position = getpos_max(stack->b, stack->len_b);
	switch_num(stack, position);
}

void	down_number(t_data *stack, int pos)
{
	int	position;

	while (pos-- >= 0)
		rra(stack->a, stack->len_a);
	position = getpos_number(stack->b, check_down(stack->b, stack->len_b, \
								stack->a[0]), stack->len_b);
	if (position == -1)
		position = getpos_max(stack->b, stack->len_b);
	switch_num(stack, position);
}
