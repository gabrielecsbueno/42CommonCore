#include "includes/libft.h"
#include <stdio.h>

int main(void)
{
    // Teste ft_putchar
    ft_putchar('A');
    ft_putchar('\n');
    
    // Teste ft_putstr
    ft_putstr("Ola pra tudo mundo ai!\n");
    
    // Teste ft_strlen
    char *str = "Teste";
    printf("ft_strlen: %d\n", ft_strlen(str));
    
    // Teste ft_strcmp
    char *s1 = "abc";
    char *s2 = "abd";
    printf("ft_strcmp: %d\n", ft_strcmp(s1, s2));
    
    // Teste ft_swap
    int a = 10;
    int b = 20;
    printf("Antes: a=%d, b=%d\n", a, b);
    ft_swap(&a, &b);
    printf("Depois: a=%d, b=%d\n", a, b);
    
    return (0);
}