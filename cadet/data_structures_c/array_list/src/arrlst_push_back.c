#include "array_list.h"

int	arrlst_push_back(t_arrlist *lst, t_item item)
{
    ssize_t	pos;

    if (arrlst_is_full(lst))
        return (FUNC_ERR);
    if (arrlst_is_empty(lst))
    {
        if (lst -> front == -1)
            pos = 0;
        else
            pos = lst -> front;
        lst -> front = pos;
        lst -> rear = pos;
    }
    else
    {
        pos = lst -> rear + 1;
        if (pos >= lst -> max_size)
            pos = pos % lst -> max_size;
        lst -> rear = pos;
    }
    lst -> items[pos] = item;
    ++(lst -> size);
    return (SUCCESS);
}