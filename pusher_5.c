/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:37:56 by fballest          #+#    #+#             */
/*   Updated: 2021/05/14 12:49:08 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_insert_sta_a2(t_chec *chec)
{
	if (chec->posa <= chec->posb)
	{
		while (chec->posa > 0)
		{
			if (chec->posa == 1)
			{
				ft_pushstack_a(chec);
				ft_swapstack_a(chec);
				chec->instru = ft_strjoin(chec->instru, "pa\n,sa\n");
				chec->posa--;
			}
			ft_rotatestack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "ra\n");
			chec->posa--;
		}
	}
	else if (chec->posa == chec->totnum || chec->posa > chec->posb)
	{
		while (chec->posb > 0)
		{
			ft_rotrevstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "rra\n");
			chec->posb--;
		}
	}
}

void	ft_insert_sta_a(t_chec *chec)
{
	while (chec->totnumb > 0)
	{
		ft_checminpos(chec);
		ft_checpositions(chec);
		ft_checpositions_2(chec);
		ft_origin_position(chec);
		ft_insert_sta_a2(chec);
		if (chec->staint[1][0] < chec->minnum
			|| chec->staint[1][0] > chec->maxnum)
		{
			ft_pushstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "pa\n");
		}
		while (chec->staint[1][0] < chec->staint[0][0]
				&& chec->staint[1][0] > chec->staint[0][chec->totnum - 1])
		{
			ft_pushstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "pa\n");
		}
	}
}

void	ft_origin_position(t_chec *chec)
{
	if ((chec->posa <= chec->posb && chec->posa - 1 > chec->pos2a)
		|| (chec->posb <= chec->posa && chec->posb - 1 > chec->pos2b))
	{
		chec->posa = chec->pos2a;
		chec->posb = chec->pos2b;
		if (chec->posb < chec->posa)
		{
			ft_rotrevstack_ab(chec);
			chec->instru = ft_strjoin(chec->instru, "rrr\n");
			chec->posa++;
			chec->posb--;
		}
		if (chec->posa <= chec->posb)
		{
			ft_rotatestack_ab(chec);
			chec->instru = ft_strjoin(chec->instru, "rr\n");
			chec->posa--;
			chec->posb++;
		}
	}
}

int	ft_insert_sta_b2(t_chec *chec, int x)
{
	if (chec->staint[0][0] < chec->staint[1][0]
		&& chec->staint[0][0] < chec->staint[1][1]
		&& chec->staint[0][0] > chec->staint[1][2])
	{
		ft_rotatestack_b(chec);
		ft_pushstack_b(chec);
		ft_swapstack_b(chec);
		ft_rotrevstack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "rb\npb\nsb\nrrb\n");
		x++;
	}
	if (chec->staint[0][0] > chec->staint[1][chec->totnumb - 1]
		&& chec->staint[0][0] > chec->staint[1][chec->totnumb - 2]
		&& chec->staint[0][0] < chec->staint[1][chec->totnumb - 3])
	{
		ft_rotrevstack_b(chec);
		ft_rotrevstack_b(chec);
		ft_pushstack_b(chec);
		ft_rotatestack_b(chec);
		ft_rotatestack_b(chec);
		ft_rotatestack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "rrb\nrrb\npb\nrrb\nrrb\nrrb\n");
		x++;
	}
	else if (chec->staint[0][0] < chec->staint[1][0]
		&& chec->staint[0][0] < chec->staint[1][1]
		&& chec->staint[0][0] < chec->staint[1][2]
		&& chec->staint[0][0] > chec->staint[1][3]
		&& x < 3)
	{
		ft_rotatestack_b(chec);
		ft_rotatestack_b(chec);
		ft_pushstack_b(chec);
		ft_swapstack_b(chec);
		ft_rotrevstack_b(chec);
		ft_rotrevstack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "rb\nrb\npb\nsb\nrrb\nrrb\n");
		x++;
	}
	if (chec->staint[0][0] < chec->staint[1][chec->totnumb - 1])
	{
		ft_pushstack_b(chec);
		ft_rotatestack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "pb\nrb\n");
		x++;
	}
	if (chec->staint[0][0] > chec->staint[1][chec->totnumb - 1]
		&& chec->staint[0][0] < chec->staint[1][chec->totnumb - 2])
	{
		ft_rotrevstack_b(chec);
		ft_pushstack_b(chec);
		ft_rotatestack_b(chec);
		ft_rotatestack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "rrb\npb\nrb\nrb\n");
		x++;
	}
	if (x == 0)
	{
		ft_pushstack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "pb\n");
		x++;
	}
	return (x);
}

void	ft_insert_sta_b(t_chec *chec)
{
	int		x;

	x = 0;
	while (x < 3)
	{
		if (chec->staint[0][0] > chec->staint[1][0])
		{
			ft_pushstack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "pb\n");
			x++;
		}
		if (chec->staint[0][0] < chec->staint[1][chec->totnumb - 1])
		{
			ft_pushstack_b(chec);
			ft_rotatestack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "pb\nrb\n");
			x++;
		}
		if (chec->staint[0][0] < chec->staint[1][0]
			&& chec->staint[0][0] > chec->staint[1][1])
		{
			ft_pushstack_b(chec);
			ft_swapstack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "pb\nsb\n");
			x++;
		}
		if (chec->staint[0][0] > chec->staint[1][chec->totnumb - 1]
			&& chec->staint[0][0] < chec->staint[1][chec->totnumb - 2])
		{
			ft_rotrevstack_b(chec);
			ft_pushstack_b(chec);
			ft_rotatestack_b(chec);
			ft_rotatestack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "rrb\npb\nrb\nrb\n");
			x++;
		}
		x = ft_insert_sta_b2(chec, x);
	}
}
