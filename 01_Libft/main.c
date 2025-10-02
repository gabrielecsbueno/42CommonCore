#include <stdio.h>
#include "libft.h"

//#include <ctype.h>

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
	printf("------ ft_isdigit ------\n\n");
	char	a2 = '3';

	if(ft_isdigit(a2))
		printf("%c es un digito\n\n", a2);
	else
		printf("%c no es un digito\n\n", a2);
	
	//teste do Isalnum
	printf("------ ft_isalnum ------\n\n");
	char	a3 = 'G';

	if(ft_isalnum(a3))
		printf("%c es un alphanumerico\n\n", a3);
	else
		printf("%c no es un alphanumerico\n\n", a3);
	// fim dos testes
	return (0);
}
