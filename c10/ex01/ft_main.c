#include <string.h>
#include <errno.h>

void	ft_putstr(char *str);
void	ft_msg(char *str, int err_code);
int		ft_display_file(char *file_name);

int	main(int argc, char *argv[])
{
	int	idx;

	if (argc <= 1)
	{
		ft_msg("", errno);
		return (1);
	}
	idx = 1;
	while (idx < argc)
		ft_display_file(argv[idx++]);
	return (0);
}
