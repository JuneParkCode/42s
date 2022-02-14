#include <stdlib.h>
#define SIZE_CHAR 1
#define SIZE_INT 4

unsigned int    ft_strlen(const char *str)
{
    unsigned int length;

    length = 0;
    while (str[length])
        ++length;
    return (length);
}
s
char    *ft_strdup(char *src)
{
    char    *res;
    
    res = malloc(ft_strlen(src) * SIZE_CHAR);
    while (*src)
    {
        *res = *src;
        res++;
        src++;
    }
    return (res);
}