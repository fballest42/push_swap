/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:49:46 by fballest          #+#    #+#             */
/*   Updated: 2022/03/11 10:21:19 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	number_check(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (arg[i][0] == '-' || arg[i][0] == '+')
				j++;
			if (!ft_isdigit(arg[i][j++]))
				return (1);
		}
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
			ft_freematrix(stack->spl);
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
	while (argv[i])
	{
		if (!check_space(argv[i]))
			stack->spl[k++] = ft_strdup(argv[i++]);
		else
		{
			j = 0;
			tmp2 = ft_split(argv[i++], 32);
			while (tmp2[j])
				stack->spl[k++] = ft_strdup(tmp2[j++]);
			ft_freematrix(tmp2);
		}
	}
	stack->spl[k] = NULL;
	return (stack->spl);
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
