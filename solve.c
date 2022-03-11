/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:51:25 by fballest          #+#    #+#             */
/*   Updated: 2022/03/10 22:16:17 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	exec_sorter(char *action, t_data *stack)
{
	if (!ft_strncmp(action, "sa", 3))
		sa(stack->a);
	else if (!ft_strncmp(action, "sb", 3))
		sb(stack->b);
	else if (!ft_strncmp(action, "ss", 3))
		ss(stack);
	else if (!ft_strncmp(action, "pa", 3))
		pa(stack);
	else if (!ft_strncmp(action, "pb", 3))
		pb(stack);
	else if (!ft_strncmp(action, "ra", 3))
		ra(stack->a, stack->len_a);
	else if (!ft_strncmp(action, "rb", 3))
		rb(stack->b, stack->len_b);
	else if (!ft_strncmp(action, "rr", 3))
		rr(stack);
	else if (!ft_strncmp(action, "rra", 4))
		rra(stack->a, stack->len_a);
	else if (!ft_strncmp(action, "rrb", 4))
		rrb(stack->b, stack->len_b);
	else if (!ft_strncmp(action, "rrr", 4))
		rrr(stack);
}

void	sort_three(t_data *stack)
{
	if (stack->len_a == 2 && stack->a[0] < stack->a[1])
		sa(stack->a);
	if (stack->len_a == 3)
	{
		if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] && \
			stack->a[2] > stack->a[0])
			sa(stack->a);
		else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
		{
			sa(stack->a);
			rra(stack->a, stack->len_a);
		}
		else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] && \
			stack->a[2] < stack->a[0])
			ra(stack->a, stack->len_a);
		else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] && \
			stack->a[2] > stack->a[0])
		{
			sa(stack->a);
			ra(stack->a, stack->len_a);
		}
		else
			rra(stack->a, stack->len_a);
	}
}

void	sort_five(t_data *stack)
{
	int	pos;

	while (stack->len_a != 3)
		pb(stack);
	if (!(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		sort_three(stack);
	while (stack->len_b != 0)
	{
		pos = getpos_number(stack->a, check_up(stack->a, stack->len_a, \
								stack->b[0]), stack->len_a);
		if (pos < (stack->len_a / 2))
			putit_down(stack, pos + 1);
		else
			putit_up(stack, pos + 1);
	}
	sort_last_five(stack);
}

void	sort_hundred(t_data *stack)
{
	int	hf;
	int	hs;
	int	nb;

	while (stack->len_a != 0)
	{
		chunk_start(stack);
		nb = 0;
		while (nb++ < stack->len_c)
		{
			hf = reserve_first(stack);
			hs = stack->len_a - 1 - reserve_second(stack);
			if (hf <= hs)
			{
				up_number(stack, hf);
			}
			else if (hs < hf)
			{
				down_number(stack, hs);
			}
		}
		free(stack->chunk);
		stack->chunk = NULL;
	}
	last_sorter(stack);
}

int	orderer(t_data *stack)
{
	if (!check_order(stack))
		return (0);
	if (stack->len_a == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack->a);
	}
	else if (stack->len_a == 3)
	{
		if (!(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
			sort_three(stack);
	}
	else if (stack->len_a <= 5 && stack->len_a > 3)
		sort_five(stack);
	else if (stack->len_a > 5 && stack->len_a > 3)
		sort_hundred(stack);
	return (0);
}
