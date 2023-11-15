#include "libft.h"
#include <stdio.h>

int     c_count(char const *s, char c)
{
    int count;

    count = 0;
    while (*s)
        {
            if (*s == c && *(s+1) != c)
                count++;
            s++;
        }
    return (count);
}

char    **ft_split(char const *s, char c)
{
    char    **array;
    char    *str;
    int     str_count;
    int     i;
    int     start;

    str = (char *)s;
    str_count = c_count(s, c);
    printf("strs: %i\n", str_count);
    i = 0;
    start = 0;
    array = malloc((str_count + 1) * sizeof(char *));
    if (array == NULL)
        return (array);
    while (*str)
    {
        array[i++] = ft_substr(str, start, ft_strchr(str, c) - str);
        str = ft_strchr(str, c) + 1;
    }
    array[i] = NULL;    
    return (array);
}

int main(void)
{
    char **array = ft_split("  tripouille  42  ", ' ');
    int i = 0;

    while (i < 4)
    {
        printf("%s;\n", array[i]);
        i++;
    }
}