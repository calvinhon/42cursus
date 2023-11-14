#include <unistd.h>
#include <stdio.h>

void ft_print_alphabet(void)
{
    char i = 'a';
    while (i <= 'z')
    {
        write(1, &i, 1);
        i++;
    }
}

int main(void)
{
    ft_print_alphabet();
    printf("\n");
}