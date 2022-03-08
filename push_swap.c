/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:14:39 by fballest          #+#    #+#             */
/*   Updated: 2022/03/08 23:14:39 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	end_sort(t_stack *stack)
{
	int	ref;

	ref = get_max_pos(stack->b, stack->b_len);
	if (ref < (stack->b_len / 2))
		while (ref-- >= 1)
			rotate_b(stack->b, stack->b_len);
	else
	{
		while (ref++ < stack->b_len)
			rev_rotate_b(stack->b, stack->b_len);
	}
	while (stack->b_len)
		push_a(stack);
}

void	exit_main(t_stack *stack, int bool)
{
	if (stack->chunk)
		free(stack->chunk);
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack->oper)
		free_tab(stack->oper);
	if (bool)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	exit(0);
}

int	is_sort(t_stack *stack)
{
	int		i;
	int		prev;

	i = 1;
	if (stack->b_len != 0)
		return (1);
	prev = stack->a[0];
	while (i < stack->a_len)
	{
		if (prev > stack->a[i])
			return (1);
		prev = stack->a[i++];
	}
	return (0);
}

void	print_stack(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putnbr_fd(stack[i], 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.oper = NULL;
	stack.a = NULL;
	stack.b = NULL;
	stack.chunk = NULL;
	if (argc == 1)
		return (0);
	if (argc < 2 || check_num(argv) || \
		check_len(argv) || init_stack(&stack, argc - 1, argv + 1))
		exit_main(&stack, 1);
	if (execution(&stack))
		exit_main(&stack, 1);
	exit_main(&stack, 0);
	return (0);
}
