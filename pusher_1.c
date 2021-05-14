/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:08:19 by fballest          #+#    #+#             */
/*   Updated: 2021/05/14 12:41:27 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_midsort(t_chec *chec)
{
	int		x;

	x = 0;
	chec->blo = chec->totnum / 6;
	if ((chec->totnum - (6 * chec->blo)) > 0)
		chec->blo++;
	while (chec->totnum > 3 && x < 3)
	{
		if (chec->staint[0][0] > chec->staint[1][0] && chec->totnumb != 0)
		{
			ft_pushstack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "pb\n");
		}
		if (chec->staint[0][0] < chec->staint[1][0]
			&& chec->staint[0][0] > chec->staint[1][1] && chec->totnumb != 0)
		{
			ft_pushstack_b(chec);
			ft_swapstack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "pb\nsb\n");
		}
		if (chec->staint[0][0] < chec->staint[1][chec->totnumb - 1] && chec->totnumb != 0)
		{
			ft_pushstack_b(chec);
			ft_rotatestack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "pb\nrb\n");
		}
		if (chec->staint[0][0] > chec->staint[1][chec->totnumb - 1]
			&& chec->staint[0][0] < chec->staint[1][chec->totnumb - 2] && chec->totnumb != 0)
		{
			ft_rotrevstack_b(chec);
			ft_pushstack_b(chec);
			ft_rotatestack_b(chec);
			ft_rotatestack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "rrb\npb\nrb\nrb\n");
		}
		if (chec->totnum > 3)
		{
			ft_pushstack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "pb\n");
			x++;
		}
		if (x > 1)
			x = ft_mid_stab_order_b(chec, x);
	}
	ft_threesort_mid(chec);
	if (chec->totnum >= 3)
	{
		ft_insert_sta_b(chec);
		ft_midsort(chec);
	}
	while (chec->totnumb > 0)
		ft_insert_sta_a(chec);
	ft_order_stack_a(chec);
}

void	ft_mid_return_sta_a(t_chec *chec)
{
	int		y;

	y = chec->totnumb;
	while (y > 0)
	{
		ft_checpositions(chec);
		if (chec->posa == 0 && (chec->staint[1][0] < chec->staint[0][chec->totnum - 1]
			&& chec->staint[0][0] < chec->staint[0][chec->totnum]))
		{
			ft_rotrevstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "rra\n");
		}
		else if (chec->posa == 0 && chec->staint[1][0] > chec->staint[0][chec->totnum - 1])
		{
			ft_pushstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "pa\n");
			y--;
		}
		else if (chec->posb == 0 && chec->staint[1][0] < chec->staint[1][1])
		{
			ft_pushstack_a(chec);
			ft_rotatestack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "pa\nra\n");
			y--;
		}
		else if (chec->posb == 0 && chec->staint[1][0] > chec->staint[1][1])
		{
			ft_pushstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "pa\n");
			y--;
			while (chec->staint[0][0] > chec->staint[1][0] 
					&& chec->staint[1][0] > chec->staint[0][chec->totnum - 1])
			{
				ft_pushstack_a(chec);
				chec->instru = ft_strjoin(chec->instru, "pa\n");
				y--;
			}
		}
		else if (chec->posa == 1)
		{
			ft_pushstack_a(chec);
			ft_swapstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "pa\nsa\n");
			y--;
		}
		else if (chec->posa <= chec->posb)
		{
			while (chec->posa > 1)
			{
				ft_rotatestack_a(chec);
				chec->instru = ft_strjoin(chec->instru, "ra\n");
				chec->posa--;
				chec->posb++;
			}
			if (chec->staint[1][0] > chec->staint[0][0] && chec->staint[1][0] < chec->staint[0][1])
			{
				ft_pushstack_a(chec);
				ft_swapstack_a(chec);
				chec->instru = ft_strjoin(chec->instru, "pa\nsa\n");
				y--;
			}
		}
		else if (chec->posb < chec->posa)
		{
			while (chec->posb > 2)
			{
				ft_rotrevstack_a(chec);
				chec->instru = ft_strjoin(chec->instru, "rra\n");
				chec->posb--;
				chec->posa++;
			}
		}
		if (chec->staint[1][0] < chec->staint[0][0]
			&& chec->staint[0][chec->totnum - 1] > chec->staint[1][0])
		{
			while (chec->staint[0][chec->totnum - 1] < chec->staint[0][0]
				&& chec->staint[0][chec->totnum - 1] > chec->staint[1][0])
			{
				ft_rotrevstack_a(chec);
				chec->instru = ft_strjoin(chec->instru, "rra\n");
				chec->posb--;
			}
			if (chec->totnumb > 0)
			{
				ft_pushstack_a(chec);
				chec->instru = ft_strjoin(chec->instru, "pa\n");
				y--;
			}
		}
		if (chec->staint[1][0] < chec->staint[0][0] && chec->staint[0][chec->totnum - 1] > chec->staint[1][0] 
			&& chec->staint[0][chec->totnum - 1] < chec->staint[0][0])
		{
			ft_rotrevstack_a(chec);
			ft_pushstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "rra\npa\n");
			y--;
		}
		if (chec->staint[1][0] > chec->staint[0][0] && chec->staint[1][0] < chec->staint[0][1])
		{
			ft_pushstack_a(chec);
			ft_swapstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "pa\nsa\n");
			y--;
		}
	}
}

void	ft_checminpos_b(t_chec *chec)
{
	int		j;

	j = 0;
	chec->minnumb = chec->staint[1][0];
	chec->maxnumb = chec->staint[1][0];
	chec->minposb = 0;
	chec->maxposb = 0;
	while (j++ < chec->totnumb)
	{
		if (chec->minnumb > chec->staint[1][j - 1])
		{
			chec->minnumb = chec->staint[1][j - 1];
			chec->minposb = j - 1;
		}
		else if (chec->maxnumb < chec->staint[1][j - 1])
		{
			chec->maxnumb = chec->staint[1][j - 1];
			chec->maxposb = j - 1;
		}
	}
	chec->minposb = (chec->totnum - 1) - chec->minnum;
}
