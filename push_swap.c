/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:14:39 by fballest          #+#    #+#             */
/*   Updated: 2022/03/10 11:06:49 by fballest         ###   ########.fr       */
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

int		check_space(char *str)
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

char	**splitter(char **argv)
{
	int		i;
	char	**sp;
	char	**arg;

	i = 1;
	sp = NULL;
	arg = NULL;
	arg = ft_calloc(sizeof(char *), 1);
	while (argv[i])
	{
		if (check_space(argv[i]))
		{
			sp = ft_split(argv[i], ' ');
			arg = ft_matrixrealloc(arg, sp, 1);
		}
		else
			arg = ft_matrixrealloc(arg, &argv[i], 2);
		i++;
	}
	return (arg);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	char	**spl;

	stack.oper = NULL;
	stack.a = NULL;
	stack.b = NULL;
	stack.chunk = NULL;
	spl = NULL;
	if (argc == 1)
		return (0);
	if (argc >= 2)
		spl = splitter(argv);
	if (check_num(spl) || check_len(spl)
		|| init_stack(&stack, spl))
		exit_main(&stack, 1);
	if (execution(&stack))
		exit_main(&stack, 1);
	exit_main(&stack, 0);
	return (0);
}
