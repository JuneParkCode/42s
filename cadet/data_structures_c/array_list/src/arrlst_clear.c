#include "array_list.h"

void	arrlst_clear(t_arrlist *lst)
{
    lst -> front = -1;
    lst -> rear = -1;
    lst -> size = 0;
}