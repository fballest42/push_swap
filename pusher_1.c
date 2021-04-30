/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:08:19 by fballest          #+#    #+#             */
/*   Updated: 2021/04/30 10:32:24 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_insert_sta_a(t_chec *chec)
{
	while (chec->totnumb > 0)
	{
		ft_checminpos(chec);
		ft_checpositions(chec);
		if (chec->posa && chec->posa <= chec->posb)
		{
			while (chec->posa > 0)
			{
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
		ft_pushstack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "pa\n");
	}
}

void	ft_insert_sta_b(t_chec *chec)
{
	while (chec->totnum > 3)
	{
		ft_checminpos_b(chec);
		ft_checpositions_b(chec);
		if (chec->posa && chec->posa <= chec->posb)
		{
			while (chec->posa > 0)
			{
				ft_rotatestack_b(chec);
				chec->instru = ft_strjoin(chec->instru, "rb\n");
				chec->posa--;
			}
		}
		else if (chec->posa == chec->totnum || chec->posa > chec->posb)
		{
			while (chec->posb > 0)
			{
				ft_rotrevstack_b(chec);
				chec->instru = ft_strjoin(chec->instru, "rrb\n");
				chec->posb--;
			}
		}
		ft_pushstack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "pb\n");
	}	
}

void	ft_order_stack_a(t_chec *chec)
{
	ft_checminpos(chec);
	if (chec->minpos == 0)
		ft_printnumbers(chec);
	else if (chec->minpos >= chec->totnum / 2)
	{
		while (chec->minpos < chec->totnum)
		{
			ft_rotrevstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "rra\n");
			chec->minpos++;
		}
	}
	else if (chec->minpos < chec->totnum / 2)
	{
		while (chec->minposb < chec->totnum)
		{
			ft_rotatestack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "ra\n");
			chec->minpos++;
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

void	ft_midsort(t_chec *chec)
{
	int		x;

	x = 0;
	chec->blo = chec->totnum / 6;
	if ((chec->totnum - (6 * chec->blo)) > 0)
		chec->blo++;
	while (chec->totnum > 3 && chec->blo > 0 && x < 3)
	{
		if (chec->blo == 1)
			x = x - 3;
		ft_pushstack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "pb\n");
		x++;
		if (chec->totnumb > 1)
			ft_insert_stack_b(chec);
	}
	ft_threesort_mid(chec);
	chec->blo--;
	if (chec->blo > 0)
		ft_midsort(chec);
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
			// if (chec->posa == 0)
			// {
			// 	ft_pushstack_a(chec);
			// 	chec->instru = ft_strjoin(chec->instru, "pa\n");
			// }
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

void	ft_mid_return_sta_min(t_chec *chec)
{
	ft_checminpos(chec);
	if (chec->minpos == 0)
		printf("%s", chec->instru);
	else if (chec->minpos != 0 && chec->minpos > (chec->totnum / 2))
	{
		while (chec->minpos != 0)
		{
			ft_rotrevstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "rra\n");
			chec->minpos++;
		}
	}
	else if (chec->minpos != 0 && chec->minpos < (chec->totnum / 2))
	{
		while (chec->minpos != 0)
		{
			ft_rotatestack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "ra\n");
			chec->minpos--;
		}
	}
}

void	ft_mid_stab_order_b(t_chec *chec)
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
		if (chec->staint[1][0] < chec->staint[1][1] && chec->staint[1][0] < chec->staint[1][2])
		{
			ft_rotatestack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "rb\n");
		}
		if (chec->staint[1][0] < chec->staint[1][1] && chec->staint[1][0] > chec->staint[1][2])
		{
			ft_swapstack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "sb\n");
		}
	}
	if (chec->totnum > 3)
		ft_
}

void	ft_checminpos(t_chec *chec)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	chec->minnum = chec->staint[0][0];
	chec->minpos = 0;
	while (j++ < chec->totnum)
	{
		if (chec->minnum > chec->staint[0][j - 1])
		{
			chec->minnum = chec->staint[0][j - 1];
			chec->minpos = j - 1;
		}
	}
}

void	ft_checminpos_b(t_chec *chec)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	chec->minnum = chec->staint[1][0];
	chec->minpos = 0;
	while (j++ < chec->totnumb)
	{
		if (chec->minnum > chec->staint[1][j - 1])
		{
			chec->minnum = chec->staint[1][j - 1];
			chec->minpos = j - 1;
		}
	}
}

// void	ft_few_stab_go_b(t_chec *chec)
// {
// 	int	x;

// 	x = chec->totnum;
// }

// void	ft_few_stab_a(t_chec *chec)
// {
// 	if (chec->staint[1][0] > chec->staint[0][2])
// 	{
// 		ft_pushstack_a(chec);
// 		ft_rotatestack_a(chec);
// 		chec->instru = ft_strjoin(chec->instru, "pa\nra\n");
// 	}
// 	if (chec->staint[1][0] > chec->staint[0][1])
// 	{
// 		ft_rotatestack_a(chec);
// 		ft_pushstack_a(chec);
// 		ft_rotrevstack_a(chec);
// 		chec->instru = ft_strjoin(chec->instru, "ra\npa\nrra\n");
// 	}
// 	if (chec->staint[1][0] > chec->staint[0][0])
// 	{
// 		ft_pushstack_a(chec);
// 		chec->instru = ft_strjoin(chec->instru, "pa\n");
// 	}
// }

// void	ft_few_stab_b(t_chec *chec)
// {
// 	if (chec->staint[1][0] < chec->staint[1][1])
// 	{
// 		ft_swapstack_b(chec);
// 		chec->instru = ft_strjoin(chec->instru, "sa\n");
// 	}
// 	if (chec->staint[1][0] < chec->staint[0][0])
// 	{
// 		ft_pushstack_a(chec);
// 		chec->instru = ft_strjoin(chec->instru, "pa\n");
// 	}
// 	if (chec->staint[1][0] > chec->staint[0][2])
// 	{
// 		ft_pushstack_a(chec);
// 		ft_rotatestack_a(chec);
// 		chec->instru = ft_strjoin(chec->instru, "pa\nra\n");
// 	}
// 	if (chec->staint[1][0] > chec->staint[0][0] && chec->staint[1][0] < chec->staint[0][1])
// 	{
// 		ft_pushstack_a(chec);
// 		ft_swapstack_a(chec);
// 		chec->instru = ft_strjoin(chec->instru, "pa\nsa\n");
// 	}
// 	if (chec->staint[1][0] > chec->staint[0][0] && chec->staint[1][0] > chec->staint[0][1])
// 	{
// 		ft_rotatestack_a(chec);
// 		ft_rotatestack_a(chec);
// 		ft_pushstack_a(chec);
// 		ft_rotrevstack_a(chec);
// 		ft_rotrevstack_a(chec);
// 		chec->instru = ft_strjoin(chec->instru, "rra\npa\nra\nra\n");
// 	}
// 		// if (chec->staint[1][1] < chec->staint[0][0])
// 		// {
// 		// 	ft_rotatestack_b(chec);
// 		// 	ft_pushstack_a(chec);
// 		// 	chec->instru = ft_strjoin(chec->instru, "rb\npa\n");
// 		// }
// 		// if (chec->staint[1][1] > chec->staint[0][2])
// 		// {
// 		// 	ft_swapstack_b(chec);
// 		// 	ft_pushstack_a(chec);
// 		// 	ft_rotatestack_a(chec);
// 		// 	chec->instru = ft_strjoin(chec->instru, "sb\npa\nra\n");
// 		// }
// 		// if (chec->staint[1][1] > chec->staint[0][0] && chec->staint[1][1] < chec->staint[0][1])
// 		// {
// 		// 	ft_swapstack_b(chec);
// 		// 	ft_pushstack_a(chec);
// 		// 	ft_swapstack_a(chec);
// 		// 	chec->instru = ft_strjoin(chec->instru, "sb\npa\nsa\n");
// 		// }

// 		// if (chec->staint[1][1] > chec->staint[0][0] && chec->staint[1][1] > chec->staint[0][1])
// 		// {
// 		// 	ft_swapstack_b(chec);
// 		// 	ft_rotrevstack_a(chec);
// 		// 	ft_pushstack_a(chec);
// 		// 	ft_rotatestack_a(chec);
// 		// 	ft_rotatestack_a(chec);
// 		// 	chec->instru = ft_strjoin(chec->instru, "sb\nrra\npa\nra\nra\n");
// 		// }
// 	// 	while (chec->totnumb > 0)
// 	// {

// 	// 	if (chec->staint[1][0] > chec->staint[0][chec->totnum - 1])
// 	// 	{
// 	// 		ft_pushstack_a(chec);
// 	// 		ft_rotatestack_a(chec);
// 	// 		chec->instru = ft_strjoin(chec->instru, "pa\nra\n");
// 	// 	}
// 	// 	else if (chec->staint[1][0] > chec->staint[0][0] && chec->staint[1][0] < chec->staint[0][1])
// 	// 	{
// 	// 		ft_pushstack_a(chec);
// 	// 		ft_swapstack_a(chec);
// 	// 		chec->instru = ft_strjoin(chec->instru, "pa\nsa\n");
// 	// 	}
// 	// }
// }
