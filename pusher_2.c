/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:02:12 by fballest          #+#    #+#             */
/*   Updated: 2021/04/30 11:32:43 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_createcommands(t_chec *chec)
{
	chec->instru = ft_strdup("");
	if (chec->totnum == 1)
		chec->commands = "";
	if (chec->totnum == 2)
		ft_shortersort(chec);
	if (chec->totnum == 3)
		ft_threesort(chec);
	if (chec->totnum > 3 && chec->totnum < 6)
		ft_fewsort(chec);
	if (chec->totnum >= 6 && chec-> totnum < 501)
		ft_midsort(chec);
	if (chec->totnum > 500)
		ft_printerror("Error\n Too much numbers, pleaser insert numbers");
}

void	ft_shortersort(t_chec *chec)
{
	if (chec->staint[0][1] < chec->staint[0][0])
	{
		ft_swapstack_a(chec);
		chec->commands = ft_strjoin(chec->commands, chec->commands = "sa\n");
	}
	else
		chec->commands = ft_strjoin(chec->commands, chec->commands = "");
}

void	ft_threesort(t_chec *chec)
{
	if (chec->staint[0][0] > chec->staint[0][1]
		&& chec->staint[0][0] < chec->staint[0][2])
	{
		ft_swapstack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "sa\n");
	}
	if (chec->staint[0][1] > chec->staint[0][0]
		&& chec->staint[0][1] > chec->staint[0][2]
		&& chec->staint[0][0] < chec->staint[0][2])
	{
		ft_rotrevstack_a(chec);
		ft_swapstack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "rra\nsa\n");
	}
	if (chec->staint[0][1] > chec->staint[0][0]
		&& chec->staint[0][1] > chec->staint[0][2]
		&& chec->staint[0][0] > chec->staint[0][2])
	{
		ft_rotrevstack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "rra\nsa\n");
	}
	ft_threesort_b(chec);
}

void	ft_threesort_b(t_chec *chec)
{
	if (chec->staint[0][0] > chec->staint[0][1]
		&& chec->staint[0][0] > chec->staint[0][2]
		&& chec->staint[0][1] > chec->staint[0][2])
	{
		ft_rotatestack_a(chec);
		ft_swapstack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "ra\nsa\n");
	}
	if (chec->staint[0][0] > chec->staint[0][1]
		&& chec->staint[0][0] > chec->staint[0][2]
		&& chec->staint[0][1] < chec->staint[0][2])
	{
		ft_rotatestack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "ra\n");
	}
}

void	ft_fewsort(t_chec *chec)
{
	int		x;

	x = 0;
	while (chec->totnum > 3 && x < 2)
	{
		x++;
		ft_pushstack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "pb\n");
		if (chec->totnumb > 1)
			ft_few_stab_order_b(chec);
	}
	ft_threesort(chec);
	while (chec->totnumb > 0 && x > 0)
	{
		ft_insert_sta_a(chec);
		x--;
	}
	ft_order_stack_a(chec);
}
