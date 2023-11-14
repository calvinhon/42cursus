#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char       *dest_p;
    const unsigned char *src_p;

    dest_p = dest;
    src_p = src;
    if (dest_p == src_p)
        return(dest);
    if (dest_p < src_p)
        while (n > 0)
        {
            *dest_p++ = *src_p++;
            n--;
        }
    else
        {
            dest_p += n - 1;
            src_p += n - 1;
            while (n > 0)
            {
                *dest_p-- = *src_p--;
                n--;
            }
        }
    return(dest);
}