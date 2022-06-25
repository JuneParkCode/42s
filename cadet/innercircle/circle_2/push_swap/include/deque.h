/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:01:04 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/25 18:20:55 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

typedef int	t_item;

/* for using (pseudo) methods, I used function pointer*/
typedef struct s_deque
{
	int		current_size;
	int		max_size;
	int		front_idx;
	int		back_idx;
	t_item	*datas;
	void	(*push_back)(struct s_deque *self, t_item item);
	void	(*push_front)(struct s_deque *self, t_item item);
	void	(*pop_back)(struct s_deque *self);
	void	(*pop_front)(struct s_deque *self);
	t_item	(*get_back)(struct s_deque * self);
	t_item	(*get_front)(struct s_deque * self);
	int		(*is_full_deque)(struct s_deque *self);
	int		(*is_empty_deque)(struct s_deque *self);
	int		(*get_next_front_idx)(struct s_deque *self);
	int		(*get_prev_front_idx)(struct s_deque *self);
	int		(*get_next_back_idx)(struct s_deque *self);
	int		(*get_prev_back_idx)(struct s_deque *self);
}	t_deque;

/* C,D Funcs for deque */
t_deque	*make_deque(const unsigned int size);
void	delete_deque(t_deque *dq);

/* method functions... */
int		f_dq_get_next_front_idx(t_deque *self);
int		f_dq_get_next_back_idx(t_deque *self);
int		f_dq_get_prev_front_idx(t_deque *self);
int		f_dq_get_prev_back_idx(t_deque *self);
void	f_dq_push_front(t_deque *self, t_item item);
void	f_dq_push_back(t_deque *self, t_item item);
void	f_dq_pop_front(t_deque *self);
void	f_dq_pop_back(t_deque *self);
int		f_dq_is_full_deque(t_deque *self);
int		f_dq_is_empty_deque(t_deque *self);
t_item	f_dq_get_front(t_deque *self);
t_item	f_dq_get_back(t_deque *self);

#endif
