/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:51:25 by fballest          #+#    #+#             */
/*   Updated: 2021/03/30 09:23:51 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checkorder(t_chec *chec, char **line)
{

}

void	ft_swapstack_a(t_chec *chec)
{
	int		*temp;

	temp = chec->staint[0][0];
	chec->staint[0][0] = chec->staint[0][1];
	chec->staint[0][1] = temp;
}

void	ft_swapstack_b(t_chec *chec)
{
	int		*tmp;

	tmp = chec->staint[1][0];
	chec->staint[1][0] = chec->staint[1][1];
	chec->staint[1][1] = tmp;
}

void	ft_swapstack_ab(t_chec *chec)
{
	ft_swapstack_a(chec);
	ft_swapstack_b(chec);
}

void	ft_pushstack_a(t_chec *chec)
{
	int		*tmpa;
	int		*tmpb;
	int		x;
	int		y;

	x = 0;
	y = 1;
	tmpa = chec->staint[0][0];
	while (chec->staint[0][y])
		chec->staint[0][x++] = chec->staint[0][y++];
	chec->staint[0][y] = NULL;
	while (chec->staint[1][x])
		x++;
	while (x >= 0)
	{
		chec->staint[1][x + 1] = chec->staint[1][x];
		x--;
	}
	chec->staint[1][0] = tmpa;
}

void	ft_pushstack_b(t_chec *chec)
{
	int		*tmpb;
	int		x;
	int		y;

	x = 0;
	y = 1;
	tmpb = chec->staint[1][0];
	while (chec->staint[1][y])
		chec->staint[1][x++] = chec->staint[1][y++];
	chec->staint[1][y] = NULL;
	while (chec->staint[0][x])
		x++;
	while (x >= 0)
	{
		chec->staint[0][x + 1] = chec->staint[0][x];
		x--;
	}
	chec->staint[0][0] = tmpb;
}


void	ft_rotatestack_a(t_chec *chec)
{
	int	*temp;
	int x;
	int	y;

	temp = chec->staint[0][0];
	x = 0;
	y = 1;
	while (chec->staint[0][y])
		chec->staint[0][x++] = chec->staint[0][y++];
	chec->staint[0][y] = temp;
}

void	ft_rotatestack_b(t_chec *chec)
{
	int	*tmp;
	int x;
	int	y;

	temp = chec->staint[1][0];
	x = 0;
	y = 1;
	while (chec->staint[1][y])
		chec->staint[1][x++] = chec->staint[1][y++];
	chec->staint[1][y] = temp;
}

void	ft_rotatestack_ab(t_chec *chec)
{
	ft_rotatestack_a(chec);
	ft_rotatestack_b(chec);
}

void	ft_rotrevstack_a(t_chec *chec)
{

}

void	ft_rotrevstack_b(t_chec *chec)
{

}

void	ft_rotrevstack_ab(t_chec *chec)
{
	
}

void	ft_checkinst(t_chec *chec, char **line)
{
	if (!ft_strncmp(&line, "sa", 2) || ft_strlen(&line) > 2)
		ft_swapstack_a(chec);
	else if (!ft_strncmp(&line, "sb", 2) || ft_strlen(&line) > 2)
		ft_swapstack_b(chec);
	else if (!ft_strncmp(&line, "ss", 2) || ft_strlen(&line) > 2)
		ft_swapstack_ab(chec);
	else if (!ft_strncmp(&line, "pa", 2) || ft_strlen(&line) > 2)
		ft_pushstack_a(chec);
	else if (!ft_strncmp(&line, "pb", 2) || ft_strlen(&line) > 2)
		ft_pushstack_b(chec);
	else if (!ft_strncmp(&line, "ra", 2) || ft_strlen(&line) > 2)
		ft_rotatestack_a(chec);
	else if (!ft_strncmp(&line, "rb", 2) || ft_strlen(&line) > 2)
		ft_rotatestack_b(chec);
	else if (!ft_strncmp(&line, "rr", 2) || ft_strlen(&line) > 2)
		ft_rotatetack_ab(chec);
	else if (!ft_strncmp(&line, "rra", 3) || ft_strlen(&line) > 3)
		ft_rotrevstack_a(chec);
	else if (!ft_strncmp(&line, "rrb", 3) || ft_strlen(&line) > 3)
		ft_rotrevstack_b(chec);
	else if (!ft_strncmp(&line, "rrr", 3) || ft_strlen(&line) > 3)
		ft_rotrevtack_ab(chec);
	else
		ft_printerror("Error\n");
}
