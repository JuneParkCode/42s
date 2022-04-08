
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*store[OPEN_MAX];
	char		*str;
	char		*ret;

	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (store[fd] == NULL)
		store[fd] = ft_strdup("");
	ret = get_line(store[fd]);
	if (ft_strchr(ret, '\n'))
	{
		store[fd] = get_residue(store[fd]);
		return (ret);
	}
	str = read_file(fd, store[fd]);
	if (str == NULL)
		return (NULL);
	ret = ft_strjoin(store[fd], get_line(str));
	free(store[fd]);
	store[fd] = NULL;
	if (ft_strchr(ret, '\n') != NULL)
		store[fd] = get_residue(str);
	free(str);
	return (ret);
}

char	*get_line(char *str)
{
	char	*ret;
	char	*lr_pos;
	size_t	size_ret;
	
	lr_pos = ft_strchr(str, '\n');
	if (lr_pos == NULL)
		return (str);
	size_ret = lr_pos - str + 2;
	ret = malloc(sizeof(char) * size_ret);
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, str, size_ret);
	return (ret);	
}

char	*read_file(int fd, char *store)
{
	char	*ret;
	char	*tmp;
	char	buf[BUFFER_SIZE + 1];
	ssize_t	rd_size;

	ret = ft_strdup("");
	buf[0] = 0;
	while (ft_strchr(buf, '\n') == NULL)
	{
		rd_size = read(fd, buf, BUFFER_SIZE);
		if (rd_size == -1)
		{
			free(store);
			free(ret);
			return (NULL);
		}
		if (rd_size == 0)
			break ;
		buf[rd_size] = 0;
		tmp = ret;
		ret = ft_strjoin(ret, buf);
		free(tmp);
	}
	return (ret);
}

char	*get_residue(char *str)
{
	char	*ret;
	char	*residue;
	size_t	size_ret;

	residue = ft_strchr(str, '\n') + 1;
	if (residue - 1 == NULL)
		return (ft_strdup(""));
	size_ret = ft_strlen(residue) + 1;
	ret = malloc(sizeof(char) * size_ret);
	if (ret)
		return (NULL);
	ft_strlcpy(ret, residue, size_ret);
	return (ret);
}
