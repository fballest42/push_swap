/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:14:39 by fballest          #+#    #+#             */
/*   Updated: 2022/03/11 09:30:45 by fballest         ###   ########.fr       */
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
		freematrix(stack->oper);
	if (stack->spl)
		freematrix(stack->spl);
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

char	**num_counter(char **argv, t_data *stack)
{
	int		i;
	int		cnt;

	i = 1;
	cnt = 0;
	while (argv[i])
	{
		if (!check_space(argv[i]))
			cnt++;
		else
		{
			stack->spl = ft_split(argv[i], ' ');
			cnt = cnt + ft_matrixlen(stack->spl);
			freematrix(stack->spl);			
		}
		i++;
	}
	stack->spl = (char **)malloc(sizeof(char *) * (cnt + 1));
	return (stack->spl);
}

char	**number_tolist(char **argv, t_data *stack)
{
	int		i;
	int		j;
	int		k;
	char	**tmp2;

	i = 1;
	k = 0;
	while(argv[i])
	{
		if (!check_space(argv[i]))
			stack->spl[k++] = ft_strdup(argv[i++]);
		else
		{
			j = 0;
			tmp2 = ft_split(argv[i++], 32);
			while(tmp2[j])
				stack->spl[k++] = ft_strdup(tmp2[j++]);
			freematrix(tmp2);
		}
	}
	printf("AQUI I = %d\n", k);
	stack->spl[k] = NULL;
	return(stack->spl);
}

char	**get_list(char **argv, int argc, t_data *stack)
{

	if (argc == 2)
		stack->spl = ft_split(argv[1], ' ');
	else
	{
		num_counter(argv, stack);
		number_tolist(argv, stack);
	}
	return (stack->spl);
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
	// system("leaks push_swap");
	return (0);
}
