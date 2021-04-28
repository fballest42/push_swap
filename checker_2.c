/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:51:25 by fballest          #+#    #+#             */
/*   Updated: 2021/04/14 12:58:07 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checknumbers_b(t_chec *chec)
{
	int		y;
	int		x;
	int		z;

	y = 0;
	z = chec->totnum;
	x = 0;
	while (z > 0)
	{
		if (chec->staint[0][y] == 0)
		{
			chec->zero = 1;
			chec->zeropos = y;
			chec->zerocol = 0;
		}
		if (chec->staint[0][y] > INT_MAX || chec->staint[0][y] < INT_MIN)
			ft_printerror("Error\n Números más altos de los permitidos");

		y++;
		z--;
	}
	y = 0;
	z = chec->totnum;
	while (chec->staint[0][x] && z > 0)
	{
		y = x + 1;
		while (chec->staint[0][y] != 0)
		{
			if (chec->staint[0][y] == chec->staint[0][x])
				ft_printerror("Error\n números repetidos");
			y++;
		}
		x++;
		z--;
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

void	ft_checkorder(t_chec *chec)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < chec->totnum && chec->totnumb == 0)
	{
		y = x + 1;
		while (y < chec->totnum)
		{
			if (chec->staint[0][x] < chec->staint[0][y])
				y++;
			else
			{
				y = -1;
				break ;
			}
		}
		if (y == x - 1)
		{
			printf("KO\n");
			break ;
		}
		x++;
	}
	if (x == chec->totnum)
		printf("OK\n");
}

void	ft_printnumbers(t_chec *chec)
{
	char	*str;
	char	*str2;
	int		x;
	int		y;
	
	str = NULL;
	str2 = NULL;
	x = 0;
	y = chec->totnumb;
	if (chec->totnum > chec->totnumb)
		y = chec->totnum;
	while (x < y)
	{
		str = ft_itoa((int)chec->staint[0][x]);
		if (ft_strncmp(str, "0", 1) == 0 && x >= chec->totnum)
			str = " ";
		str2 = ft_itoa((int)chec->staint[1][x]);
		if (ft_strncmp(str2, "0", 1) == 0 && x >= chec->totnumb)
			str2 = " ";
		printf("%s %s\n", str, str2);
		x++;
	}
	printf("-------\n");
}
