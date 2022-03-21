void	ft_putstr(char *str);

int	main(void)
{
	char *str1 = "TEST";
	char *str2 = "\0";

	ft_putstr(str1);
	ft_putstr("\n");
	ft_putstr(str2);
}
