/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:08:19 by fballest          #+#    #+#             */
/*   Updated: 2021/04/20 16:02:38 by fballest         ###   ########.fr       */
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
	if (chec->totnum > 3)
		ft_fewsort(chec);
	// if (chec->totnum > 6 && chec-> totnum < 13 && chec->totnumb == 0)
	// 	ft_midsort(chec);
	// if (chec->totnum > 12 && chec->totnum < 121 && chec->totnumb == 0)
	// 	ft_centsort(chec);
	// if (chec->totnum > 120 && chec->totnum < 240 && chec->totnumb == 0)
	// 	ft_totalsort(chec);
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
	if (chec->staint[0][0] > chec->staint[0][1] && chec->staint[0][0] < chec->staint[0][2])
	{
		ft_swapstack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "sa\n");
	}
	if (chec->staint[0][1] > chec->staint[0][0] && chec->staint[0][1] > chec->staint[0][2]
		&& chec->staint[0][0] < chec->staint[0][2])
	{
		ft_rotrevstack_a(chec);
		ft_swapstack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "rra\nsa\n");
	}
	if (chec->staint[0][1] > chec->staint[0][0] && chec->staint[0][1] > chec->staint[0][2]
		&& chec->staint[0][0] > chec->staint[0][2])
	{
		ft_rotrevstack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "rra\nsa\n");
	}
	ft_threesort_b(chec);
}

void	ft_threesort_b(t_chec *chec)
{
	if (chec->staint[0][0] > chec->staint[0][1] && chec->staint[0][0] > chec->staint[0][2]
		&& chec->staint[0][1] > chec->staint[0][2])
	{
		ft_rotatestack_a(chec);
		ft_swapstack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "ra\nsa\n");
	}
	if (chec->staint[0][0] > chec->staint[0][1] && chec->staint[0][0] > chec->staint[0][2]
		&& chec->staint[0][1] < chec->staint[0][2])
	{
		ft_rotatestack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "ra\n");
	}
}

void	ft_fewsort(t_chec *chec)
{
	while (chec->totnum > 3)
	{
		ft_pushstack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "pb\n");
	}
	ft_threesort(chec);
	ft_few_stab_a(chec);
	ft_few_stab_b(chec);
	ft_few_stab_c(chec);
}

void	ft_few_stab_a(t_chec *chec)
{
	if (chec->totnumb == 1)
	{
		if (chec->staint[1][0] > chec->staint[0][2])
		{
			ft_pushstack_a(chec);
			ft_rotatestack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "pa\nra\n");
		}
		if (chec->staint[1][0] > chec->staint[0][1])
		{
			ft_rotatestack_a(chec);
			ft_pushstack_a(chec);
			ft_rotrevstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "ra\npa\nrra\n");
		}
		if (chec->staint[1][0] > chec->staint[0][0])
		{
			ft_pushstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "pa\n");
		}
	}
}

void	ft_few_stab_b(t_chec *chec)
{
	if (chec->totnumb == 2)
	{
		if (chec->staint[1][0] < chec->staint[1][1])
		{
			ft_swapstack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "sa\n");
		}
		if (chec->staint[1][0] < chec->staint[0][0])
		{
			ft_pushstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "pa\n");
			ft_few_stab_a(chec);
		}
		if (chec->staint[1][0] > chec->staint[0][2])
		{
			ft_pushstack_a(chec);
			ft_rotatestack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "pa\nra\n");
			ft_few_stab_a(chec);
		}
		if (chec->staint[1][0] > chec->staint[0][0] && chec->staint[1][0] < chec->staint[0][1])
		{
			ft_pushstack_a(chec);
			ft_swapstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "pa\nsa\n");
		}
		if (chec->staint[1][0] > chec->staint[0][0] && chec->staint[1][0] > chec->staint[0][1])
		{
			ft_rotatestack_a(chec);
			ft_rotatestack_a(chec);
			ft_pushstack_a(chec);
			ft_rotrevstack_a(chec);
			ft_rotrevstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "rra\npa\nra\nra\n");
		}
		if (chec->staint[1][1] < chec->staint[0][0])
		{
			ft_rotatestack_b(chec);
			ft_pushstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "rb\npa\n");
			ft_few_stab_a(chec);
		}
		if (chec->staint[1][1] > chec->staint[0][2])
		{
			ft_swapstack_b(chec);
			ft_pushstack_a(chec);
			ft_rotatestack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "sb\npa\nra\n");
		}
		if (chec->staint[1][1] > chec->staint[0][0] && chec->staint[1][1] < chec->staint[0][1])
		{
			ft_swapstack_b(chec);
			ft_pushstack_a(chec);
			ft_swapstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "sb\npa\nsa\n");
		}

		if (chec->staint[1][1] > chec->staint[0][0] && chec->staint[1][1] > chec->staint[0][1])
		{
			ft_swapstack_b(chec);
			ft_rotrevstack_a(chec);
			ft_pushstack_a(chec);
			ft_rotatestack_a(chec);
			ft_rotatestack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "sb\nrra\npa\nra\nra\n");
		}
	}
}

void	ft_few_stab_c(t_chec *chec)
{
	int		x;

	x = chec->min;
}

void	ft_checpositions(t_chec *chec)
{
	int		x;

	x = 0;
	chec->min = chec->staint[0][0];
	chec->min2 = chec->staint[0][0];
	chec->max = chec->staint[0][0];
	chec->max2 = chec->staint[0][0];
	while (chec->staint[0][x])
	{
		if (chec->staint[0][x] < chec->min)
			chec->min = chec->staint[0][x];
		if (chec->staint[0][x] > chec->max)
			chec->max = chec->staint[0][x];
		if (chec->staint[0][x] < chec->min2 && chec->staint[0][x] > chec->min)
			chec->min2 = chec->staint[0][x];
		if (chec->staint[0][x] > chec->max2 && chec->staint[0][x] < chec->max)
			chec->min2 = chec->staint[0][x];
			
	}
}
