/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:40:32 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/25 17:44:17 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h> 
typedef struct s_list
{
	int						fd;
	char					*content;
	struct s_list	*next;
	struct s_list	*prev;
}		t_list;
size_t	has_lr(const char *str);
char		*ft_substr(const char *str, size_t start, size_t len);
char		*get_line(t_list *cur_node);
char		*join_str(char *s1, char *s2);
char		*get_next_line(int fd);
t_list	*lst_newnode(int fd, char *content);
int			lst_delone(t_list **lst, t_list *node);
t_list	*lst_addback(t_list	**lst, t_list *node);
t_list	*lst_find(t_list *lst, int fd);
int			lst_clear(t_list **lst);

#endif
