/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:10:48 by fballest          #+#    #+#             */
/*   Updated: 2021/05/14 13:05:42 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (chec->staint[1][0] < chec->staint[1][chec->totnumb - 1])
	{
		ft_rotatestack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "rb\n");
	}
	if (x == 1 && ((chec->staint[1][0] < chec->staint[1][1]
		&& chec->staint[1][0] > chec->staint[1][2])
		|| (chec->staint[1][0] < chec->staint[1][1]
		&& chec->staint[1][1] < chec->staint[1][2])))
	{
		ft_swapstack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "sb\n");
		x--;
	}
	if (x > 1 && x <= 3)
	{
		x = ft_mid_stab_order_b2(chec, x);
		x = ft_mid_stab_order_b3(chec, x);
	}
	x = ft_mid_stab_order_pusher(chec, x);
	if (x < 0)
		x = 0;
	return (x);
}

int	ft_mid_stab_order_b2(t_chec *chec, int x)
{
	if (((x <= 3 || x <= 2) && (chec->staint[1][0] < chec->staint[1][1]
		&& chec->staint[1][0] > chec->staint[1][2]))
		|| (x <= 2 && (chec->staint[1][0] < chec->staint[1][1]
		&& chec->staint[1][1] < chec->staint[1][2])))
	{
		ft_swapstack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "sb\n");
		x--;
	}
	if (chec->staint[1][0] < chec->staint[1][1]
		&& chec->staint[1][0] < chec->staint[1][2]
		&& chec->staint[1][0] > chec->staint[1][3])
	{
		ft_swapstack_b(chec);
		ft_rotatestack_b(chec);
		ft_swapstack_b(chec);
		ft_rotrevstack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "sb\nrb\nsb\nrrb\n");
		x--;
	}
	if (chec->staint[1][0] > chec->staint[1][chec->totnumb - 1]
		&& chec->staint[1][0] > chec->staint[1][chec->totnumb - 2]
		&& chec->staint[1][0] < chec->staint[1][chec->totnumb - 3])
	{
		ft_rotrevstack_b(chec);
		ft_swapstack_b(chec);
		ft_rotrevstack_b(chec);
		ft_swapstack_b(chec);
		ft_rotatestack_b(chec);
		ft_rotatestack_b(chec);
		ft_rotatestack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "rrb\nsb\nrrb\nsb\nrb\nrb\nrb\n");
		x--;
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
		x--;
	}
	if (chec->staint[1][0] < chec->staint[1][1]
		&& chec->staint[1][0] < chec->staint[1][2]
		&& chec->staint[1][0] < chec->staint[1][3]
		&& chec->staint[1][0] < chec->staint[1][4]
		&& chec->staint[1][0] > chec->staint[1][5])
	{
		ft_swapstack_b(chec);
		ft_rotatestack_b(chec);
		ft_swapstack_b(chec);
		ft_rotatestack_b(chec);
		ft_swapstack_b(chec);
		ft_rotatestack_b(chec);
		ft_swapstack_b(chec);
		ft_rotrevstack_b(chec);
		ft_rotrevstack_b(chec);
		ft_rotrevstack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "sb\nrb\nsb\nrb\nsb\nrb\nsb\nrrb\nrrb\nrrb\n");
		x--;
	}
	return (x);
}

int	ft_mid_stab_order_b3(t_chec *chec, int x)
{
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
		x--;
	}
	return (x);
}

int	ft_mid_stab_order_pusher(t_chec *chec, int x)
{
	while (chec->staint[0][0] > chec->staint[1][0])
	{
		ft_pushstack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "pb\n");
	}
	while (chec->staint[0][0] < chec->staint[1][chec->totnumb - 1])
	{
		ft_pushstack_b(chec);
		ft_rotatestack_b(chec);
		chec->instru = ft_strjoin(chec->instru, "pb\nrb\n");
	}
	return (x);
}
