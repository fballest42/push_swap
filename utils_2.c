/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 09:58:00 by fballest          #+#    #+#             */
/*   Updated: 2022/03/10 22:18:02 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	search_num(int len_s, int *stack, int *tmp, int len_r)
{
	int	i;

	i = 0;
	if (!len_r)
	{
		while (i < len_s)
		{
			if (stack[i] > *tmp)
			{
				*tmp = stack[i];
				i = -1;
			}
			i++;
		}
	}
}

void	start_order(int *rest, int *div, int *bool, t_data *stack)
{
	if (!*bool)
	{
		*bool = 1;
		*rest = stack->len_a % 5;
		if (stack->len_a >= 500)
			*rest = stack->len_a % 11;
		*div = stack->len_a / 5;
		if (stack->len_a >= 500)
			*div = stack->len_a / 11;
	}
}
