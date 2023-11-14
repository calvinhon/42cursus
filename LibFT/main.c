#include "libft.h"
#include <stdio.h>

// int main(void)
// {
//     unsigned char c = 'z';
//     printf("%i\n", ft_isalpha(c));
//     return(0);
// }

int main(int argc, char **argv)
{
    (void)argc;
    printf("%i\n", ft_atoi(argv[1]));
    return(0);
}