/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:40:32 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/04 21:57:09 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h> 

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
	struct s_list	*prev;
}		t_list;
char	*get_next_line(int fd);
size_t	f_find_char(const char *str, const char c);
char	*f_strnjoin(char *s1, const char *s2, size_t len);
char	*f_substr(const char *str, size_t idx, t_list **node);
char	*f_get_line(t_list *node);

t_list	*lst_newnode(int fd, char *content);
char	*lst_delone(t_list **lst, t_list *node);
t_list	*lst_addback(t_list	**lst, t_list *node);
t_list	*lst_find(t_list **lst, int fd);
void	*my_free(void *addr);

#endif
