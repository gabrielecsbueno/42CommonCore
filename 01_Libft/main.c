#include <stdio.h>
#include "libft.h"

int	main(void)
{
	// teste do Isalpha
	printf("------ ft_isalpha ------\n\n");
	char	a1 = 'A';

	if(ft_isalpha(a1))
		printf("%c es una letra\n\n", a1);
	else
		printf("%c no es una letra\n\n", a1);

	// teste do Isdigit 
	printf("------ ft_isadigit ------\n\n");


	// fim dos testes
	return (0);
}
