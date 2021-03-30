/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:12:33 by fballest          #+#    #+#             */
/*   Updated: 2021/03/26 13:08:23 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include "libft/libft.h"

typedef struct	s_chec
{
	int					posmax;
	int					posmin;
	int					middle;
	int					number;
	char				**stack;
	char				**info;
	int					ya;
	int					yb;
}				t_chec;

int		ft_getargv(t_chec *chec, char **argv);
void	ft_checkall(t_chec *chec);

#endif
