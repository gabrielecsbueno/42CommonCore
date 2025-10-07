/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 08:14:28 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/07 13:07:27 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

#include <ctype.h>
#include <string.h>

int	main(void)
{
	int	i;
	/* teste do Isalpha */
	printf("------ ft_isalpha ------\n\n");
	char	a1 = 'A';

	if (isalpha(a1))
		printf("O . %c es una letra\n\n", a1);
	else
		printf("O . %c no es una letra\n\n", a1);
	if (ft_isalpha(a1))
		printf("C . %c es una letra\n\n", a1);
	else
		printf("C . %c no es una letra\n\n", a1);

	// teste do Isdigit
	printf("------ ft_isdigit ------\n\n");
	char	a2 = '3';

	if (isdigit(a2))
		printf("O . %c es un digito\n\n", a2);
	else
		printf("O . %c no es un digito\n\n", a2);
	if (ft_isdigit(a2))
		printf("C . %c es un digito\n\n", a2);
	else
		printf("C . %c no es un digito\n\n", a2);

	//teste do Isalnum
	printf("------ ft_isalnum ------\n\n");
	char	a3 = 'G';

	if (isalnum(a3))
		printf("O . %c es un alphanumerico\n\n", a3);
	else
		printf("O . %c no es un alphanumerico\n\n", a3);
	if (ft_isalnum(a3))
		printf("C . %c es un alphanumerico\n\n", a3);
	else
		printf("C . %c no es un alphanumerico\n\n", a3);
/*************************achar um jeito de testar este aqui ************/
	//teste do IsAscii
	printf("------ ft_isascii ------\n\n");
	char	a4 = 'f';
//	char	a5 = "é";

	if (isascii(a4))
		printf("O . %c es ASCII\n\n", a4);
	else
		printf("O . %c no es ASCII\n\n", a4);
	if (ft_isascii(a4))
		printf("C . %c es ASCII\n\n", a4);
	else
		printf("C . %c no es ASCII\n\n", a4);

//	if (ft_isascii(a5))
//		printf("C . %c es ASCII\n\n", a5);
//	else
//		printf("C . %c no es ASCII\n\n", a5);
/**************************************************************************/
	//teste do IsPrint
	printf("------ ft_isprint ------\n\n");
	char	a6 = '\n';

	if (isprint(a6))
		printf("O . %c es un imprimible\n\n", a6);
	else
		printf("O . %c no es imprimible\n\n", a6);
	if (ft_isprint(a6))
		printf("C . %c es un imprimible\n\n", a6);
	else
		printf("C . %c no es imprimible\n\n", a6);

	//teste do Strlen
	printf("------ ft_strlen ------\n\n");
	char	str1[15] = "Oi pessoa legal";
	size_t	num1;

	num1 = strlen(str1);
	printf("O . La frase: %s . tiene %ld letras\n\n", str1, num1);

	num1 = ft_strlen(str1);
	printf("C . La frase: %s . tiene %ld letras\n\n", str1, num1);

	//teste do Memset 	NAO ESTA FEITA
	printf("------ ft_memset ------\n\n");
	int	strn1[5] = {10, 20, 30, 40, 50};

	memset(strn1, 0, 18);
	i = 0;
	printf("O . ");
	while (i < 5)
	{
		printf("%d ", strn1[i]);
		i++;
	}
	printf("\n\n");
	memset(str1, '!', sizeof(str1));
	printf("O . %s\n\n", str1);

	//teste do bsero
	//teste do memcpy
	//teste do memmove

	//teste do strlcpy
	printf("------ ft_strlcpy ------\n\n");
	char	cpyl[] = "Bom dia";
	char	cpy2[10] = "Oi ";
	char	cpy3[10];
	size_t	sizecpy = 7;
	size_t	rtcpy;

	rtcpy = strlcpy(cpy2, cpyl, sizecpy);
	printf("O . %s - tamanho = %zu \n\n", cpy2, rtcpy);
	rtcpy = ft_strlcpy(cpy3, cpyl, sizecpy);
	printf("C . %s - tamanho = %zu \n\n", cpy3, rtcpy);

	//teste do strlcat
	printf("------ ft_strlcat ------\n\n");
	char	catl[] = "gente!";
	char	cat2[6] = "Oi ";
	char	cat3[6] = "Oi ";
	size_t	sizecat = 5;
	size_t	rtcat;

	rtcat = strlcat(cat2, catl, sizecat);
	printf("O . %s - tamanho = %zu \n\n", cat2, rtcat);
	rtcat = ft_strlcat(cat3, catl, sizecat);
	printf("C . %s - tamanho = %zu \n\n", cat3, rtcat);

	//teste do toupper
	printf("------ ft_toupper ------\n\n");
	char	ctper = 'g';
	char	rtper;

	rtper = toupper(ctper);
	printf ("O . La letra es : %c \n\n", rtper);
	rtper = ft_toupper(ctper);
	printf ("C . La letra es : %c \n\n", rtper);

	//teste do tolower
	printf("------ ft_tolower ------\n\n");
	char	ctwer = 'A';
	char	rtwer;

	rtwer = tolower(ctwer);
	printf ("O . La letra es : %c \n\n", rtwer);
	rtwer = ft_tolower(ctwer);
	printf ("C . La letra es : %c \n\n", rtwer);

	// fim dos testes
	return (0);
}
