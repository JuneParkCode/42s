#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef OPEN_MAX
# define OPEN_MAX 256
#endif

# include <stddef.h>

/* get_next_line.c */
char	*get_next_line(int fd);
char	*get_line(char *str);
char	*read_file(int fd, char *store);
char	*get_residue(char *str);

/* get_next_line_utils.c */
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif
