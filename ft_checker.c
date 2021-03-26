/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:11:18 by fballest          #+#    #+#             */
/*   Updated: 2021/03/26 12:08:12 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_getargv(t_chec *chec, char **argv)
{
	int		y;
	char	*c = "ABCDE";

	y = 0;
	while (y <= chec->number && argv[y][0])
	{
		if (ft_isdigit(ft_atoi(argv[y])))
		{
			chec->stack[0][y] = argv[y][y + 1];
			chec->stack[1][y] = ' ';
			printf("%c - %d - %d\n",c[y], chec->stack[0][y], chec->stack[1][y]);
			y++;
		}
		else
		{
			printf("Error\n");
			exit (-1);
		}
	}
	return (0);
}

void	ft_checkargv(t_chec *chec)
{
	char	comp;

	comp = chec->stack[1][0];
}

int	main(int argc, char **argv)
{
	t_chec		*chec;

	chec = NULL;
	ft_bzero(chec, sizeof(t_chec));
	chec->number = argc;
	if (ft_getargv(chec, argv) == 0)
		ft_checkargv(chec);
}
