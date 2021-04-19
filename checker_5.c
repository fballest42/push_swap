/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:19:44 by fballest          #+#    #+#             */
/*   Updated: 2021/04/17 14:23:58 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_freememory(t_chec *chec)
{
	int	i;

	i = 0;
	while (chec->staint[i])
	{
		chec->staint[i] = 0;
		free(chec->staint[i]);
	}
	chec->staint = 0;
	free(chec->staint);
	free(chec);
}