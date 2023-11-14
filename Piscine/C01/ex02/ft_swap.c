#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main(void)
{
	int a = 4;
	int b = 2;
	
	int *pa = &a;
	int *pb = &b;

	ft_swap(pa, pb);
	printf("%i\n%i\n", a, b);
}
