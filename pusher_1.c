/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:08:19 by fballest          #+#    #+#             */
/*   Updated: 2021/05/06 12:45:54 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_insert_sta_a(t_chec *chec)
{
	while (chec->totnumb > 0)
	{
		ft_checminpos(chec);
		ft_checpositions(chec);
		ft_checpositions_2(chec);
		if (chec->posa <= chec->posb)
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
		if (chec->staint[1][0] < chec->minnum || chec->staint[1][0] > chec->maxnum)
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
		if (chec->staint[0][0] < chec->staint[1][0]
			&& chec->staint[0][0] > chec->staint[1][1])
		{
			ft_pushstack_b(chec);
			ft_swapstack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "pb\nsb\n");
			x++;
		}
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
		else if (chec->staint[0][0] < chec->staint[1][0]
			&& chec->staint[0][0] < chec->staint[1][1]
			&& chec->staint[0][0] < chec->staint[1][2] && x < 3)
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
	}
}

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

void	ft_midsort(t_chec *chec)
{
	int		x;

	x = 0;
	chec->blo = chec->totnum / 6;
	if ((chec->totnum - (6 * chec->blo)) > 0)
		chec->blo++;
	while (chec->totnum > 3 && chec->blo > 0 && x < 3)
	{
		if (chec->staint[0][0] > chec->staint[1][chec->totnumb - 1]
			&& chec->staint[0][0] < chec->staint[1][chec->totnumb - 2])
		{
			ft_rotrevstack_b(chec);
			ft_pushstack_b(chec);
			ft_rotatestack_b(chec);
			ft_rotatestack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "rrb\npb\nrb\nrb\n");
		}
		ft_pushstack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "pb\n");
		x++;
		if (x > 1)
			x = ft_mid_stab_order_b(chec, x);
	}
	ft_threesort_mid(chec);
	chec->blo--;
	if (chec->totnum >= 3 && chec->blo > 0)
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

int	ft_mid_stab_order_b(t_chec *chec, int x)
{
	if (x == 1 && chec->staint[1][0] < chec->staint[1][1]
		&& chec->staint[1][0] > chec->staint[1][2])
	{
		ft_swapstack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "sb\n");
		x--;
	}
	// if (x > 1)
	// {
	// 	if (chec->staint[1][0] < chec->staint[1][1]
	// 		&& chec->staint[1][0] > chec->staint[1][2])
	// 	{
	// 		ft_swapstack_b(chec);
	// 		chec->instru = ft_strjoin(chec->instru, "sb\n");
	// 	}
	// }
	if (x > 1 && x <= 3)
	{
		if ((x <= 3 || x <= 2) && chec->staint[1][0] < chec->staint[1][1]
		&& chec->staint[1][0] > chec->staint[1][2])
		{
			ft_swapstack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "sb\n");
		}
		if (x <= 3 && chec->staint[1][0] < chec->staint[1][1]
			&& chec->staint[1][0] < chec->staint[1][2]
			&& chec->staint[1][0] > chec->staint[1][3])
		{
			ft_swapstack_b(chec);
			ft_rotatestack_b(chec);
			ft_swapstack_b(chec);
			ft_rotrevstack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "sb\nrb\nsb\nrrb\n");
		}
		if (x == 3 && chec->staint[1][0] < chec->staint[1][1]
			&& chec->staint[1][0] < chec->staint[1][2])
		{
			ft_swapstack_b(chec);
			ft_rotatestack_b(chec);
			ft_swapstack_b(chec);
			ft_rotrevstack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "sb\nrb\nsb\nrrb\n");
		}
		if (chec->staint[1][0] < chec->staint[1][1]
			&& chec->staint[1][0] < chec->staint[1][2]
			&& chec->staint[1][0] < chec->staint[1][3]
			&& chec->staint[1][0] > chec->staint[1][4])
		{
			ft_swapstack_b(chec);
			ft_rotatestack_b(chec);
			ft_swapstack_b(chec);
			ft_rotatestack_b(chec);
			ft_swapstack_b(chec);
			ft_rotrevstack_b(chec);
			ft_rotrevstack_b(chec);
			chec->instru = ft_strjoin(chec->instru, "sb\nrb\nsb\nrb\nsb\nrrb\nrrb\n");
		}
	}
	while (chec->staint[0][0] > chec->staint[1][0])
	{
		ft_pushstack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "pb\n");
		x++;
	}
	while (chec->staint[0][0] < chec->staint[1][chec->totnumb - 1])
	{
		ft_pushstack_b(chec);
		ft_rotatestack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "pb\nrb\n");
		x--;
	}
	return (x);
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
