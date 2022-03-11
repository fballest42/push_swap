/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_std.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:19:44 by fballest          #+#    #+#             */
/*   Updated: 2022/03/10 22:03:19 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(int *stack)
{
	int	tmp;

	ft_putstr_fd("sa\n", 1);
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	sb(int *stack)
{
	int	tmp;

	ft_putstr_fd("sb\n", 1);
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	ss(t_data *stack)
{
	ft_putstr_fd("ss\n", 1);
	sa(stack->a);
	sb(stack->b);
}

void	pa(t_data *stack)
{
	int	tmp;

	ft_putstr_fd("pa\n", 1);
	if (stack->len_b == 0)
		return ;
	tmp = stack->len_a;
	while (--tmp >= 0)
		stack->a[tmp + 1] = stack->a[tmp];
	stack->a[0] = stack->b[0];
	stack->len_a++;
	tmp = -1;
	while (++tmp < stack->len_b)
		stack->b[tmp] = stack->b[tmp + 1];
	stack->len_b--;
}

void	pb(t_data *stack)
{
	int	tmp;

	ft_putstr_fd("pb\n", 1);
	if (stack->len_a == 0)
		return ;
	tmp = stack->len_b;
	while (--tmp >= 0)
		stack->b[tmp + 1] = stack->b[tmp];
	stack->len_b++;
	stack->b[0] = stack->a[0];
	tmp = -1;
	while (++tmp < stack->len_a)
		stack->a[tmp] = stack->a[tmp + 1];
	stack->len_a--;
}
