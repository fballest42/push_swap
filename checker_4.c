/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:49:46 by fballest          #+#    #+#             */
/*   Updated: 2021/04/12 13:59:40 by fballest         ###   ########.fr       */
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
	int		y;

	x = 0;
	y = 1;
	tmpa = chec->staint[0][0];
	while (chec->staint[0][y])
	{
		chec->staint[0][x] = chec->staint[0][y];
		chec->staint[0][y++] = 0;
		x++;
	}
	x = 0;
	y = 1;
	while ((chec->staint[1][x] != 0 && !chec->zero)
			|| (chec->staint[1][x] == 0 && chec->zero))
		x++;
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
	int		y;

	x = 0;
	y = 1;
	tmpa = chec->staint[1][0];
	while (chec->staint[1][y])
	{
		chec->staint[1][x] = chec->staint[1][y];
		chec->staint[1][y++] = 0;
		x++;
	}
	x = 0;
	y = 1;
	while ((chec->staint[0][x] != 0 && !chec->zero)
			|| (chec->staint[0][x] == 0 && chec->zero))
		x++;
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
	while (chec->staint[0][y])
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
	while (chec->staint[1][y])
		chec->staint[1][x++] = chec->staint[1][y++];
	chec->staint[1][y - 1] = tmp;
}
