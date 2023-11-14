#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    while (n > 0)
    {
        if (*((char *)s) == (char)c)
            return((void *)s);
        s++;
        n--;
    }
    s = NULL;
    return((void *)s);
}