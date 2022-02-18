#include <unistd.h>
#include <string.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_put(char *str, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while (idx < size)
		write(1, &str[idx++], 1);
}

void	ft_msg(char *file_name, int err_code)
{
	ft_puterr("cat: ");
	ft_puterr(file_name);
	ft_puterr(": ");
	ft_puterr(strerror(err_code));
	ft_puterr("\n");
}
