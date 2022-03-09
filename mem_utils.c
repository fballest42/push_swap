/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:43:14 by fballest          #+#    #+#             */
/*   Updated: 2022/03/09 15:17:49 by fballest         ###   ########.fr       */
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

int	ft_matrixlen(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
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

char	**ft_matrixrealloc(char **s1, char **s2)
{
	int		i;
	int		j;
	int		x;
	char	**str;

	i = 0;
	j = 0;
	x = ft_matrixlen(s1) + ft_matrixlen(s2);
	str = (char **)malloc(sizeof(char *) * (x + 1));
	while (i < x)
	{
		if (s1[i] && j == 0)
		{
			str[i] = ft_strdup(s1[i]);
			i++;
		}
		else
			str[i++] = ft_strdup(s2[j++]);
	}
	str[i] = NULL;
	ft_freematrix(s1);
	if (i > 1)
		ft_freematrix(s2);
	return (str);
}

void	ft_freematrix(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != NULL)
	{
		s[i] = NULL;
		free(s[i]);
		i++;
	}
	s = NULL;
	free(s);
}
