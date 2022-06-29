/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:44:58 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/29 19:53:52 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0

# include "ft_printf.h"
# include "deque.h"
typedef int	t_bool;

/* MAIN PUSH_SWAP FUNCTION */
void		push_swap(const long long numbers[]);

/* INPUT PROCESSING FUNCTIONS */
long long	atoll(const char *str);
int			convert_string_to_numbers(const char *strs[], long long arr[]);
t_bool		is_valid_number(const char *str);
t_bool		has_duplicate_number(const long long numbers[]);
void		simplify_numbers(const long long numbers[], long long result[]);
int			push_inputs_to_stack(const long long numbers[], t_deque *stack);

/* SORTING FUNCTIONS */
void		radix_sort(t_deque *a, t_deque *b, const int size);

/* PUSH_SWAP COMMANDS */
void		command_swap(t_deque *dq);
void		command_sa(t_deque *a);
void		command_sb(t_deque *a);
void		command_ss(t_deque *a, t_deque *b);
void		command_push(t_deque *to, t_deque *from);
void		command_pa(t_deque *a, t_deque *b);
void		command_pb(t_deque *a, t_deque *b);
void		command_rotation(t_deque *dq);
void		command_ra(t_deque *a);
void		command_rb(t_deque *b);
void		command_rr(t_deque *a, t_deque *b);
void		command_rotation_reverse(t_deque *dq);
void		command_rra(t_deque *a);
void		command_rrb(t_deque *b);
void		command_rrr(t_deque *a, t_deque *b);

#endif
