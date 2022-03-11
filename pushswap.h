/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:12:33 by fballest          #+#    #+#             */
/*   Updated: 2022/03/11 00:47:30 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h" 

typedef struct s_data
{
	char		**spl;
	int			*a;
	int			*b;
	int			len_a;
	int			len_b;
	int			len_c;
	int			*chunk;
	char		**oper;
}				t_data;

/*
** PUSH_SWAP.C FILES
*/
void		last_sorter(t_data *stack);
void		freeexit(t_data *stack, int bool);
int			check_order(t_data *stack);
// void		print_data(int *stack, int len);
int			main(int argc, char **argv);
int			check_space(char *str);
char		**get_list(char **argv, int argc, t_data *stack);
char		**number_tolist(char **argv, t_data *stack);
char		**num_counter(char **argv, t_data *stack);

/*
** PARSER.C FILES
*/
int			number_check(char **arg);
// int			argv_check(char **tab);
void		freematrix(char **tab);

/*
** PARSER_2.C FILES
*/
int			check_duplicate(int *stack, int len);
int			ft_isnum(int ch);
int			check_atoi(const char *str, int *bool);
int			stack_a_init(int *stack, char **action, int len);
int			initial_data(t_data *stack, char **action);

/*
** PARSER_3.C FILES
*/
int			get_simbol(char *tab);
int			check_number(char *tab, int sign);
int			size_check(char **argv);

/*
** MOVES_STD.C FILES
*/
void		sa(int *stack);
void		sb(int *stack);
void		ss(t_data *stack);
void		pa(t_data *stack);
void		pb(t_data *stack);

/*
** MOVES_STD2.C FILES
*/
void		ra(int *stack, int len);
void		rb(int *stack, int len);
void		rr(t_data *stack);
void		rra(int *stack, int len);
void		rrr(t_data *stack);

/*
** MOVES_STD3.C FILES
*/
void		rrb(int *stack, int len);
void		swapper(int *a, int *b);
void		sort_last_five(t_data *stack);

/*
** UTILS.C FILES
*/
int			getpos_max(int *stack, int len);
int			getpos_min(int *stack, int len);
int			getpos_number(int *stack, int num, int len);
int			check_up(int *stack, int len, int num);
int			check_down(int *stack, int len, int num);

/*
** UTILS_2.C FILES
*/
void		search_num(int len_s, int *stack, int *tmp, int len_r);
void		start_order(int *rest, int *div, int *bool, t_data *stack);

/*
** MEM_UTILS.C FILES
** INCLUYE TAMBIEN ESTA FUNCION ESTÁTICA --> static char	**realloc_null(char *new);
*/
int			ft_matrixlen(char **arr);
char		**ft_matrixdup(char **arr);
char		**ft_matrixrealloc(char **s1, char **s2, int orig);
char		**realloc_tab(char **tab, char *new);
void		ft_freematrix(char **s);

/*
** GET_POSITION.C FILES
*/
void		putit_up(t_data *stack, int pos);
void		putit_down(t_data *stack, int pos);
void		switch_num(t_data *stack, int pos);
void		up_number(t_data *stack, int pos);
void		down_number(t_data *stack, int pos);

/*
** SOLVE.C FILES
*/
void		exec_sorter(char *action, t_data *stack);
void		sort_three(t_data *stack);
void		sort_five(t_data *stack);
void		sort_hundred(t_data *stack);
int			orderer(t_data *stack);

/*
** MEDIUM_100.C FILES
*/
int			get_references(int *chunk, int len, int num);
int			lookfor_bigger(int *stack, int *ref, int len_s, int len_r);
void		chunk_start(t_data *stack);
int			reserve_first(t_data *stack);
int			reserve_second(t_data *stack);

#endif
