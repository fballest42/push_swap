/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 09:58:00 by fballest          #+#    #+#             */
/*   Updated: 2021/05/13 09:59:34 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_order_stack_a(t_chec *chec)
{
	ft_checminpos(chec);
	if (chec->minpos <= chec->totnum / 2 && chec->minpos != 0)
	{
		while (chec->minpos > 0)
		{
			ft_rotatestack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "ra\n");
			ft_checminpos(chec);
		}
	}
	else if (chec->minpos > chec->totnum / 2 && chec->minpos != 0)
	{
		while ((chec->totnum - chec->minpos) != chec->totnum)
		{
			ft_rotrevstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "rra\n");
			ft_checminpos(chec);
		}
	}
}

void	ft_threesort_mid(t_chec *chec)
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
		ft_rotatestack_a(chec);
		ft_swapstack_a(chec);
		ft_rotrevstack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "ra\nsa\nrra\n");
	}
	ft_threesort_midb(chec);
}

void	ft_threesort_midb(t_chec *chec)
{
	if (chec->staint[0][1] > chec->staint[0][0]
		&& chec->staint[0][1] > chec->staint[0][2]
		&& chec->staint[0][0] > chec->staint[0][2])
	{
		ft_rotatestack_a(chec);
		ft_swapstack_a(chec);
		ft_rotrevstack_a(chec);
		ft_swapstack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "ra\nsa\nrra\nsa\n");
	}
	if (chec->staint[0][0] > chec->staint[0][1]
		&& chec->staint[0][0] > chec->staint[0][2]
		&& chec->staint[0][1] > chec->staint[0][2])
	{
		ft_swapstack_a(chec);
		ft_rotatestack_a(chec);
		ft_swapstack_a(chec);
		ft_rotrevstack_a(chec);
		ft_swapstack_a(chec);
	}
	ft_threesort_midc(chec);
}

void	ft_threesort_midc(t_chec *chec)
{
	if (chec->staint[0][0] > chec->staint[0][1]
		&& chec->staint[0][0] > chec->staint[0][2]
		&& chec->staint[0][1] < chec->staint[0][2])
	{
		ft_swapstack_a(chec);
		ft_rotatestack_a(chec);
		ft_swapstack_a(chec);
		ft_rotrevstack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "sa\nra\nsa\nrra\nsa\n");
	}
}

void	ft_checminpos(t_chec *chec)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	chec->minnum = chec->staint[0][0];
	chec->maxnum = chec->staint[0][0];
	chec->minpos = 0;
	chec->maxpos = 0;
	while (j++ < chec->totnum)
	{
		if (chec->minnum > chec->staint[0][j - 1])
		{
			chec->minnum = chec->staint[0][j - 1];
			chec->minpos = j - 1;
		}
		else if (chec->maxnum < chec->staint[0][j - 1])
		{
			chec->maxnum = chec->staint[0][j - 1];
			chec->maxpos = j - 1;
		}
	}
	chec->minposb = (chec->totnum - 1) - chec->minnum;
}
