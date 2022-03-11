/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_std2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:08:19 by fballest          #+#    #+#             */
/*   Updated: 2022/03/10 22:04:37 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(int *stack, int len)
{
	int	i;

	ft_putstr_fd("ra\n", 1);
	i = 0;
	while (i + 1 < len)
	{
		swapper(&(stack[i]), &(stack[i + 1]));
		i++;
	}
}

void	rb(int *stack, int len)
{
	int	i;

	ft_putstr_fd("rb\n", 1);
	i = 0;
	while (i + 1 < len)
	{
		swapper(&(stack[i]), &(stack[i + 1]));
		i++;
	}
}

void	rr(t_data *stack)
{
	ra(stack->a, stack->len_a);
	rb(stack->b, stack->len_b);
}

void	rra(int *stack, int len)
{
	int	tmp;

	ft_putstr_fd("rra\n", 1);
	tmp = stack[len - 1];
	while (len > 0)
	{
		swapper(&(stack[len]), &(stack[len - 1]));
		len--;
	}
	stack[0] = tmp;
}

void	rrr(t_data *stack)
{
	ft_putstr_fd("rrr\n", 1);
	rra(stack->a, stack->len_a);
	rrb(stack->b, stack->len_b);
}
