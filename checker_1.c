/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:11:18 by fballest          #+#    #+#             */
/*   Updated: 2021/04/27 13:58:45 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_countlines(char **str)
{
	int		x;
	
	x = 0;
	while (str[x] != 0)
		x++;
	return (x);
}

int	ft_printerror(char *str)
{
	printf("%s\n", str);
	exit(-1);
}

void	ft_checknumbers(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else
			ft_printerror("Error\n Numeros a ordenar no válidos");
	}
}

int	ft_getargv(t_chec *chec, char **strarg)
{
	int		x;
	x = chec->i;
	while (x < chec->totnum)
	{
		ft_checknumbers(strarg[x]);
		x++;
	}
	x = 0;
	chec->staint[0] = ft_calloc(sizeof(long int), chec->totnum + 1);
	chec->staint[1] = ft_calloc(sizeof(long int), chec->totnum + 1);
	if (!chec->staint[0] || !chec->staint[1])
		ft_printerror("Error\n Error al reservar memoria");
	while (strarg[x + chec->i] != NULL)
	{
		chec->staint[0][x] = ft_atolli(strarg[x + chec->i]);
		x++;
	}
	ft_checknumbers_b(chec);
	return (0);
}

void	ft_getcomands(t_chec *chec)
{
	int		i;
	char	*str;
	char	*line;

	i = 0;
	str = NULL;
	line = NULL;
	while (get_next_line(0, &line) >= 0)
	{
		if (line[0] == '\00')
		{
			ft_checkorder(chec);
			exit (-2);
		}
		ft_checkinst(chec, line);
		ft_printnumbers(chec);
		ft_checkorder(chec);
		free(line);
	}
	if (line)
		free(line);
}