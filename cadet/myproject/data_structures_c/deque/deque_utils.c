#include <stdlib.h>
#include "deque.h"

t_deque *make_deque(const int size)
{
  t_deque *dq;

  if (size <= 0 || is_memory_full(sizeof(t_deque) + sizeof(t_item) * size))
      return (NULL);
  dq = (t_deque *)malloc(sizeof(t_deque));
  dq->datas = (t_item *)malloc(sizeof(t_item));
  dq->current_size = 0;
  dq->max_size = size;
  dq->front_idx = 0;
  dq->back_idx = 0;
  dq->push_back = f_dq_push_back;
  dq->push_front = f_dq_push_front;
  dq->pop_back = f_dq_pop_back;
  dq->pop_front = f_dq_pop_front;
  dq->get_back = f_dq_get_back;
  dq->get_front = f_dq_get_front;
  dq->is_full_deque = f_dq_is_full_deque;
  dq->is_empty_deque = f_dq_is_empty_deque;
  dq->get_next_back_idx = f_dq_get_next_back_idx;
  dq->get_next_front_idx = f_dq_get_next_front_idx;
  return (dq);
}

void delete_deque(t_deque *dq)
{
  free(dq->datas);
  free(dq);
}

int is_memory_full(const int size)
{
  void *ptr;

  ptr = malloc(size);
  if (ptr == NULL)
  {
    return (1);
  }
  else
  {
    free(ptr);
    return (0);
  }
}

int f_dq_get_next_front_idx(t_deque *self)
{
  int front_idx;

  front_idx = self->front_idx - 1;
  if (front_idx < 0)
    front_idx += self->max_size;
  return (front_idx);
}

int f_dq_get_next_back_idx(t_deque *self)
{
  int back_idx;

  back_idx = (self->back_idx + 1) % (self->max_size);
  return (back_idx);
}
