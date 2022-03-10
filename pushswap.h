/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:12:33 by fballest          #+#    #+#             */
/*   Updated: 2022/03/10 10:36:32 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h" 

typedef struct s_stack
{
	int			*a;
	int			*b;
	int			*chunk;
	int			c_len;
	int			a_len;
	int			b_len;
	char		**oper;
}				t_stack;

/*
** PUSH_SWAP.C FILES
*/
void		end_sort(t_stack *stack);
void		exit_main(t_stack *stack, int bool);
int			is_sort(t_stack *stack);
void		print_stack(int *stack, int len);
int			main(int argc, char **argv);
int			check_space(char *str);
char		**splitter(char **argv);

/*
** PARSER.C FILES
*/
int			check_num(char **arg);
int			check_args(char **tab);
void		free_tab(char **tab);

/*
** PARSER_2.C FILES
*/
int			parse_duplicate(int *stack, int len);
int			ft_isnum(int ch);
int			check_atoi(const char *str, int *bool);
int			init_a(int *stack, char **operation, int len);
int			init_stack(t_stack *stack, char **operation);

/*
** PARSER_3.C FILES
*/
int			get_sign(char *tab);
int			parse_num(char *tab, int sign);
int			check_len(char **argv);

/*
** MOVES_STD.C FILES
*/
void		swap_a(int *stack);
void		swap_b(int *stack);
void		ss(t_stack *stack);
void		push_a(t_stack *stack);
void		push_b(t_stack *stack);

/*
** MOVES_STD2.C FILES
*/
void		rotate_a(int *stack, int len);
void		rotate_b(int *stack, int len);
void		rr(t_stack *stack);
void		rev_rotate_a(int *stack, int len);
void		rrr(t_stack *stack);

/*
** MOVES_STD3.C FILES
*/
void		rev_rotate_b(int *stack, int len);
void		ft_swap(int *a, int *b);
void		end_five_sort(t_stack *stack);

/*
** UTILS.C FILES
*/
int			get_max_pos(int *stack, int len);
int			get_min_pos(int *stack, int len);
int			get_num_position(int *stack, int num, int len);
int			first_sup(int *stack, int len, int num);
int			first_inf(int *stack, int len, int num);

/*
** UTILS_2.C FILES
*/
void		find_it(int slen, int *stack, int *tmp, int rlen);
void		init_op(int *rest, int *div, int *bool, t_stack *stack);

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
void		insert_up(t_stack *stack, int pos);
void		insert_down(t_stack *stack, int pos);
void		insert_switch(t_stack *stack, int pos);
void		push_up(t_stack *stack, int pos);
void		push_down(t_stack *stack, int pos);

/*
** SOLVE.C FILES
*/
void		exec_operation(char *operation, t_stack *stack);
void		three_sort(t_stack *stack);
void		five_sort(t_stack *stack);
void		hundred_sort(t_stack *stack);
int			execution(t_stack *stack);

/*
** MEDIUM_100.C FILES
*/
int			check_ref(int *chunk, int len, int num);
int			get_biggest(int *stack, int *ref, int slen, int rlen);
void		init_chunk(t_stack *stack);
int			hold_first(t_stack *stack);
int			hold_second(t_stack *stack);

#endif
