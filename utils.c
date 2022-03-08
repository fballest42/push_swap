/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:11:18 by fballest          #+#    #+#             */
/*   Updated: 2022/03/08 23:10:50 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_max_pos(int *stack, int len)
{
	int	max;
	int	i;

	i = 0;
	if (len == 0)
		return (0);
	max = -2147483648;
	while (i < len)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	i = -1;
	while (++i < len)
		if (stack[i] == max)
			return (i);
	return (i);
}

int	get_min_pos(int *stack, int len)
{
	int	less;
	int	i;

	i = 0;
	if (len == 0)
		return (0);
	less = 2147483647;
	while (i < len)
	{
		if (stack[i] < less)
			less = stack[i];
		i++;
	}
	i = -1;
	while (++i < len)
		if (stack[i] == less)
			return (i);
	return (i - 1);
}

int	get_num_position(int *stack, int num, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (stack[i] == num)
			return (i);
		i++;
	}
	return (i);
}

int	first_sup(int *stack, int len, int num)
{
	int	i;
	int	ref;

	i = 0;
	ref = stack[get_max_pos(stack, len)];
	while (i < len)
	{
		if (stack[i] > num && stack[i] < ref)
			ref = stack[i];
		i++;
	}
	if (num > ref)
		return (stack[get_min_pos(stack, len)]);
	return (ref);
}

int	first_inf(int *stack, int len, int num)
{
	int	i;
	int	ref;

	i = 0;
	ref = stack[get_min_pos(stack, len)];
	while (i < len)
	{
		if (stack[i] < num && stack[i] >= ref)
			ref = stack[i];
		i++;
	}
	if (num < ref)
		ref = stack[get_max_pos(stack, len)];
	return (ref);
}