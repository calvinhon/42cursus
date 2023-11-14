#include <unistd.h>
#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int main(void)
{
	int a = 5;
	int b = 2;
	int *div = NULL;
	int *mod = NULL;
	ft_div_mod(a, b, div, mod);
	printf("%i\n%i\n", a, b);
}
