#include <unistd.h>

void	ft_putnbr(int nb);
int		ft_strlen(char *str);
void	ft_putnbr(int nb)
{
	unsigned int	n;
	char			c;

	if (nb < 0)
	{
		n = -nb;
		write(1, "-", 1);
	}
	else
		n = nb;
	c = n % 10 + '0';
	n /= 10;
	if (n > 0)
		ft_putnbr(n);
	write(1, &c, 1);
}

int main(void)
{
	char *t1 = "Hello World";
	char *t2 = "";
	char *t3 = "fjlsad;jfldks;ajf;lkdsajf;lkdsjlkfjdsa;lkjf;dlsakjd;lfasd";
	char *t4 = "1234";
	
	ft_putnbr(ft_strlen(t1));
	write(1, "\n", 1);
	ft_putnbr(ft_strlen(t2));	
	write(1, "\n", 1);
	ft_putnbr(ft_strlen(t3));
	write(1, "\n", 1);

	return (0);
}
