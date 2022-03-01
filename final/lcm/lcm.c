#include <stdio.h>

int gcm(int a, int b)
{
    int x;
    int y;
    
    x = a > b ? a : b;
    y = a > b ? b : a;
    if (b == 0)
        return (a);
    return (gcm(b, a % b));
}
int lcm(int a, int b)
{
    int n = gcm(a, b);
    return (a * b / n);
}

int main()
{
    int x = 6;
    int y = 10;
    printf("%d, %d  lcm : %d  gcm : %d\n", x, y, lcm(x, y), gcm(x, y));
}