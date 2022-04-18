#include "ft_printf.h"
#include "limits.h"

int main(void)
{
  long long  x = (long long) INT_MAX + 1;
  ft_printf("%d", x);
}
