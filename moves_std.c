/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:19:44 by fballest          #+#    #+#             */
/*   Updated: 2022/03/08 23:11:43 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(int *stack)
{
	int	tmp;

	ft_putstr_fd("sa\n", 1);
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	swap_b(int *stack)
{
	int	tmp;

	ft_putstr_fd("sb\n", 1);
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	ss(t_stack *stack)
{
	ft_putstr_fd("ss\n", 1);
	swap_a(stack->a);
	swap_b(stack->b);
}

void	push_a(t_stack *stack)
{
	int	tmp;

	ft_putstr_fd("pa\n", 1);
	if (stack->b_len == 0)
		return ;
	tmp = stack->a_len;
	while (--tmp >= 0)
		stack->a[tmp + 1] = stack->a[tmp];
	stack->a[0] = stack->b[0];
	stack->a_len++;
	tmp = -1;
	while (++tmp < stack->b_len)
		stack->b[tmp] = stack->b[tmp + 1];
	stack->b_len--;
}

void	push_b(t_stack *stack)
{
	int	tmp;

	ft_putstr_fd("pb\n", 1);
	if (stack->a_len == 0)
		return ;
	tmp = stack->b_len;
	while (--tmp >= 0)
		stack->b[tmp + 1] = stack->b[tmp];
	stack->b_len++;
	stack->b[0] = stack->a[0];
	tmp = -1;
	while (++tmp < stack->a_len)
		stack->a[tmp] = stack->a[tmp + 1];
	stack->a_len--;
}
