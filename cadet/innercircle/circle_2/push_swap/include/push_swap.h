/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:44:58 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/25 18:06:37 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "deque.h"

void	command_swap(t_deque *dq);
void	command_sa(t_deque *a);
void	command_sb(t_deque *a);
void	command_ss(t_deque *a, t_deque *b);
void	command_push(t_deque *dq);
void	command_pa(t_deque *a, t_deque *b);
void	command_pb(t_deque *a, t_deque *b);
void	command_rotation(t_deque *dq);
void	command_ra(t_deque *a);
void	command_rb(t_deque *b);
void	command_rr(t_deque *a, t_deque *b);
void	command_rotation_reverse(t_deque *dq);
void	command_rra(t_deque *a);
void	command_rrb(t_deque *b);
void	command_rrr(t_deque *a, t_deque *b);

#endif
