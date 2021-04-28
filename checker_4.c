/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:49:46 by fballest          #+#    #+#             */
/*   Updated: 2021/04/14 12:19:25 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swapstack_ab(t_chec *chec)
{
	ft_swapstack_a(chec);
	ft_swapstack_b(chec);
}

void	ft_pushstack_b(t_chec *chec)
{
	int		tmpa;
	int		x;

	x = 0;
	tmpa = chec->staint[0][0];
	if (chec->totnum == 1)
		chec->staint[0][0] = 0;
	while ((x + 1) <= chec->totnum)
	{
		chec->staint[0][x] = chec->staint[0][x + 1];
		chec->staint[0][x + 1] = 0;
		x++;
	}
	x = 0;
	x = chec->totnumb;
	while (x >= 0)
	{
		chec->staint[1][x + 1] = chec->staint[1][x];
		x--;
	}
	chec->staint[1][0] = tmpa;
	chec->totnum--;
	chec->totnumb++;
}

void	ft_pushstack_a(t_chec *chec)
{
	int		tmpa;
	int		x;

	x = 0;
	tmpa = chec->staint[1][0];
	if (chec->totnumb == 1)
		chec->staint[1][0] = 0;
	while ((x + 1) <= chec->totnumb)
	{
		chec->staint[1][x] = chec->staint[1][x + 1];
		chec->staint[1][x + 1] = 0;
		x++;
	}
	x = 0;
	x = chec->totnum;
	while (x >= 0)
	{
		chec->staint[0][x + 1] = chec->staint[0][x];
		x--;
	}
	chec->staint[0][0] = tmpa;
	chec->totnum++;
	chec->totnumb--;
}

void	ft_rotatestack_a(t_chec *chec)
{
	int	temp;
	int	x;
	int	y;

	temp = chec->staint[0][0];
	x = 0;
	y = 1;
	while (y < chec->totnum)
		chec->staint[0][x++] = chec->staint[0][y++];
	chec->staint[0][y - 1] = temp;
}

void	ft_rotatestack_b(t_chec *chec)
{
	int	tmp;
	int	x;
	int	y;

	tmp = chec->staint[1][0];
	x = 0;
	y = 1;
	while (y < chec->totnumb)
		chec->staint[1][x++] = chec->staint[1][y++];
	chec->staint[1][y - 1] = tmp;
}
