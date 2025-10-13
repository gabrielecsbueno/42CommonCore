/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 08:14:28 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/13 09:39:24 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

#include <ctype.h>
#include <locale.h> // para imprimir o é
#include <string.h>
#include <stdlib.h>

void	imprime_n(int *n, int size)
{
	int	i = 0;
	while (i < size)
	{
		printf("%d ", n[i]);
		i++;
	}
	printf("\n\n");
}

int	main(void)
{
	/* teste do Isalpha */
	printf("------ ft_isalpha ------------------------------\n\n");
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
	printf("------ ft_isdigit ------------------------------\n\n");
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
	printf("------ ft_isalnum ------------------------------\n\n");
	char	a3 = 'G';

	if (isalnum(a3))
		printf("O . %c es un alphanumerico\n\n", a3);
	else
		printf("O . %c no es un alphanumerico\n\n", a3);
	if (ft_isalnum(a3))
		printf("C . %c es un alphanumerico\n\n", a3);
	else
		printf("C . %c no es un alphanumerico\n\n", a3);

	//teste do IsAscii
	printf("------ ft_isascii ------------------------------\n\n");

	unsigned char	a5 = 233; //'é' em Latin-1 (ISO-8859-1)

	if (isascii(a5))
		printf("O . %c es ASCII\n\n", a5);
	else
		printf("O . %c no es ASCII\n\n", a5);
	if (ft_isascii(a5))
		printf("C . %c es ASCII\n\n", a5);
	else
		printf("C . %c no es ASCII\n\n", a5);

	//teste do IsPrint
	printf("------ ft_isprint ------------------------------\n\n");
	char	a6 = '\t';

	if (isprint(a6))
		printf("O . %c es un imprimible\n\n", a6);
	else
		printf("O . %c no es imprimible\n\n", a6);
	if (ft_isprint(a6))
		printf("C . %c es un imprimible\n\n", a6);
	else
		printf("C . %c no es imprimible\n\n", a6);

	//teste do Strlen
	printf("------ ft_strlen ------------------------------\n\n");
	char	str1[16] = "Oi pessoa legal";
	size_t	num1;

	num1 = strlen(str1);

	printf("O . La frase: %s . tiene %ld letras\n\n", str1, num1);


	num1 = ft_strlen(str1);
	printf("C . La frase: %s . tiene %ld letras\n\n", str1, num1);

	//teste do Memset
	printf("------ ft_memset -------------------------------\n\n");
	int		n_set1[5] = {10, 20, 30, 40, 50};
	int		n_set = 3;

	char	t_set1[] = "Buenos dias amigo";
	char	t_set = 'A';

	printf("O . La str de INT = ");
	imprime_n(n_set1, (sizeof(n_set1)/4));
	printf("    Passa a ser = ");
	memset(n_set1, n_set, 4);
	imprime_n(n_set1, (sizeof(n_set1)/4));

	printf("O . La str de CHAR = %s\n\n    Passa a ser = ", t_set1);
	memset(t_set1, t_set, (sizeof(t_set1) - 1));
	printf("%s\n\n", t_set1);

	int		n_set2[5] = {10, 20, 30, 40, 50};
	char	t_set2[] = "Buenos dias amigo";

	printf("C . La str de INT = ");
	imprime_n(n_set2, (sizeof(n_set2)/4));
	printf("    Passa a ser = ");
	ft_memset(n_set2, n_set, 4);
	imprime_n(n_set2, (sizeof(n_set2)/4));

	printf("C . La str de CHAR = %s\n\n    Passa a ser = ", t_set2);
	ft_memset(t_set2, t_set, (sizeof(t_set2) - 1));
	printf("%s\n\n", t_set2);

	//teste do bzero
	printf("------ ft_bzero ------------------------------\n\n");
	printf("O . La str de INT = ");
	imprime_n(n_set1, (sizeof(n_set1)/4));
	bzero(n_set1, sizeof(n_set1));
	printf("    Passa a ser = ");
	imprime_n(n_set1, (sizeof(n_set1)/4));

	printf("C . La str de INT = ");
	imprime_n(n_set2, (sizeof(n_set2)/4));
	printf("    Passa a ser = ");
	ft_bzero(n_set2, sizeof(n_set2));
	imprime_n(n_set2, (sizeof(n_set2)/4));

	//teste do memcpy
	printf("------ ft_memcpy ------------------------------\n\n");
//teste de char
	char	s_mcpy[16] = "Oi pessoa legal";
	char	d_mcpy1[50];
	char	d_mcpy2[50];
	size_t	n_mcpy = sizeof(s_mcpy) - 1;

	memcpy(d_mcpy1, s_mcpy, n_mcpy);
	printf("O . La frase = %s - copiada = %zu (bytes)\n\n    La copia = %s\n\n", s_mcpy, n_mcpy, d_mcpy1);

	ft_memcpy(d_mcpy2, s_mcpy, n_mcpy);
	printf("C . La frase = %s - copiada = %zu (bytes)\n\n    La copia = %s\n\n", s_mcpy, n_mcpy, d_mcpy2);
//teste de int
	int		s_int[3] = {1234, 1234, 1234};
	int		d_int1[3] = {6, 6, 6};
	int		d_int2[3] = {6, 6, 6};
	int		n_int = 4;

	printf("O . Los numeros antes = ");
	imprime_n(d_int1, (sizeof(d_int1)/4));
	memcpy(d_int1, s_int, n_int);
	printf("    Agora son = ");
	imprime_n(d_int1, (sizeof(d_int1)/4));

	printf("C . Los numeros antes = ");
	imprime_n(d_int2, (sizeof(d_int1)/4));
	ft_memcpy(d_int2, s_int, n_int);
	printf("    Agora son = ");
	imprime_n(d_int2, (sizeof(d_int2)/4));


	//teste do memmove
	printf("------ ft_memmove ------------------------------\n\n");
	char	s1_mmv[] = "ABCDEFGHIJ";
	char	s2_mmv[] = "ABCDEFGHIJ";

	printf("O . Frase = %s\n\n", s1_mmv);
	memmove((s1_mmv + 3), s1_mmv, 7);
	printf("    Copia = %s\n\n", s1_mmv);

	printf("C . Frase = %s\n\n", s2_mmv);
	ft_memmove((s2_mmv + 3), s2_mmv, 7);
	printf("    Copia = %s\n\n", s2_mmv);

	//teste do strlcpy KO
	printf("------ ft_strlcpy ------------------------------\n\n");
	char	cpyl[8] = "bom dia";
	char	cpy2[8] = "BOM DIA";
	char	cpy3[10];
	size_t	sizecpy = 6;
	size_t	rtcpy;

	rtcpy = strlcpy(cpy2, cpyl, sizecpy);
	printf("O . La frase = %s - copiada %zux\n\n    Str copia = %s - tamanho original = %zu \n\n",cpyl, sizecpy, cpy2, rtcpy);
	rtcpy = ft_strlcpy(cpy3, cpyl, sizecpy);
	printf("C . La frase = %s - copiada %zux\n\n    Str copia = %s - tamanho original = %zu \n\n",cpyl, sizecpy, cpy3, rtcpy);

	//teste do strlcat
	printf("------ ft_strlcat ------------------------------\n\n");
	char	cat[] = "Dia";
	char	cat1[20] = "Bom ";
	char	cat2[20] = "Bom ";
	size_t	sizecat = 9;
	size_t	rtcat;

	rtcat = strlcat(cat1, cat, sizecat);
	printf("O . %s - tamanho = %zu \n\n", cat1, rtcat);
	rtcat = ft_strlcat(cat2, cat, sizecat);
	printf("C . %s - tamanho = %zu \n\n", cat2, rtcat);

	//teste do toupper
	printf("------ ft_toupper ------------------------------\n\n");
	char	ctper = 'g';
	char	rtper;

	rtper = toupper(ctper);
	printf ("O . La letra = %c\n\n    Maiusculo = %c \n\n", ctper, rtper);
	rtper = ft_toupper(ctper);
	printf ("O . La letra = %c\n\n    Maiusculo = %c \n\n", ctper, rtper);

	//teste do tolower
	printf("------ ft_tolower ------------------------------\n\n");
	char	ctwer = 'A';
	char	rtwer;

	rtwer = tolower(ctwer);
	printf ("O . La letra = %c\n\n    Minusculo = %c \n\n", ctwer, rtwer);
	rtwer = ft_tolower(ctwer);
	printf ("O . La letra = %c\n\n    Minusculo = %c \n\n", ctwer, rtwer);

	//teste do strchr
	printf("------ ft_strchr ------------------------------\n\n");
	char	chr[] = "Hello World";
	char	c_chr = 'W';

	printf("O . En la frase = %s - busca = %c\n\n", chr, c_chr);
	char	*chr_ptr = strchr(chr, c_chr);
	if (chr_ptr != NULL)
  		printf("    Encontrado en = %s \n\n", chr_ptr);
	else
		printf("    Nao encontrado \n\n");

	printf("C . En la frase = %s - busca o primeiro = %c\n\n", chr, c_chr);
	char	*chr_ptr2 = ft_strchr(chr, c_chr);
	if (chr_ptr2 != NULL)
  		printf("    Encontrado en = %s \n\n", chr_ptr2);
	else
		printf("    Nao encontrado \n\n");

	//teste do strrchr
	printf("------ ft_strrchr ------------------------------\n\n");
	char	rchr[] = "Hello World";
	char	c_rchar = 'l';

	printf("O . En la frase = %s - busca o ultimo = %c\n\n", rchr, c_rchar);
	char	*rchr_ptr = strrchr(rchr, c_rchar);
	if (rchr_ptr != NULL)
  		printf("    Encontrado en = %s \n\n", rchr_ptr);
	else
		printf("    Nao encontrado \n\n");

	printf("C . En la frase = %s - busca o ultimo = %c\n\n", rchr, c_rchar);
	char	*rchr_ptr2 = ft_strrchr(rchr, c_rchar);
	if (rchr_ptr2 != NULL)
  		printf("    Encontrado en = %s \n\n", rchr_ptr2);
	else
		printf("    Nao encontrado \n\n");

	//teste do strncmp
	printf("------ ft_strncmp ------------------------------\n\n");
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
	printf("------ ft_memchr ------------------------------\n\n");
	char	mchr[] = "Hello World";
	char	c_mchr = 'l';

	printf("O . En la frase = %s - busca o primeiro = %c\n\n", mchr, c_mchr);
	char	*mchr_ptr = memchr(mchr, c_mchr, (sizeof(mchr) - 1));
	if (mchr_ptr != NULL)
  		printf("    Encontrado en = %s \n\n", mchr_ptr);
	else
		printf("    Nao encontrado \n\n");

	printf("C . En la frase = %s - busca o primeiro = %c\n\n", mchr, c_mchr);
	mchr_ptr = ft_memchr(mchr, c_mchr, (sizeof(mchr) - 1));
	if (mchr_ptr != NULL)
  		printf("    Encontrado en = %s \n\n", mchr_ptr);
	else
		printf("    Nao encontrado \n\n");

	//teste do memcmp
	printf("------ ft_memcmp ------------------------------\n\n");

	char	mcmp1[] = "Oi";
	char	mcmp2[] = "Oi Meninos";
	size_t	c_mcmp = 3;
	int		ret_mcmp;

	ret_mcmp = memcmp(mcmp1, mcmp2, c_mcmp);
	if (ret_mcmp < 0)
		printf("O . '%s' é menor que '%s' - Return = %d \n\n", mcmp1, mcmp2, ret_mcmp);
	else if (ret_mcmp > 0)
		printf("O . '%s' é maior que '%s' - Return = %d \n\n", mcmp1, mcmp2, ret_mcmp);
	else if (ret_mcmp == 0)
		printf("O . '%s' é igual a '%s' - Return = %d \n\n", mcmp1, mcmp2, ret_mcmp);

	ret_mcmp = ft_memcmp(mcmp1, mcmp2, c_mcmp);
	if (ret_mcmp < 0)
		printf("C . '%s' é menor que '%s' - Return = %d \n\n", mcmp1, mcmp2, ret_mcmp);
	else if (ret_mcmp > 0)
		printf("C . '%s' é maior que '%s' - Return = %d \n\n", mcmp1, mcmp2, ret_mcmp);
	else if (ret_mcmp == 0)
		printf("C . '%s' é igual a '%s' - Return = %d \n\n", mcmp1, mcmp2, ret_mcmp);

	//teste do strnstr
	printf("------ ft_strnstr ------------------------------\n\n");
	char	strn_t[] = "O rato roeu a roupa do rei de roma";
	char	strn_b[] = "rom";

	printf("C . En la frase = %s\n\n    Busca por = %s\n\n", strn_t, strn_b);
	char	*strn_prt = ft_strnstr(strn_t, strn_b, 34);

	if (strn_prt)
  		printf("    Encontrado en = %s \n\n", strn_prt);
	else
		printf("    Nao encontrado \n\n");

	//teste do atoi
	printf("------ ft_atoi ------------------------------\n\n");
	char	t_atoi[] = "	-276";

	int		n_atoi = atoi(t_atoi);
	printf("O . numero = %d\n\n", n_atoi);

	n_atoi = ft_atoi(t_atoi);
	printf("C . numero = %d\n\n", n_atoi);

	//teste do calloc
	printf("------ ft_calloc ------------------------------\n\n");
	int n_cloc = 15;

	int *s1_cloc = calloc(n_cloc, sizeof(int));
	int *s2_cloc = calloc(n_cloc, sizeof(int));

	imprime_n(s1_cloc, n_cloc);
	imprime_n(s2_cloc, n_cloc);
	free(s1_cloc);
	free(s2_cloc);
	s1_cloc = NULL;
	s2_cloc = NULL;

	//teste do strdup
	printf("------ ft_strdup ------------------------------\n\n");

	// fim dos testes

	printf("---------------------------------------------\n\n");
	return (0);
}
