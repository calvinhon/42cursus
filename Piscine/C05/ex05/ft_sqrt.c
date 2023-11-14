#include <unistd.h>
#include <stdio.h>

int ft_sqrt(int nb)
{
    int i;

    i = 1;
    while (i * i < nb && i < 46340)
    {
        i++;
        if (i * i == nb)
            return (i);
    }
    return (0);
}

int main(void)
{
    printf("%i\n", ft_sqrt(2147395600));
}