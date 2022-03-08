/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_std2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:08:19 by fballest          #+#    #+#             */
/*   Updated: 2022/03/08 23:12:57 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_a(int *stack, int len)
{
	int	i;

	ft_putstr_fd("ra\n", 1);
	i = 0;
	while (i + 1 < len)
	{
		ft_swap(&(stack[i]), &(stack[i + 1]));
		i++;
	}
}

void	rotate_b(int *stack, int len)
{
	int	i;

	ft_putstr_fd("rb\n", 1);
	i = 0;
	while (i + 1 < len)
	{
		ft_swap(&(stack[i]), &(stack[i + 1]));
		i++;
	}
}

void	rr(t_stack *stack)
{
	rotate_a(stack->a, stack->a_len);
	rotate_b(stack->b, stack->b_len);
}

void	rev_rotate_a(int *stack, int len)
{
	int	tmp;

	ft_putstr_fd("rra\n", 1);
	tmp = stack[len - 1];
	while (len > 0)
	{
		ft_swap(&(stack[len]), &(stack[len - 1]));
		len--;
	}
	stack[0] = tmp;
}

void	rrr(t_stack *stack)
{
	ft_putstr_fd("rrr\n", 1);
	rev_rotate_a(stack->a, stack->a_len);
	rev_rotate_b(stack->b, stack->b_len);
}
