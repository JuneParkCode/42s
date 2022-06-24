#include "deque.h"

t_item  f_dq_get_front(t_deque *self)
{
  return ((self->datas)[self->front_idx]);
}

t_item  f_dq_get_back(t_deque *self)
{
  return ((self->datas)[self->back_idx]);
}
