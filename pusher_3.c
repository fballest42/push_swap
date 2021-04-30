/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:14:39 by fballest          #+#    #+#             */
/*   Updated: 2021/04/30 09:21:39 by fballest         ###   ########.fr       */
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
	chec->posb = chec->totnum - 1;
	if (chec->staint[1][0] < chec->minnum)
		chec->posa = chec->minpos;
	else
	{
		while (y < (chec->totnum - 1))
		{
			if (chec->staint[1][0] > chec->staint[0][y])
				chec->posa = y + 1;
			y++;
		}
	}
	chec->posb = chec->totnum - chec->posa;
}

void	ft_checpositions_b(t_chec *chec, int y)
{
	if ((y == chec->totnum || y == 0)
		&& ((chec->staint[0][0] < chec->staint[1][0]
		&& chec->staint[1][0] < chec->staint[0][chec->totnum - 1])
		|| (chec->staint[0][0] > chec->staint[1][0]
		&& chec->staint[1][0] > chec->staint[0][chec->totnum - 1])
		|| (chec->staint[0][0] < chec->staint[1][0]
		&& chec->staint[1][0] > chec->staint[0][chec->totnum - 1]
		&& chec->staint[0][0] > chec->staint[0][chec->totnum - 1])
		|| (chec->staint[0][0] > chec->staint[1][0]
		&& chec->staint[1][0] < chec->staint[0][chec->totnum - 1]
		&& chec->staint[0][0] < chec->staint[0][chec->totnum - 1])))
	{
		chec->posa = 0;
		chec->posb = chec->totnum - chec->posa;
	}
}

void	ft_checpositions_c(t_chec *chec, int y)
{
	if ((y == chec->totnum || y == 0)
		&& ((chec->staint[0][0] < chec->staint[1][0]
		&& chec->staint[1][0] > chec->staint[0][chec->totnum - 1]
		&& chec->staint[0][0] < chec->staint[0][chec->totnum - 1])
		|| (chec->staint[0][0] > chec->staint[1][0]
		&& chec->staint[1][0] < chec->staint[0][chec->totnum - 1]
		&& chec->staint[0][0] > chec->staint[0][chec->totnum - 1])))
	{
		chec->posa = chec->totnum;
		chec->posb = chec->totnum - chec->posa;
	}
}

		// if ((y == chec->totnum - 1 || y == 0)
		// 	&& ((chec->staint[0][0] < chec->staint[1][0]
		// 	&& chec->staint[1][0] > chec->staint[0][chec->totnum - 1]
		// 	&& chec->staint[0][0] > chec->staint[0][chec->totnum - 1])
		// 	|| (chec->staint[0][0] > chec->staint[1][0]
		// 	&& chec->staint[1][0] < chec->staint[0][chec->totnum - 1]
		// 	&& chec->staint[0][0] > chec->staint[0][chec->totnum - 1])))
		// {
		// 	chec->posa = chec->totnum;
		// 	chec->posb = chec->totnum - chec->posa;
		// }
		// if ((y == chec->totnum - 1 || y == 0)
		// 	&& ((chec->staint[0][0] < chec->staint[1][0]
		// 	&& chec->staint[1][0] < chec->staint[0][chec->totnum - 1])
		// 	|| (chec->staint[0][0] > chec->staint[1][0]
		// 	&& chec->staint[1][0] > chec->staint[0][chec->totnum - 1])
		// 	|| (chec->staint[0][0] < chec->staint[1][0]
		// 	&& chec->staint[1][0] > chec->staint[0][chec->totnum - 1]
		// 	&& chec->staint[0][0] > chec->staint[0][chec->totnum - 1])
		// 	|| (chec->staint[0][0] > chec->staint[1][0]
		// 	&& chec->staint[1][0] < chec->staint[0][chec->totnum - 1]
		// 	&& chec->staint[0][0] < chec->staint[0][chec->totnum - 1])))
		// {
		// 	chec->posa = 0;
		// 	chec->posb = chec->totnum - chec->posa;
		// }