/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:51:25 by fballest          #+#    #+#             */
/*   Updated: 2021/04/09 19:57:02 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checknumbers_b(t_chec *chec)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (chec->staint[0][y] != 0 && chec->zero)
	{
		if (chec->staint[0][y] > INT_MAX || chec->staint[0][y] < INT_MIN)
			ft_printerror("Error\n Números más altos de los permitidos");
		y++;
	}
	y = 0;
	while (chec->staint[0][x])
	{
		y = x + 1;
		while (chec->staint[0][y] != 0 && chec->zero)
		{
			if (chec->staint[0][y] == chec->staint[0][x])
				ft_printerror("Error\n números repetidos");
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

void	ft_checkorder(t_chec *chec)
{
	int		x;

	x = 0;
	while (chec->staint[0][x + 1] && !chec->staint[1][0])
	{
		if (chec->staint[0][x] > chec->staint[0][x + 1])
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
	int		x;

	x = 0;
	while (x < chec->totnum)
	{
		char	*str;
		// if (!chec->staint[0][x])
		// 	printf("  ");
		// if (chec->staint[0][x])
		str = ft_itoa((int)chec->staint[1][x]);
		if (ft_strncmp(str, "0", 1) == 0 && !chec->zero)
			str = " ";
	
		printf("%ld %s\n", chec->staint[0][x], str);
		// if (chec->staint[1][x] == 0)
		// 	printf("\n");
		//else if (chec->staint[1][x])
		//	printf("%s\n", ft_itoa((int)chec->staint[1][x]));
		x++;
	}
	printf("-------\n");
}