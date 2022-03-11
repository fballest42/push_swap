/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:11:18 by fballest          #+#    #+#             */
/*   Updated: 2022/03/11 10:22:10 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	getpos_max(int *stack, int len)
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

int	getpos_min(int *stack, int len)
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

int	getpos_number(int *stack, int num, int len)
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

int	check_up(int *stack, int len, int num)
{
	int	i;
	int	ref;

	i = 0;
	ref = stack[getpos_max(stack, len)];
	while (i < len)
	{
		if (stack[i] > num && stack[i] < ref)
			ref = stack[i];
		i++;
	}
	if (num > ref)
		return (stack[getpos_min(stack, len)]);
	return (ref);
}

int	check_down(int *stack, int len, int num)
{
	int	i;
	int	ref;

	i = 0;
	ref = stack[getpos_min(stack, len)];
	while (i < len)
	{
		if (stack[i] < num && stack[i] >= ref)
			ref = stack[i];
		i++;
	}
	if (num < ref)
		ref = stack[getpos_max(stack, len)];
	return (ref);
}
