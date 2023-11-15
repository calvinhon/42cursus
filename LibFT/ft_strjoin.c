#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    int     i;

    str = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
    if (str == NULL)
        return(NULL);
    i = 0;
    ft_memcpy(str, s1, ft_strlen(s1));
    i += ft_strlen(s1);
    ft_memcpy(str + i, s2, ft_strlen(s2));
    i += ft_strlen(s2);
    str[i] = '\0';
    return (str);
}