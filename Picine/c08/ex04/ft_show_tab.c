 #include <unistd.h>
 #include "ft_stock_str.h"
 int    ft_strlen(char *str);
 void ft_show_tab(struct s_stock_str *par)
 {
	if (!(par) || !(par -> str) || !(par ->copy))
			return ;
	 // put nbr
	write(1, (par -> str), ft_strlen(par -> str));
	write(1, "\n", 1);
	write(1, (par -> copy), ft_strlen(par -> copy));
 }
