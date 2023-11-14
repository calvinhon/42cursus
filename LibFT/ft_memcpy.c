#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    char    *dest_ptr;
    char    *src_ptr;

    dest_ptr = (char *)dest;
    src_ptr = (char *)src;
    while (n > 0)
    {
        *dest_ptr++ = *src_ptr++;
        n--;
    }
    return(dest);
}