// #include "libft.h"
// #include <stdio.h>

// int     str_count(char const *s, char c)
// {
//     int count;

//     count = 0;
//     while (*s)
//         {
//             if (*s == c && *(s+1) != c && *(s+1))
//                 count++;
//             s++;
//         }
//     return (count);
// }

// char    **ft_split(char const *s, char c)
// {
//     char    **array;
//     int     str_ct;
//     int     i;
//     int     j;

//     str_ct = str_count(s, c);
//     // printf("strs: %i\n", str_count);
//     array = malloc((str_ct + 1) * sizeof(char *));
//     if (array == NULL)
//         return (NULL);
//     if (str_ct == 0)
//     {
//         array[0] = s;
//         array[1] = NULL;
//         return (array);
//     }
//     i = 0;
//     j = 0;
//     while (str_ct > 0)
//     {
        
//         str_ct--;
//     }
//     array[i] = NULL;    
//     return (array);
// }

// int main(void)
// {
//     char **array = ft_split("  tripouille  42  ", ' ');
//     int i = 0;

//     while (i < 1)
//     {
//         printf("%s;\n", array[i]);
//         i++;
//     }
// }