#include <unistd.h>
int ft_putchar(char c);

char rush(int x, int y)
{
    char A = 'A';
    char B = 'B';
    char C = 'C';
    char n = '\n';
    char b = ' ';
    (void)b;
    if (x == 0 || y == 0)
    {
        write(1, "X and Y must be > 0", 20);
    }
    else if (x == 1)
    {
        ft_putchar(A);
        if (y > 1)
        {
            while (y > 0)
            {
                y-=2;
                ft_putchar(n);
                ft_putchar(B);
            }
            ft_putchar(n);
            ft_putchar(C);
        }
    }
    else if (x == 2 && y > 1)
    {
        ft_putchar(A);
        ft_putchar(C);
        if (y == 2)
        {
            ft_putchar(C);
            ft_putchar(A);
        }
    }
    else 
    {
        x--;
        ft_putchar(A);
        x--;
        while(x >= 1)
        {
            ft_putchar(B);
            x--;
        }
        while(x == 0)
        {
            ft_putchar(C);
            x--;
        }
    }
    ft_putchar(n);
    return (0);
}
