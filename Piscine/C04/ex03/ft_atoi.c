#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int white_space(char str)
{
    if ((str >= 9 && str <= 13) || str == ' ')
        return (1);
    else
        return (0);
}

int is_num(char str)
{
    if (str >= '0' && str <= '9')
        return (1);
    else
        return (0);
}

int ft_atoi(char *str)
{
    long    num;
    int     i;
    int     neg_ct;

    num = 0;
    i = 0;
    neg_ct = 1;
    while (white_space(str[i]))
        i++; 
    while ((str[i] == '+' || str[i] == '-'))
    {
        if (str[i] == '-')
            neg_ct *= -1;
        i++;
    }
    while (is_num(str[i]))
    {
        num = num * 10 + str[i] - '0';
        i++;
    }
    if (num * neg_ct > 2147483647 || num * neg_ct < -2147483648)
        return (0);
    return (num * neg_ct);
}

int main(int argc, char **argv)
{
    if (argc < 2)
        printf("Please fucking input one argument\n");
    else
    {
        printf("num = %i\n", ft_atoi(argv[1]));
        printf("num = %i\n", atoi(argv[1]));
    }
}
   