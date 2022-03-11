/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:14:39 by fballest          #+#    #+#             */
/*   Updated: 2022/03/11 10:21:52 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	last_sorter(t_data *stack)
{
	int	ref;

	ref = getpos_max(stack->b, stack->len_b);
	if (ref < (stack->len_b / 2))
		while (ref-- >= 1)
			rb(stack->b, stack->len_b);
	else
	{
		while (ref++ < stack->len_b)
			rrb(stack->b, stack->len_b);
	}
	while (stack->len_b)
		pa(stack);
}

void	freeexit(t_data *stack, int bool)
{
	if (stack->chunk)
		free(stack->chunk);
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack->oper)
		ft_freematrix(stack->oper);
	if (stack->spl)
		ft_freematrix(stack->spl);
	if (bool)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	exit(0);
}

int	check_order(t_data *stack)
{
	int		i;
	int		prev;

	i = 1;
	if (stack->len_b != 0)
		return (1);
	prev = stack->a[0];
	while (i < stack->len_a)
	{
		if (prev > stack->a[i])
			return (1);
		prev = stack->a[i++];
	}
	return (0);
}

int	check_space(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	stack;

	stack.spl = NULL;
	stack.oper = NULL;
	stack.a = NULL;
	stack.b = NULL;
	stack.chunk = NULL;
	if (argc > 1 || (argc == 2 && check_space(argv[1])))
	{
		get_list(argv, argc, &stack);
		if (number_check(stack.spl) || size_check(stack.spl)
			|| initial_data(&stack, stack.spl))
			freeexit(&stack, 1);
		if (orderer(&stack))
			freeexit(&stack, 1);
		freeexit(&stack, 0);
	}
	return (0);
}
