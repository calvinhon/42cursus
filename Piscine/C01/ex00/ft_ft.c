#include <unistd.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int main(void)
{
	int i;
	int *nbr;

	i = 24;
	nbr = &i;

	ft_ft(nbr);
	write(1, &i, 1);
	write(1, "\n", 1);
}
