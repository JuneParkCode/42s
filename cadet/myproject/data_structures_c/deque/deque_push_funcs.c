
#include "deque.h"

void  f_dq_push_back(t_deque *self, t_item item)
{
  if (self->is_full_deque(self))
    return ;
  self->datas[self->front_idx] = item;
  self->front_idx = self->get_next_front_idx(self);
  if (self->front_idx == self->back_idx)
    self->back_idx = self->get_next_back_idx(self);
  ++(self->current_size);
}

void  f_dq_push_front(t_deque *self, t_item item)
{
  if (self->is_full_deque(self))
    return ;
  self->datas[self->back_idx] = item;
  self->back_idx = self->get_next_back_idx(self);
  if (self->front_idx == self->back_idx)
    self->front_idx = self->get_next_front_idx(self);
  ++(self->current_size);
}
