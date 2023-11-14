#include <stdio.h>

int change_val(int a)
{
    a = 42;
    printf("%i\n", a);
}

int main(void)
{
    int num;

    num = 0;
    change_val(num);
    printf("%i\n", num);
}