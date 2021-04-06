/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:11:18 by fballest          #+#    #+#             */
/*   Updated: 2021/04/06 15:29:40 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_printerror(char *str)
{
	printf("%s\n", str);
	exit(-1);
}

void	ft_checknumbers(t_chec *chec, int z)
{
	int		y;

	y = 0;
	while (chec->temp[z][y])
	{
		if ((chec->temp[z][y] >= '0' && chec->temp[z][y] <= '9') ||
			((chec->temp[z][0] == '-' || chec->temp[z][0] == '+') &&
			(chec->temp[z][1] >= '0' && chec->temp[z][y] <= '9')))
			y++;
		else
			ft_printerror("Error");
	}
}

int	ft_getargv(t_chec *chec, char **argv)
{
	int		x;

	x = 1;
	while (argv[x])
	{
		chec->temp[x - 1] = ft_strdup(argv[x]);
		ft_checknumbers(chec, x - 1);
		x++;
	}
	chec->temp[x] = NULL;
	x = 0;

	while (chec->temp[x])
	{
		chec->staint[x] = ft_calloc(sizeof(int), 3);
		if (!chec->staint[x])
			ft_printerror("Error");
		chec->staint[0][x] = ft_atolli(chec->temp[x]);
		x++;
	}
	ft_checknumbers_b(chec);
	return (0);
}

void	ft_getcomands(t_chec *chec, char *line)
{
	int		i;

	i = 0;
	while (get_next_line(0, &line) >= 0)
	{
		ft_checkinst(chec, line);
		ft_printnumbers(chec);
		ft_checkorder(chec);
		free(line);
	}
	free(line);
}

int		main(int argc, char **argv)
{
	t_chec		*chec;
	char		*line;

	line = NULL;
	chec = ft_calloc(sizeof(t_chec), 1);
	if (!chec || argc <= 1)
		return (ft_printerror("Error"));
	chec->totnum = argc - 1;
	chec->temp = ft_calloc(sizeof(char *), chec->totnum + 1);
	chec->staint = ft_calloc(sizeof(int *), chec->totnum + 1);
	if (!chec->temp || !chec->staint)
		return (ft_printerror("Error"));
	if (ft_getargv(chec, argv) == 0)
	{
		ft_printnumbers(chec);
		ft_getcomands(chec, line);
	}
	return (0);
}
