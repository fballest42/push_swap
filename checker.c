/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:11:18 by fballest          #+#    #+#             */
/*   Updated: 2021/04/09 10:22:56 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_printerror(char *str)
{
	printf("%s\n", str);
	exit(-1);
}

void	ft_checknumbers(char *str)
{
	if (*str == '-' && *str == '+')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else
			ft_printerror("Error\n Numeros a ordenar no válidos");
	}
}

int	ft_getargv(t_chec *chec, char **argv)
{
	int		x;

	x = 1;
	while (argv[x])
	{
		ft_checknumbers(argv[x]);
		x++;
	}
	x = 0;
	chec->staint[0] = ft_calloc(sizeof(long int), chec->totnum + 1);
	chec->staint[1] = ft_calloc(sizeof(long int), chec->totnum + 1);
	if (!chec->staint[0] || !chec->staint[1])
		ft_printerror("Error\n Error al reservar memoria");
	while (argv[x + 1])
	{
		chec->staint[0][x] = ft_atolli(argv[x + 1]);
		if (chec->staint[0][x] == 0)
			chec->zero = 1;
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
		return (ft_printerror("Error\n Número de argumentos invalidos"));
	chec->totnum = argc - 1;
	chec->staint = ft_calloc(sizeof(long int *), 3);
	if (!chec->staint)
		return (ft_printerror("Error\n Reserva de memoría fallida"));
	if (ft_getargv(chec, argv) == 0)
	{
		ft_printnumbers(chec);
		ft_getcomands(chec, line);
	}
	return (0);
}
