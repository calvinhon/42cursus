#include <unistd.h>

void ft_is_negative(int n)
{
    if (n < 0)
    {
        write(1, "N", 1);
    }
    else 
    {
        write(1, "P", 1);
    }
}

int main(void)
{
    int n = 0;
    ft_is_negative(n);
    write(1, "\n", 1);
}