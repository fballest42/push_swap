/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:08:19 by fballest          #+#    #+#             */
/*   Updated: 2021/04/17 15:18:49 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_createcommands(t_chec *chec)
{
	if (chec->totnum == 1 && chec->totnumb == 0)
		chec->commands = ft_strjoin(chec->commands, chec->commands = "\n");
	if (chec->totnum == 2 && chec->totnumb == 0)
		chec->commands = ft_strjoin(chec->commands, ft_shortersort(chec));
	if (chec->totnum == 3 && chec->totnumb == 0)
		chec->commands = ft_strjoin(chec->commands, ft_threesort(chec));
	if (chec->totnum > 3 && chec->totnum < 7 && chec->totnumb == 0)
		chec->commands = ft_strjoin(chec->commands, ft_fewsort(chec));
	if (chec->totnum > 6 && chec-> totnum < 13 && chec->totnumb == 0)
		chec->commands = ft_strjoin(chec->commands, ft_midsort(chec));
	if (chec->totnum > 12 && chec->totnum < 121 && chec->totnumb == 0)
		chec->commands = ft_strjoin(chec->commands, ft_centsort(chec));
	if (chec->totnum > 120 && chec->totnum < 240 && chec->totnumb == 0)
		chec->commands = ft_strjoin(chec->commands, ft_totalsort(chec));
}

char	*ft_shortersort(t_chec *chec)
{
	if (chec->staint[0][1] > chec->staint[0][0])
	{
		ft_swapstack_a(chec);
		chec->commands = ft_strjoin(chec->commands, chec->commands = "sa\n");
	}
	else
		chec->commands = ft_strjoin(chec->commands, chec->commands = "");
	return (chec->commands);
}

char	*ft_threesort(t_chec *chec)
{
	ft_checkpositions(chec);

}



void	ft_checpositions(t_chec *chec)
{
	int		x;

	x = 0;
	chec->min = chec->staint[0][0];
	chec->min2 = chec->staint[0][0];
	chec->max = chec->staint[0][0];
	chec->max2 = chec->staint[0][0];
	while (chec->staint[0][x])
	{
		if (chec->staint[0][x] < chec->min)
			chec->min = chec->staint[0][x];
		if (chec->staint[0][x] > chec->max)
			chec->max = chec->staint[0][x];
		if (chec->staint[0][x] < chec->min2 && chec->staint[0][x] > chec->min)
			chec->min2 = chec->staint[0][x];
		if (chec->staint[0][x] > chec->max2 && chec->staint[0][x] < chec->max)
			chec->min2 = chec->staint[0][x];	
	}
}