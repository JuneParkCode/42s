/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:44:58 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/02 13:58:53 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0

# include "deque.h"

typedef int	t_bool;

/* MAIN PUSH_SWAP FUNCTION */
void		push_swap(const int argc, char *argv[]);

/* INPUT PROCESSING FUNCTIONS */
t_bool		get_input(const int argc, char *argv[], t_deque *dq);
t_bool		has_duplicate_number(t_deque *dq);
void		simplify_numbers(t_deque *from, t_deque *to);
long long	atoll(const char *str);

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
