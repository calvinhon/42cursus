#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    signed char   *ptr;

    ptr = s;
    while (n > 0)
    {
        *ptr++ = (signed char)c;
        n--;
    }
    return(s);
}