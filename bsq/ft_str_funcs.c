
#include <unistd.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		++length;
	return (length);
}

int	ft_is_printable(char c)
{
	return (32 <= c && c < 127);
}

void	ft_show_strs(char **strs)
{
	int	idx_strs;
	while (strs[idx_strs])
	{
		write(1, strs[idx_strs], ft_strlen(strs[idx_strs]));
		idx_strs++;
		write(1, "\n",1);
	}
}

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}