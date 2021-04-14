/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:43:14 by fballest          #+#    #+#             */
/*   Updated: 2021/04/14 13:21:09 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotatestack_ab(t_chec *chec)
{
	ft_rotatestack_a(chec);
	ft_rotatestack_b(chec);
}

void	ft_rotrevstack_a(t_chec *chec)
{
	int		temp;
	int		x;
	int		y;

	if (chec->totnum == 2)
		ft_swapstack_a(chec);
	else
	{
		x = chec->totnum - 2;
		y = chec->totnum - 1;
		temp = chec->staint[0][y];
		while (y >= 0)
			chec->staint[0][y--] = chec->staint[0][x--];
		chec->staint[0][0] = temp;
	}
}

void	ft_rotrevstack_b(t_chec *chec)
{
	int		temp;
	int		x;
	int		y;

	if (chec->totnumb == 2)
		ft_swapstack_b(chec);
	else
	{
		x = chec->totnumb - 2;
		y = chec->totnumb - 1;
		temp = chec->staint[1][y];
		while (y >= 0)
			chec->staint[1][y--] = chec->staint[1][x--];
		chec->staint[1][0] = temp;
	}
}

void	ft_rotrevstack_ab(t_chec *chec)
{
	ft_rotrevstack_a(chec);
	ft_rotrevstack_b(chec);
}

void	ft_checkinst(t_chec *chec, char *line)
{
	if (!ft_strncmp(line, "sa", 2) && ft_strlen(line) == 2 && chec->totnum > 1)
		ft_swapstack_a(chec);
	if (!ft_strncmp(line, "sb", 2) && ft_strlen(line) == 2 && chec->totnumb > 1)
		ft_swapstack_b(chec);
	if (!ft_strncmp(line, "ss", 2) && ft_strlen(line) == 2 && chec->totnum > 1
		&& chec->totnumb > 1)
		ft_swapstack_ab(chec);
	if (!ft_strncmp(line, "pa", 2) && ft_strlen(line) == 2
		&& chec->totnumb >= 1)
		ft_pushstack_a(chec);
	if (!ft_strncmp(line, "pb", 2) && ft_strlen(line) == 2 && chec->totnum >= 1)
		ft_pushstack_b(chec);
	if (!ft_strncmp(line, "ra", 2) && ft_strlen(line) == 2 && chec->totnum > 1)
		ft_rotatestack_a(chec);
	if (!ft_strncmp(line, "rb", 2) && ft_strlen(line) == 2 && chec->totnumb > 1)
		ft_rotatestack_b(chec);
	if (!ft_strncmp(line, "rr", 2) && ft_strlen(line) == 2
		&& chec->totnum > 1 && chec->totnumb > 1)
		ft_rotatestack_ab(chec);
	if (!ft_strncmp(line, "rra", 3) && ft_strlen(line) == 3 && chec->totnum > 1)
		ft_rotrevstack_a(chec);
	if (!ft_strncmp(line, "rrb", 3) && ft_strlen(line) == 3
		&& chec->totnumb > 1)
		ft_rotrevstack_b(chec);
	if (!ft_strncmp(line, "rrr", 3) && ft_strlen(line) == 3
		&& chec->totnum > 1 && chec->totnumb > 1)
		ft_rotrevstack_ab(chec);
}
