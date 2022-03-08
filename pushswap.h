/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:12:33 by fballest          #+#    #+#             */
/*   Updated: 2022/03/08 23:22:29 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

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

int			check_len(char **argv);
size_t		ft_strlen(const char *str);
void		ft_bzero(void *s, size_t n);
int			ft_isdigit(int ch);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
void		ft_putchar_fd(char c, int fd);
char		*ft_strdup(const char *src);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			is_sort(t_stack *stack);
int			check_len(char **tab);
void		end_five_sort(t_stack *stack);
void		find_it(int slen, int *stack, int *tmp, int rlen);
void		init_op(int *rest, int *div, int *bool, t_stack *stack);
void		exit_main(t_stack *stack, int bool);
void		push_up(t_stack *stack, int pos);
void		push_down(t_stack *stack, int pos);
void		print_stack(int *stack, int len);
void		insert_up(t_stack *stack, int pos);
void		insert_down(t_stack *stack, int pos);
int			hold_first(t_stack *stack);
int			hold_second(t_stack *stack);
void		insert_down(t_stack *stack, int pos);
void		insert_down(t_stack *stack, int pos);
int			get_max_pos(int *stack, int len);
int			get_min_pos(int *stack, int len);
int			get_num_position(int *stack, int num, int len);
int			first_sup(int *stack, int len, int num);
int			first_inf(int *stack, int len, int num);
void		ft_swap(int *a, int *b);
void		swap_a(int *stack);
void		swap_b(int *stack);
void		ss(t_stack *stack);
void		push_a(t_stack *stack);
void		push_b(t_stack *stack);
void		rotate_a(int *stack, int len);
void		rotate_b(int *stack, int len);
void		rr(t_stack *stack);
void		rev_rotate_a(int *stack, int len);
void		rev_rotate_b(int *stack, int len);
void		rrr(t_stack *stack);
void		resolve(t_stack *stack);
int			execution(t_stack *stack);
int			parse_duplicate(int *stack, int len);
int			init_stack(t_stack *stack, int nb, char **operation);
int			init_a(int *stack, char **operation, int nb);
int			check_atoi(const char *str, int *bool);
char		**realloc_tab(char **tab, char *new);
int			check_num(char **arg);
int			check_args(char **tab);
void		free_tab(char **tab);
int			operation_check(char *operation);
int			valid_operations(char **operation, int i);
void		init_chunk(t_stack *stack);
void		end_sort(t_stack *stack);

#endif