/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:11:18 by fballest          #+#    #+#             */
/*   Updated: 2021/05/05 10:31:50 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char **argv)
{
	t_chec		*chec;
	char		**num;

	num = NULL;
	chec = ft_calloc(sizeof(t_chec), 1);
	if (!chec || argc <= 1)
		return (-1);
	chec->staint = ft_calloc(sizeof(long int *), 3);
	if (!chec->staint)
		return (ft_printerror("Error\n"));
	if (argc == 2)
	{
		num = ft_split(argv[1], ' ');
		chec->totnum = ft_countlines(num);
		chec->i = 0;
		ft_getargv(chec, num);
	}
	else if (argc > 2)
	{
		chec->totnum = argc - 1;
		chec->i = 1;
		ft_getargv(chec, argv);
	}
	ft_printnumbers(chec);
	ft_getcomands(chec);
	ft_freememory(chec);
	return (0);
}
