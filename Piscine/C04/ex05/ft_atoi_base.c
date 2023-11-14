#include <unistd.h>
#include <stdio.h>

int idx(char str, char *base)
{
    int i;

    i = 0;
    while (base[i])
    {
        if (str == base[i])
            return (i);
        i++;
    }
    return (0);
}

int in_base(char str, char *base)
{
    int i;

    i = 0;
    while (base[i])
    {
        if (str == base[i])
            return (1);
        i++;
    }
    return (0);
}

int	nbr_decimal(char *str, char *base, int len)
{
	int	i;
	int	neg_ct;
	int	nbr;

	i = 0;
	neg_ct = 1;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg_ct *= -1;
		i++;
	}
	while (str[i] && in_base(str[i], base) == 1)
	{
		nbr = nbr * len + idx(str[i], base);
		i++;
	}
	nbr *= neg_ct;
	return (nbr);
}

int	check_arg(char *b, int *l)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (b[*l])
	{
		if (b[*l] == '+' || b[*l] == '-' 
			|| (b[*l] >= 9 && b[*l] <= 13) || b[*l] == ' ')
			return (0);
		*l += 1;
	}
	if (*l < 2)
		return (0);
	while (b[i + 1])
	{
		while (b[i+j])
		{
			if (b[i] == b[i + j])
            {
				return (0);
            }
            j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;

	len = 0;
	if (check_arg(base, &len) == 0)
		return (0);
	return (nbr_decimal(str, base, len));
}

int main(int argc, char **argv)
{
	if (argc != 3)
		write(1, "Input two strings\n", 18);
	else
		printf("%i\n", ft_atoi_base(argv[1], argv[2]));
}