/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:08:19 by fballest          #+#    #+#             */
/*   Updated: 2021/04/21 12:55:58 by fballest         ###   ########.fr       */
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
		if (chec->totnumb > 1)
			ft_few_stab_order_b(chec);
	}
	ft_threesort(chec);
	while (chec->totnumb > 0)
		ft_few_stab_back_a(chec);
}

void	ft_few_stab_a(t_chec *chec)
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

void	ft_few_stab_b(t_chec *chec)
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
	}
	if (chec->staint[1][0] > chec->staint[0][2])
	{
		ft_pushstack_a(chec);
		ft_rotatestack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "pa\nra\n");
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
		// if (chec->staint[1][1] < chec->staint[0][0])
		// {
		// 	ft_rotatestack_b(chec);
		// 	ft_pushstack_a(chec);
		// 	chec->instru = ft_strjoin(chec->instru, "rb\npa\n");
		// }
		// if (chec->staint[1][1] > chec->staint[0][2])
		// {
		// 	ft_swapstack_b(chec);
		// 	ft_pushstack_a(chec);
		// 	ft_rotatestack_a(chec);
		// 	chec->instru = ft_strjoin(chec->instru, "sb\npa\nra\n");
		// }
		// if (chec->staint[1][1] > chec->staint[0][0] && chec->staint[1][1] < chec->staint[0][1])
		// {
		// 	ft_swapstack_b(chec);
		// 	ft_pushstack_a(chec);
		// 	ft_swapstack_a(chec);
		// 	chec->instru = ft_strjoin(chec->instru, "sb\npa\nsa\n");
		// }

		// if (chec->staint[1][1] > chec->staint[0][0] && chec->staint[1][1] > chec->staint[0][1])
		// {
		// 	ft_swapstack_b(chec);
		// 	ft_rotrevstack_a(chec);
		// 	ft_pushstack_a(chec);
		// 	ft_rotatestack_a(chec);
		// 	ft_rotatestack_a(chec);
		// 	chec->instru = ft_strjoin(chec->instru, "sb\nrra\npa\nra\nra\n");
		// }
	// 	while (chec->totnumb > 0)
	// {

	// 	if (chec->staint[1][0] > chec->staint[0][chec->totnum - 1])
	// 	{
	// 		ft_pushstack_a(chec);
	// 		ft_rotatestack_a(chec);
	// 		chec->instru = ft_strjoin(chec->instru, "pa\nra\n");
	// 	}
	// 	else if (chec->staint[1][0] > chec->staint[0][0] && chec->staint[1][0] < chec->staint[0][1])
	// 	{
	// 		ft_pushstack_a(chec);
	// 		ft_swapstack_a(chec);
	// 		chec->instru = ft_strjoin(chec->instru, "pa\nsa\n");
	// 	}
	// }
}

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
		if (chec->staint[1][0] < chec->staint[1][2])
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
	while (chec->staint[1][0] > chec->staint[0][chec->totnum - 1] && chec->totnumb > 0)
	{
		ft_pushstack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "pa\n");
		i++;
	}
	while (i-- > 0)
	{
		ft_rotrevstack_a(chec);
		chec->instru = ft_strjoin(chec->instru, "rra\n");
	}
	ft_insert_sta_a(chec);
}

void	ft_insert_sta_a(t_chec *chec)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (chec->totnumb > 0)
	{
		ft_checpositions(chec);
		if (chec->posa == 1)
		{
			ft_pushstack_a(chec);
			ft_swapstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "pa\nsa\n");
			ft_insert_sta_a(chec);
		}
		if (chec->posb == 1 && chec->posa == 0)
		{
			ft_rotatestack_a(chec);
			x++;
			ft_pushstack_a(chec);
			chec->instru = ft_strjoin(chec->instru, "ra\npa\n");
			ft_insert_sta_a(chec);
		}
		if (chec->posa < chec->posb)
		{

		}
	}
	// if (chec->posa < chec->posb)
	// {
	// 	while (chec->posa > 0)
	// 	{
	// 		ft_rotatestack_a(chec);
	// 		chec->instru = ft_strjoin(chec->instru, "ra\n");
	// 		chec->posa--;
	// 		x++;
	// 	}
	// 	ft_pushstack_a(chec);
	// 	chec->instru = ft_strjoin(chec->instru, "pa\n");
	// }
	// if (chec->posb < chec->posa)
	// {
	// 	while (chec->posa > 0)
	// 	{
	// 		ft_rotrevstack_a(chec);
	// 		chec->instru = ft_strjoin(chec->instru, "rra\n");
	// 		chec->posa--;
	// 		x++;
	// 	}
	// 	ft_pushstack_a(chec);
	// 	chec->instru = ft_strjoin(chec->instru, "pa\n");
	// }

}

void	ft_few_stab_go_b(t_chec *chec)
{
	int	x;

	x = chec->totnum;
}

void	ft_checpositions(t_chec *chec)
{
	chec->posa = 0;
	chec->posb = 0;
	while (chec->staint[0][chec->posa] < chec->staint[1][0])
		chec->posa++;
	while (chec->staint[0][(chec->totnum - 1) - chec->posb] > chec->staint[1][0])
		chec->posb++;
}
