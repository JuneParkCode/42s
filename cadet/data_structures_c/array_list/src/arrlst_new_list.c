#include <stdlib.h>
#include "array_list.h"

t_arrlist	*arrlst_new_list(size_t size)
{
    t_arrlist   *new_lst;
    t_item      *items;

    new_lst = malloc(sizeof(t_arrlist));
    if (new_lst == NULL)
        return (NULL);
    items = malloc(sizeof(t_item) * size);
    if (items == NULL)
    {
        free(new_lst);
        return (NULL);
    }
    new_lst -> items = items;
    new_lst -> front = -1;
    new_lst -> rear = -1;
    new_lst -> size = 0;
    new_lst -> max_size = size;
    return (new_lst);
}