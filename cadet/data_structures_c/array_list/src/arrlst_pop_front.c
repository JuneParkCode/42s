#include "array_list.h"

/*  if lst is empty -> undefined */
t_item	arrlst_pop_front(t_arrlist *lst)
{
    t_item 	item;
    ssize_t	pos;

    item = lst -> items[lst -> front];
    pos = lst -> front + 1;
    if (pos >= lst -> max_size)
        pos = pos % lst -> max_size;
    lst -> front = pos;
    --(lst -> size);
    return (item);
}