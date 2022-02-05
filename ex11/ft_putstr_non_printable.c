#include <unistd.h>

int	ft_char_is_printable(const char c)
{
	return (32 <= c && c < 127);
}

void	ft_print_hex(int n, int length, int depth)
{
	char	*hex = "0123456789abcdef";
	int	i;
	char	c;

	i = 0;
	c = hex[n % 16];
	if (depth < length)
		ft_print_hex(n / 16, length, depth + 1);
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_char_is_printable(str[i]))
		{
			write(1, "\\", 1);
			ft_print_hex(str[i], 2, 1);
		}
		else
			write(1, &str[i], 1);
		++i;
	}
}
