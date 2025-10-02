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
// *************************achar um jeito de testar este aqui ************
	//teste do IsAscii
	printf("------ ft_isascii ------\n\n");
	char	a4 = 'f';
//	char	a5 = "é";

	if(ft_isascii(a4))
		printf("%c es ASCII\n\n", a4);
	else
		printf("%c no es ASCII\n\n", a4);

//	if(ft_isascii(a5))
//		printf("%c es ASCII\n\n", a5);
//	else
//		printf("%c no es ASCII\n\n", a5);
/**************************************************************************/
	//teste do IsPrint
	printf("------ ft_isprint ------\n\n");
	char	a6 = '\n';

	if(ft_isprint(a6))
		printf("%c es un imprimible\n\n", a6);
	else
		printf("%c no es imprimible\n\n", a6);
	
	//teste do Strlen
	printf("------ ft_strlen ------\n\n");
	char	str1[15] = "Oi pessoa legal";
	size_t	num1 = ft_strlen(str1);
	printf("La frase: %s . tiene %ld letras\n\n", str1, num1);
	
	// fim dos testes
	return (0);
}
