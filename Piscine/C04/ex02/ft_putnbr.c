#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nb)
{
	int num = nb;
	char n = 0;
	
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10); 
	}
	if (nb < 10)
	{
		n = 48 + nb;
		write(1, &n, 1);
	}
	if (nb / 10 == 0)
	{
		write(1, "\n", 1);
	}
}

int main(void)
{
	ft_putnbr(100);
}