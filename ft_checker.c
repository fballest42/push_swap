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
			ft_printerror("Error\n");
	}
}

int	ft_getargv(t_chec *chec, char **argv)
{
	int		x;

	x = 1;
	chec->temp = malloc(sizeof(char *) * chec->totarg + 1);
	chec->staint = malloc(sizeof(int *) * chec->totarg + 1);
	if (!chec->temp || !chec->staint)
		return(ft_printerror("Error\n"));
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
		chec->staint[x] = malloc(sizeof(int) * 3);
		if (!chec->staint[x])
			ft_printerror("Error\n");
		ft_bzero(chec->staint[x], sizeof(int));
		chec->staint[x][0] = ft_atoi(chec->temp[x]);
		x++;
	}
	return (0);
}

void	ft_getcomands(t_chec *chec, char **line)
{
	int		fd;
	char	*instr;
	int		i;

	fd = 0;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_checkinst(chec, line);
	}
	ft_checkorder(chec, line);
}

int		main(int argc, char **argv)
{
	t_chec		*chec;
	char		**line;
	int			fd;

	chec = malloc(sizeof(t_chec));
	if (!chec || argc <= 1)
		return(0);
	chec->totarg = argc - 1;
	if (ft_getargv(chec, argv) == 0)
		ft_getcommands(chec, &line);
	return (0);
}
