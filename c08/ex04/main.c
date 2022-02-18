#include <unistd.h>
#include <string.h>
#include "ft_stock_str.h"

void				ft_show_tab(struct s_stock_str *par);
struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ste_putstr(char *str)
{
	write(1, str, strlen(str));
}

void	do_test(struct s_stock_str* par)
{
	if (!par)
	{
		ste_putstr("(NULL)\n");
		return ;
	}
    while (1)
    {
        ft_show_tab(par);
        write(1, "\n", 1);
		if (!(par -> str))
			return ;
		++par;
    }
}

int main(void)
{
	do_test(ft_strs_to_tab(0, 0));

	char *av1[] = { "HelloWorld!" };
	do_test(ft_strs_to_tab(1, av1));

	char *av2[] = { "Hello", "42", "SEOUL!" };
	do_test(ft_strs_to_tab(3, av2));

	char *av3[] = { "", "", "Hello 42 SEOUL!" };
	do_test(ft_strs_to_tab(3, av3));

	char *av4[] = { "Show", "me", "the", "money" };
	do_test(ft_strs_to_tab(4, av4));

	char *av5[] = { "Operation", "CWAL", "Do not print this!", "Do not print this!!!!" };
	do_test(ft_strs_to_tab(2, av5));

	char *av6[] = { "Smoke", "in", "the", "water" };
	do_test(ft_strs_to_tab(3, av6));
	
	struct s_stock_str a;
	a.size = 0;
	a.str = 0;
	a.copy = 0;
	ft_show_tab(&a);
	return (0);
}
