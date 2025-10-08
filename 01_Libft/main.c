/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 08:14:28 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/08 12:01:21 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void	imprime_n(int *n)
{
	int	i = 0;
	while (i < 5)
	{
		printf("%d ", n[i]);
		i++;
	}
	printf("\n\n");
}

int	main(void)
{
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
	int		n_set[5] = {10, 20, 30, 40, 50};
	char	t_set[18] = "Buenos dias amigos";

	printf("O . ");
	memset(n_set, 1802, 4);
	imprime_n(n_set);
	memset(t_set, '!', sizeof(t_set));
	printf("O . %s\n\n", t_set);

	//teste do bzero
	printf("------ ft_bzero ------\n\n");
	//teste do memcpy
	printf("------ ft_memcpy ------\n\n");
	//teste do memmove
	printf("------ ft_memmove ------\n\n");

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

	//teste do strchr
	printf("------ ft_strchr ------\n\n");
	char	chr[] = "Hello World";
	char	c_chr = 'W';

	char	*chr_ptr = strchr(chr, c_chr);
	if (chr_ptr != NULL)
  		printf("O . %s \n\n", chr_ptr);
	else
		printf("O . caractere nao encontrado \n\n");

	char	*chr_ptr2 = ft_strchr(chr, c_chr);
	if (chr_ptr2 != NULL)
  		printf("C . %s \n\n", chr_ptr2);
	else
		printf("C . caractere nao encontrado \n\n");

	//teste do strrchr
	printf("------ ft_strrchr ------\n\n");
	char	rchr[] = "Hello World";
	char	c_rchar = 'l';

	char	*rchr_ptr = strrchr(rchr, c_rchar);
	if (rchr_ptr != NULL)
  		printf("O . %s \n\n", rchr_ptr);
	else
		printf("O . caractere nao encontrado \n\n");

	char	*rchr_ptr2 = ft_strrchr(rchr, c_rchar);
	if (rchr_ptr2 != NULL)
  		printf("C . %s \n\n", rchr_ptr2);
	else
		printf("C . caractere nao encontrado \n\n");

	//teste do strncmp
	printf("------ ft_strncmp ------\n\n");
	char	cmp1[] = "Oi";
	char	cmp2[] = "Oi Meninos";
	size_t	c_cmp = 5;
	int		ret_cmp;

	ret_cmp = strncmp(cmp1, cmp2, c_cmp);
	if (ret_cmp < 0)
		printf("O . '%s' é menor que '%s' - Return = %d \n\n", cmp1, cmp2, ret_cmp);
	else if (ret_cmp > 0)
		printf("O . '%s' é maior que '%s' - Return = %d \n\n", cmp1, cmp2, ret_cmp);
	else if (ret_cmp == 0)
		printf("O . '%s' é igual a '%s' - Return = %d \n\n", cmp1, cmp2, ret_cmp);

	ret_cmp = ft_strncmp(cmp1, cmp2, c_cmp);
	if (ret_cmp < 0)
		printf("C . '%s' é menor que '%s' - Return = %d \n\n", cmp1, cmp2, ret_cmp);
	else if (ret_cmp > 0)
		printf("C . '%s' é maior que '%s' - Return = %d \n\n", cmp1, cmp2, ret_cmp);
	else if (ret_cmp == 0)
		printf("C . '%s' é igual a '%s' - Return = %d \n\n", cmp1, cmp2, ret_cmp);


	//teste do memchr
	printf("------ ft_memchr ------\n\n");


	//teste do memstr
	printf("------ ft_memstr ------\n\n");

	//teste do strnstr
	printf("------ ft_strnstr ------\n\n");
	char	strn_t[] = "O rato roeu a roupa do rei de roma";
	char	strn_b[] = "rom";

	char	*strn_prt = ft_strnstr(strn_t, strn_b, 34);

	if (strn_prt)
		printf("C . Encontrado : '%s' \n\n", strn_prt);
	else
		printf("C . No encontrado %s \n\n", strn_prt);

	//teste do atoi
	printf("------ ft_atoi ------\n\n");
	char	t_atoi[] = "-2147483649";

	int		n_atoi = atoi(t_atoi);
	printf("O . numero = %d\n\n", n_atoi);

	n_atoi = ft_atoi(t_atoi);
	printf("C . numero = %d\n\n", n_atoi);

	// fim dos testes
	return (0);
}
