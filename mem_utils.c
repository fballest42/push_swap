/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:43:14 by fballest          #+#    #+#             */
/*   Updated: 2022/03/08 23:30:40 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static char	**realloc_null(char *new)
{
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * (2));
	if (!tmp)
		return (NULL);
	tmp[0] = ft_strdup(new);
	tmp[1] = NULL;
	if (tmp[0] == NULL)
		free_tab(tmp);
	return (tmp);
}

char	**realloc_tab(char **tab, char *new)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = NULL;
	if (!tab)
		return (realloc_null(new));
	while (tab[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 2));
	if (!tmp)
		return (NULL);
	while (j < i)
	{
		tmp[j] = ft_strdup(tab[j]);
		j++;
	}
	tmp[j++] = ft_strdup(new);
	tmp[j] = NULL;
	free_tab(tab);
	return (tmp);
}
