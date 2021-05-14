/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:14:39 by fballest          #+#    #+#             */
/*   Updated: 2021/05/11 11:48:53 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_few_stab_order_b(t_chec *chec)
{
	if (chec->totnumb == 2)
	{
		if (chec->staint[1][0] < chec->staint[1][1])
		{
			ft_swapstack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "sb\n");
		}
	}
	if (chec->totnumb == 3)
	{
		if (chec->staint[1][0] < chec->staint[1][chec->totnumb - 1])
		{
			ft_rotatestack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "rb\n");
		}
		if (chec->staint[1][0] < chec->staint[1][1])
		{
			ft_swapstack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "sb\n");
		}
	}
}

void	ft_few_stab_back_a(t_chec *chec)
{
	int		i;

	i = 0;
	while (chec->staint[1][0] < chec->staint[0][0] && chec->totnumb > 0)
	{
		ft_pushstack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "pa\n");
	}
	while (chec->staint[1][0] > chec->staint[0][chec->totnum - 1]
			&& chec->totnumb > 0)
	{
		ft_pushstack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "pa\n");
		i++;
	}
	while (i-- > 0)
	{
		ft_rotatestack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "rra\n");
	}
	ft_insert_sta_a(chec);
}

void	ft_checpositions(t_chec *chec)
{
	int		y;

	y = 0;
	chec->posa = 0;
	chec->posb = 0;
	if (chec->staint[1][0] < chec->minnum)
		chec->posa = chec->minpos;
	else if (chec->staint[1][0] > chec->maxnum)
		chec->posa = chec->maxpos + 1;
	else
	{
		while (y < chec->totnum - 1)
		{
			if ((chec->staint[1][0] > chec->staint[0][y]
				&& chec->staint[1][0] < chec->staint[0][y + 1])
				|| (chec->staint[1][0] < chec->staint[0][y]
				&& chec->staint[1][0] > chec->staint[0][y + 1]))
				chec->posa = y + 1;
			y++;
		}
	}
	if (chec->posb == 0)
		chec->posb = chec->totnum - chec->posa;
}

void	ft_checpositions_2(t_chec *chec)
{
	int		y;

	y = 0;
	chec->pos2a = 0;
	chec->pos2b = 0;
	ft_checminpos(chec);
	if (chec->staint[1][chec->totnumb - 1] < chec->minnum)
		chec->pos2a = chec->minpos;
	else if (chec->staint[1][chec->totnumb - 1] > chec->maxnum)
		chec->pos2a = chec->maxpos + 1;
	else
	{
		while (y < chec->totnum - 1)
		{
			if ((chec->staint[1][chec->totnumb - 1] > chec->staint[0][y]
				&& chec->staint[1][chec->totnumb - 1] < chec->staint[0][y + 1])
				|| (chec->staint[1][chec->totnumb - 1] < chec->staint[0][y]
				&& chec->staint[1][chec->totnumb - 1] > chec->staint[0][y + 1]))
				chec->pos2a = y + 1;
			y++;
		}
	}
	if (chec->pos2b == 0)
		chec->pos2b = chec->totnum - chec->pos2a;
}

void	ft_checpositions_b(t_chec *chec)
{
	int		y;

	y = 0;
	chec->posa = 0;
	chec->posb = 0;
	if (chec->staint[0][0] < chec->minnum)
		chec->posa = chec->minpos;
	else if (chec->staint[0][0] > chec->maxnum)
		chec->posa = chec->maxpos + 1;
	else
	{
		while (y < chec->totnumb - 1)
		{
			if ((chec->staint[0][0] > chec->staint[1][y]
				&& chec->staint[0][0] < chec->staint[1][y + 1])
				|| (chec->staint[0][0] < chec->staint[1][y]
				&& chec->staint[0][0] > chec->staint[1][y + 1]))
				chec->posa = y + 1;
			y++;
		}
	}
	if (chec->posb == 0)
		chec->posb = chec->totnumb - chec->posa;
}
