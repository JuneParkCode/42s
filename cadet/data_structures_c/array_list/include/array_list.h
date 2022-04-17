
#ifndef ARRAY_LIST_H
# define ARRAY_LIST_H

# include <sys/types.h>
# include <stddef.h>

# define FUNC_ERR 1
# define NOT_FOUND -1
# define SUCCESS 0

/* typdef for item */
typedef int	t_item;

/* struct for array_list */
/* This list is in order */
typedef struct	s_arrlist
{
    t_item	*items;
    ssize_t	front;
    ssize_t	rear;
    ssize_t	max_size;
  	ssize_t	size;
}				t_arrlist;

/* make new array list */
t_arrlist	*arrlst_new_list(size_t size);

/* push item functions */
int			arrlst_push_front(t_arrlist *lst, t_item item);
int			arrlst_push_back(t_arrlist *lst, t_item item);

/* pop item functions */
t_item		arrlst_pop_front(t_arrlist *lst);
t_item		arrlst_pop_back(t_arrlist *lst);

/* find item function */
ssize_t		arrlst_find_item(t_arrlist *lst, t_item item, int(*cmp)(t_item, t_item));

/* get length of list */
int			arrlst_get_size(t_arrlist *lst);

/* check list is full */
int			arrlst_is_full(t_arrlist *lst);

/* check list is empty */
int			arrlst_is_empty(t_arrlist *lst);

/* change max_size of list*/
ssize_t		arrlst_resize(t_arrlist **lst, ssize_t size);

/* copy list */
int			arrlst_copy_list(t_arrlist *dest, t_arrlist *src);

/* swap item function */
int			arrlst_swap(t_arrlist *lst, t_item item_a, t_item item_b, int(*cmp)(t_item, t_item));

/* clear list */
void		arrlst_clear(t_arrlist *lst);

#endif