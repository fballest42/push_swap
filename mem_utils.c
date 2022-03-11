/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:43:14 by fballest          #+#    #+#             */
/*   Updated: 2022/03/11 10:13:46 by fballest         ###   ########.fr       */
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
		ft_freematrix(tmp);
	return (tmp);
}

char	**ft_matrixrealloc(char **tab, char *new)
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
	ft_freematrix(tab);
	return (tmp);
}

int	ft_matrixlen(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

char	**ft_matrixdup(char **arr)
{
	int		i;
	char	**ret;

	i = 0;
	ret = malloc(sizeof(char *) * (ft_matrixlen(arr) + 1));
	while (arr[i])
	{
		ret[i] = ft_strdup(arr[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void	ft_freematrix(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}
