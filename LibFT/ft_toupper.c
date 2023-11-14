#include "libft.h"

int ft_toupper(int c)
{
    if ((char)c >= 'a' && (char)c <= 'z')
        return(c - 32);
    return(c);
}