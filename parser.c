/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:49:46 by fballest          #+#    #+#             */
/*   Updated: 2022/03/11 09:26:21 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	number_check(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		printf("%d\n", i);
		j = 0;
		while (arg[i][j])
		{
			if (arg[i][0] == '-' || arg[i][0] == '+')
				j++;
			if (!ft_isdigit(arg[i][j++]))
				return (1);
		}
		i++;
	}
	return (0);
}

// int	argv_check(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		if (ft_strncmp(tab[i], "pa", 3))
// 			return (1);
// 	}
// 	return (0);
// }

void	freematrix(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}
