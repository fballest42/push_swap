/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:51:25 by fballest          #+#    #+#             */
/*   Updated: 2022/03/08 23:22:28 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_sign(char *tab)
{
	if (tab[0] == '-')
		return (1);
	if (tab[0] == '+')
		return (2);
	return (0);
}

int	parse_num(char *tab, int sign)
{
	int		i;
	char	*str;

	i = 0;
	str = "2147483647";
	if (sign == 1)
		str = "-2147483648";
	if (sign == 2)
		str = "+2147483647";
	if (ft_strlen(tab) < ft_strlen(str))
		return (0);
	while (tab[i])
	{
		if (tab[i] < str[i])
			return (0);
		if (tab[i] > str[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_len(char **argv)
{
	int	i;
	int	sign;
	int	len;

	i = 1;
	while (argv[i])
	{
		len = ft_strlen(argv[i]);
		sign = get_sign(argv[i]);
		if (len > 11 || \
			(len == 11 && !sign))
			return (1);
		if (len >= 10 && parse_num(argv[i], sign))
			return (1);
		i++;
	}
	return (0);
}
