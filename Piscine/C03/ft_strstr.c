#include <unistd.h>
#include <string.h>
#include <stdio.h>

char    *ft_strstr(char *str, char *to_find)
{
    int s_idx = 0;
    int tf_idx = 0;

    while (str[s_idx])
    {
        while (str[s_idx + tf_idx] == to_find[tf_idx] && to_find[tf_idx])
            {
                tf_idx++;
                if (to_find[tf_idx] == '\0')
                    return (&str[s_idx]);
            }
        s_idx++;
        tf_idx = 0;
    }
    return (0);
}

int main(void)
{
    char *haystack = "Hello     there and bye";
    char *needle = "Hh";
    printf("42_f: %s\n", strstr(haystack, needle));
    printf("Real_f: %s\n", strstr(haystack, needle));
}