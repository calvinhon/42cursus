#include "libft.h"

char    *ft_strdup(const char *s)
{
    char    *dest;
    int     len;
    int     i;

    len = 0;
    while (s[len])
        len++;
    dest = malloc(sizeof(char) * len + 1);
    if (dest == NULL)
        return(NULL);
    i = 0;
    while (len > 0)
    {
        dest[i] = s[i];
        i++;
        len--;
    }
    dest[i] = '\0';
    return(dest);
}