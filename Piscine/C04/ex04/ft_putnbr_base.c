#include <unistd.h>

void	ft_putnbr(int nb)
{
	int i;

	i = 0;
	if (nb == -2147483648)
	{
		ft_putnbr(-2);
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		nb += '0';
		write(1, &nb, 1);
	}
}

// #include <stdio.h>
// int main(void)
// {
// 	ft_putnbr(42);
// 	write(1, "\n", 1);
// 	ft_putnbr(-2147483648);
// 	write(1, "\n", 1);
// 	ft_putnbr(2147483647);
// 	write(1, "\n", 1);
// 	ft_putnbr(0);
// 	write(1, "\n", 1);
// 	ft_putnbr(-100);
// 	write(1, "\n", 1);
// }