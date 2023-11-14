#include <unistd.h>
#include <stdio.h>

int ft_find_next_prime(int nb)
{
    int i;

    i = 2;
    if (nb == 0 || nb == 1 || nb == -2147483648)
        return (0);
    if (nb < 0)
        nb *= -1;
    while (i < nb)
    {
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int main(void)
{
    printf("%i\n", ft_find_next_prime(-2147483648));
}