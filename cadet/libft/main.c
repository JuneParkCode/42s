#include "ft_set_print_color.h"
#include "libft.h"

int	main(void)
{
	ft_printf(ANSI_COLOR_BLUE_BOLD);
	ft_printf("TEST\n");
	ft_printf(ANSI_COLOR_RESET);
	ft_printf("TEST\n");
}
