#include <stdio.h>
#include <string.h>
#include <unistd.h>

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int dest_len = 0;

    while (dest[dest_len])
        dest_len++;
    
}

int main(void)
{
    char dest[] = "Hello";
    char src[] = " there";
    unsigned int size = 3; 
    printf("42_f: %s\n", ft_strlcat(dest, src, size));
    printf("Real_f: %s\n", strlcat(dest, src, size));
}