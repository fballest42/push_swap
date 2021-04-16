/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:12:33 by fballest          #+#    #+#             */
/*   Updated: 2021/04/16 12:41:10 by fballest         ###   ########.fr       */
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
# include <limits.h>
# include "libft/libft.h"

typedef struct s_chec
{
	int			maxnum;
	int			minnum;
	int			midnum;
	int			totnum;
	int			zero;
	int			zeropos;
	int			zerocol;
	int			totins;
	int			totnumb;
	char		**temp;
	int			tmp;
	long int	**staint;
	char		**stastr;
	char		*instru;
	int			ya;
	int			yb;
	char		*error;
	int			symbol;
	char		symb;
	int			i;
	char		*commands;
	int			min;
	int			min2;
	int			max;
	int			max2;
}				t_chec;

/*
// FILE CHECKER_1.C
*/
int		ft_countlines(char **str);
int		ft_printerror(char *str);
void	ft_checknumbers(char *str);
int		ft_getargv(t_chec *chec, char **argv);
void	ft_getcomands(t_chec *chec);

/*
// FILE CHECKER_2.C
*/
void	ft_checknumbers_b(t_chec *chec);
void	ft_swapstack_a(t_chec *chec);
void	ft_swapstack_b(t_chec *chec);
void	ft_checkorder(t_chec *chec);
void	ft_printnumbers(t_chec *chec);
/*
// FILE CHECKER_3.C
*/
void	ft_rotatestack_ab(t_chec *chec);
void	ft_rotrevstack_a(t_chec *chec);
void	ft_rotrevstack_b(t_chec *chec);
void	ft_rotrevstack_ab(t_chec *chec);
void	ft_checkinst(t_chec *chec, char *line);

// NO USADA void	ft_checkall(t_chec *chec);

/*
// FILE CHECKER_4.C
*/
void	ft_swapstack_ab(t_chec *chec);
void	ft_pushstack_a(t_chec *chec);
void	ft_pushstack_b(t_chec *chec);
void	ft_rotatestack_a(t_chec *chec);
void	ft_rotatestack_b(t_chec *chec);

/*
// FILE PUSHER_1.C
*/
void	ft_createcommands(t_chec *chec);
char	*ft_shortersort(t_chec *chec);
char	*ft_threesort(t_chec *chec);
void	ft_checpositions(t_chec *chec);

#endif
