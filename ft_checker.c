/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:11:18 by fballest          #+#    #+#             */
/*   Updated: 2021/03/26 13:15:32 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_getargv(t_chec *chec, char **argv)
{
	int		y;
	char	*c = "ABCDE";

	y = 1;
	chec->info = ft_split(*argv, ' ');
	while (y <= chec->number && argv[y][0])
	{
		if (ft_isdigit(ft_atoi(argv[y])))
		{
			chec->stack[y] = argv[y];
			chec->stack[0] = " ";
			printf("%c - %s - %s\n",c[y], chec->stack[0], chec->stack[1]);
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

void	ft_checkall(t_chec *chec)
{
	char	comp;

	comp = chec->stack[1][0];
}

int		main(int argc, char **argv)
{
	t_chec		*chec;

	chec = malloc(sizeof(t_chec));
	if (!chec)
		return (-1);
	if (argc > 1)
	{
		 chec->number = argc;
		if (ft_getargv(chec, argv) == 0)
			ft_checkall(chec);
	}
	else
		printf("Error\n");
	return (0);
}
