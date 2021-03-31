/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:51:25 by fballest          #+#    #+#             */
/*   Updated: 2021/03/31 11:50:46 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checknumbers_b(t_chec *chec)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (chec->staint[0][y])
	{
		if (chec->staint[0][y] > INT_MAX || chec->staint[0][y] < INT_MIN)
			ft_printerror("Error");
		y++;
	}
	y = 0;
	while (chec->staint[0][x])
	{
		y = x + 1;
		while (chec->staint[0][y])
		{
			if (chec->staint[0][y] == chec->staint[0][x])
				ft_printerror("Error");
		y++;
		}
		x++;
	}
}

void	ft_swapstack_a(t_chec *chec)
{
	int		temp;

	temp = chec->staint[0][0];
	chec->staint[0][0] = chec->staint[0][1];
	chec->staint[0][1] = temp;
}

void	ft_swapstack_b(t_chec *chec)
{
	int		tmp;

	tmp = chec->staint[1][0];
	chec->staint[1][0] = chec->staint[1][1];
	chec->staint[1][1] = tmp;
}
