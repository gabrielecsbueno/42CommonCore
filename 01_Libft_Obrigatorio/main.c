#include <stdio.h>
#include "libft.h"

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <bsd/string.h>
#include <fcntl.h>		// para open()
#include <unistd.h>		// para close()
#include <locale.h>		// para imprimir acentos em pt

void	ft_imprime_n(int *n, int size)
{
	int	i = 0;
	while (i < size)
	{
		printf("%d ", n[i]);
		i++;
	}
	printf("\n\n");
}

char	ft_addindex(unsigned int i, char c) // teste do ft_strmapi
{
	return (c + i);
}

void	ft_changepair(unsigned int i, char *c) // teste do ft_strmapi
{
	if (i % 2 == 0)
		*c = '*';
}

int	main(void)
{
	setlocale(LC_ALL, "Portuguese");
	printf("\n------------------------------ PARTE 1 --------------------------------\n\n");
	printf("'O . ' = Función Original \n\n");
	printf("'C . ' = Función Creada \n\n");

	/* teste do Isalpha */
	printf("------------------------------ ft_isalpha ------------------------------\n\n");
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
	printf("------------------------------ ft_isdigit ------------------------------\n\n");
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
	printf("------------------------------ ft_isalnum ------------------------------\n\n");
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
	printf("------------------------------- ft_isascii ------------------------------\n\n");

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
	printf("------------------------------ ft_isprint ------------------------------\n\n");
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
	printf("------------------------------ ft_strlen ------------------------------\n\n");
	char	str1[] = "Oi pessoa legal";
	size_t	num1;

	num1 = strlen(str1);
	printf("O . La frase: %s . tiene %ld letras\n\n", str1, num1);

	num1 = ft_strlen(str1);
	printf("C . La frase: %s . tiene %ld letras\n\n", str1, num1);

	//teste do Memset
	printf("------------------------------ ft_memset -------------------------------\n\n");
	int		n_set1[5] = {10, 20, 30, 40, 50};
	int		n_set = 3;

	char	t_set1[] = "Buenos dias amigo";
	char	t_set = 'A';

	printf("O . La str INT = ");
	ft_imprime_n(n_set1, (sizeof(n_set1)/4));
	printf("    Se convierte = ");
	memset(n_set1, n_set, 4);
	ft_imprime_n(n_set1, (sizeof(n_set1)/4));

	printf("O . La str de CHAR = %s\n\n    Se convierte = ", t_set1);
	memset(t_set1, t_set, (sizeof(t_set1) - 1));
	printf("%s\n\n", t_set1);

	int		n_set2[5] = {10, 20, 30, 40, 50};
	char	t_set2[] = "Buenos dias amigo";

	printf("C . La str de INT = ");
	ft_imprime_n(n_set2, (sizeof(n_set2)/4));
	printf("    Se convierte = ");
	ft_memset(n_set2, n_set, 4);
	ft_imprime_n(n_set2, (sizeof(n_set2)/4));

	printf("C . La str de CHAR = %s\n\n    Se convierte = ", t_set2);
	ft_memset(t_set2, t_set, (sizeof(t_set2) - 1));
	printf("%s\n\n", t_set2);

	//teste do bzero
	printf("------------------------------ ft_bzero ------------------------------\n\n");
	printf("O . La str de INT = ");
	ft_imprime_n(n_set1, (sizeof(n_set1)/4));
	bzero(n_set1, sizeof(n_set1)); //teste com as variaveis do Memset
	printf("    Se convierte = ");
	ft_imprime_n(n_set1, (sizeof(n_set1)/4));

	printf("C . La str de INT = ");
	ft_imprime_n(n_set2, (sizeof(n_set2)/4));
	printf("    Se convierte = ");
	ft_bzero(n_set2, sizeof(n_set2)); //teste com as variaveis do Memset
	ft_imprime_n(n_set2, (sizeof(n_set2)/4));

	//teste do memcpy
	printf("------------------------------ ft_memcpy ------------------------------\n\n");
	//teste de char
	char	s_mcpy[] = "Oi pessoa legal";
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
	ft_imprime_n(d_int1, (sizeof(d_int1)/4));
	memcpy(d_int1, s_int, n_int);
	printf("    Agora son = ");
	ft_imprime_n(d_int1, (sizeof(d_int1)/4));

	printf("C . Los numeros antes = ");
	ft_imprime_n(d_int2, (sizeof(d_int1)/4));
	ft_memcpy(d_int2, s_int, n_int);
	printf("    Agora son = ");
	ft_imprime_n(d_int2, (sizeof(d_int2)/4));

	//teste do memmove
	printf("------------------------------ ft_memmove ------------------------------\n\n");
	char	s1_mmv[] = "ABCDEFGHIJ";
	char	s2_mmv[] = "ABCDEFGHIJ";

	printf("O . Frase = %s\n\n", s1_mmv);
	memmove((s1_mmv + 3), s1_mmv, 7);
	printf("    Copia = %s\n\n", s1_mmv);

	printf("C . Frase = %s\n\n", s2_mmv);
	ft_memmove((s2_mmv + 3), s2_mmv, 7);
	printf("    Copia = %s\n\n", s2_mmv);

	//teste do strlcpy
	printf("------------------------------ ft_strlcpy ------------------------------\n\n");
	// O TESTE DA FUNCAO ORIGINAL, NOS COMPUTADORES DA 42 TEM QUE SER COMPILADO COM AS FLAGS NECESSARIAS
	char	cpyl[8] = "bom dia";
//	char	cpy2[8] = "BOM DIA";
	char	cpy3[10];
	size_t	sizecpy = 6;
	size_t	rtcpy;

//	rtcpy = strlcpy(cpy2, cpyl, sizecpy);
//	printf("O . La frase = %s - copiada %zux\n\n    Str copia = %s - size original = %zu \n\n",cpyl, sizecpy, cpy2, rtcpy);

	rtcpy = ft_strlcpy(cpy3, cpyl, sizecpy);
	printf("C . La frase = %s - copiada %zux\n\n    Str copia = %s - size original = %zu \n\n",cpyl, sizecpy, cpy3, rtcpy);

	//teste do strlcat
	printf("------------------------------ ft_strlcat ------------------------------\n\n");
	// O TESTE DA FUNCAO ORIGINAL, NOS COMPUTADORES DA 42 TEM QUE SER COMPILADO COM AS FLAGS NECESSARIAS
	char	cat[] = "Dia";
//	char	cat1[20] = "Bom ";
	char	cat2[20] = "Bom ";
	size_t	sizecat = 9;
	size_t	rtcat;

//	rtcat = strlcat(cat1, cat, sizecat);
//	printf("O . %s - size = %zu \n\n", cat1, rtcat);

	rtcat = ft_strlcat(cat2, cat, sizecat);
	printf("C . %s - size = %zu \n\n", cat2, rtcat);

	//teste do toupper
	printf("------------------------------ ft_toupper ------------------------------\n\n");
	char	ctper = 'g';
	char	rtper;

	rtper = toupper(ctper);
	printf ("O . La letra = %c\n\n    Maiusculo = %c \n\n", ctper, rtper);
	rtper = ft_toupper(ctper);
	printf ("O . La letra = %c\n\n    Maiusculo = %c \n\n", ctper, rtper);

	//teste do tolower
	printf("------------------------------ ft_tolower ------------------------------\n\n");
	char	ctwer = 'A';
	char	rtwer;

	rtwer = tolower(ctwer);
	printf ("O . La letra = %c\n\n    Minusculo = %c \n\n", ctwer, rtwer);
	rtwer = ft_tolower(ctwer);
	printf ("O . La letra = %c\n\n    Minusculo = %c \n\n", ctwer, rtwer);

	//teste do strchr
	printf("------------------------------ ft_strchr ------------------------------\n\n");
	char	chr[] = "Hello World";
	char	c_chr = 'W';

	printf("O . En la frase = %s - busca = %c\n\n", chr, c_chr);
	char	*chr_ptr = strchr(chr, c_chr);
	if (chr_ptr != NULL)
  		printf("    Encontrado en = %s \n\n", chr_ptr);
	else
		printf("    No encontrado \n\n");

	printf("C . En la frase = %s - busca el primeiro = %c\n\n", chr, c_chr);
	char	*chr_ptr2 = ft_strchr(chr, c_chr);
	if (chr_ptr2 != NULL)
  		printf("    Encontrado en = %s \n\n", chr_ptr2);
	else
		printf("    No encontrado \n\n");

	//teste do strrchr
	printf("------------------------------ ft_strrchr ------------------------------\n\n");
	char	rchr[] = "Hello World";
	char	c_rchar = 'l';

	printf("O . En la frase = %s - busca el ultimo = %c\n\n", rchr, c_rchar);
	char	*rchr_ptr = strrchr(rchr, c_rchar);
	if (rchr_ptr != NULL)
  		printf("    Encontrado en = %s \n\n", rchr_ptr);
	else
		printf("    No encontrado \n\n");

	printf("C . En la frase = %s - busca o ultimo = %c\n\n", rchr, c_rchar);
	char	*rchr_ptr2 = ft_strrchr(rchr, c_rchar);
	if (rchr_ptr2 != NULL)
  		printf("    Encontrado en = %s \n\n", rchr_ptr2);
	else
		printf("    No encontrado \n\n");

	//teste do strncmp
	printf("------------------------------ ft_strncmp ------------------------------\n\n");
	char	cmp1[] = "Oi";
	char	cmp2[] = "Oi Meninos";
	size_t	c_cmp = 5;
	int		ret_cmp;

	ret_cmp = strncmp(cmp1, cmp2, c_cmp);
	if (ret_cmp < 0)
		printf("O . '%s' es menor que '%s' - Return = %d \n\n", cmp1, cmp2, ret_cmp);
	else if (ret_cmp > 0)
		printf("O . '%s' es maior que '%s' - Return = %d \n\n", cmp1, cmp2, ret_cmp);
	else if (ret_cmp == 0)
		printf("O . '%s' es igual a '%s' - Return = %d \n\n", cmp1, cmp2, ret_cmp);

	ret_cmp = ft_strncmp(cmp1, cmp2, c_cmp);
	if (ret_cmp < 0)
		printf("C . '%s' es menor que '%s' - Return = %d \n\n", cmp1, cmp2, ret_cmp);
	else if (ret_cmp > 0)
		printf("C . '%s' es maior que '%s' - Return = %d \n\n", cmp1, cmp2, ret_cmp);
	else if (ret_cmp == 0)
		printf("C . '%s' es igual a '%s' - Return = %d \n\n", cmp1, cmp2, ret_cmp);

//teste da vagaba da francinette
	ret_cmp = strncmp("test\200", "test\0", 6);

	if (ret_cmp < 0)
		printf("O . 'test 200' é menor que 'test 0' - Return = %d \n\n", ret_cmp);
	else if (ret_cmp > 0)
		printf("O . 'test 200' é maior que 'test 0' - Return = %d \n\n", ret_cmp);
	else if (ret_cmp == 0)
		printf("O . 'test 200' é igual a 'test 0' - Return = %d \n\n", ret_cmp);

	ret_cmp = ft_strncmp("test\200", "test\0", 6);

	if (ret_cmp < 0)
		printf("C . 'test 200' é menor que 'test 0' - Return = %d \n\n", ret_cmp);
	else if (ret_cmp > 0)
		printf("C . 'test 200' é maior que 'test 0' - Return = %d \n\n", ret_cmp);
	else if (ret_cmp == 0)
		printf("C . 'test 200' é igual a 'test 0' - Return = %d \n\n", ret_cmp);

//fim do teste - obrigada francinette

	//teste do memchr
	printf("------------------------------ ft_memchr ------------------------------\n\n");
	char	mchr[] = "Hello World";
	char	c_mchr = 'l';

	printf("O . En la frase = %s - busca el primeiro = %c\n\n", mchr, c_mchr);
	char	*mchr_ptr = memchr(mchr, c_mchr, (sizeof(mchr) - 1));
	if (mchr_ptr != NULL)
  		printf("    Encontrado en = %s \n\n", mchr_ptr);
	else
		printf("    No encontrado \n\n");

	printf("C . En la frase = %s - busca el primeiro = %c\n\n", mchr, c_mchr);
	mchr_ptr = ft_memchr(mchr, c_mchr, (sizeof(mchr) - 1));
	if (mchr_ptr != NULL)
  		printf("    Encontrado en = %s \n\n", mchr_ptr);
	else
		printf("    No encontrado \n\n");

// teste da francinette - que felicidade - porque nao da certo!?
	int teste6[7] = {-49, 49, 1, -1, 0, -2, 2};
    printf("O . %s\n\n", (char *)memchr(teste6, -1, 7));
	int teste9[7] = {-49, 49, 1, -1, 0, -2, 2};
    printf("C . %s\n\n", (char *)ft_memchr(teste9, -1, 7));
//fim do teste da francinette

	//teste do memcmp
	printf("------------------------------ ft_memcmp ------------------------------\n\n");

	char	mcmp1[] = "Oi";
	char	mcmp2[] = "Oi Meninos";
	size_t	c_mcmp = 3;
	int		ret_mcmp;

	ret_mcmp = memcmp(mcmp1, mcmp2, c_mcmp);
	if (ret_mcmp < 0)
		printf("O . '%s' es menor que '%s' - Return = %d \n\n", mcmp1, mcmp2, ret_mcmp);
	else if (ret_mcmp > 0)
		printf("O . '%s' es maior que '%s' - Return = %d \n\n", mcmp1, mcmp2, ret_mcmp);
	else if (ret_mcmp == 0)
		printf("O . '%s' es igual a '%s' - Return = %d \n\n", mcmp1, mcmp2, ret_mcmp);

	ret_mcmp = ft_memcmp(mcmp1, mcmp2, c_mcmp);
	if (ret_mcmp < 0)
		printf("C . '%s' es menor que '%s' - Return = %d \n\n", mcmp1, mcmp2, ret_mcmp);
	else if (ret_mcmp > 0)
		printf("C . '%s' es maior que '%s' - Return = %d \n\n", mcmp1, mcmp2, ret_mcmp);
	else if (ret_mcmp == 0)
		printf("C . '%s' es igual a '%s' - Return = %d \n\n", mcmp1, mcmp2, ret_mcmp);

	//teste do strnstr
	printf("------------------------------ ft_strnstr ------------------------------\n\n");
	char	strn_t[] = "O rato roeu a roupa do rei de roma";
	char	strn_b[] = "rom";

	printf("C . En la frase = %s\n\n    Busca por = %s\n\n", strn_t, strn_b);
	char	*strn_prt = ft_strnstr(strn_t, strn_b, 34);

	if (strn_prt)
  		printf("    Encontrado en = %s \n\n", strn_prt);
	else
		printf("    No encontrado \n\n");

	//teste do atoi
	printf("------------------------------ ft_atoi ------------------------------\n\n");
	char	t_atoi[] = "	-276";

	int		n_atoi = atoi(t_atoi);
	printf("O . numero = %d\n\n", n_atoi);

	n_atoi = ft_atoi(t_atoi);
	printf("C . numero = %d\n\n", n_atoi);

	//teste do calloc
	printf("------------------------------ ft_calloc ------------------------------\n\n");
	int n_cloc = 15;

	int *s1_cloc = calloc(n_cloc, sizeof(int));
	int *s2_cloc = ft_calloc(n_cloc, sizeof(int));

	ft_imprime_n(s1_cloc, n_cloc);
	ft_imprime_n(s2_cloc, n_cloc);
	free(s1_cloc);
	free(s2_cloc);
	s1_cloc = NULL;
	s2_cloc = NULL;

	//teste do strdup
	printf("------------------------------ ft_strdup ------------------------------\n\n");
	char	s_dup[] = "O rato roeu a roupa do rei de roma";
	char	*d1_dup = strdup(s_dup);
	char	*d2_dup = ft_strdup(s_dup);
	size_t	size_s = strlen(s_dup);
	size_t	size_d1 = strlen(d1_dup);
	size_t	size_d2 = strlen(d2_dup);

	printf("O . Frase = %s - size = %zu\n\n", s_dup, size_s);
	printf("O . Copia = %s - size = %zu\n\n", d1_dup, size_d1);
	free(d1_dup);
	printf("C . Frase = %s - size = %zu\n\n", s_dup, size_s);
	printf("C . Copia = %s - size = %zu\n\n", d2_dup, size_d2);
	free(d2_dup);

	printf("\n\n------------------------------ PARTE 2 ------------------------------\n\n");
	printf("Esta parte não tem função original\nsegue apenas as funções criadas\n\n");
	//teste do substr
	printf("------------------------------ ft_substr ------------------------------\n\n");
	char s_str[] = "bonjour mes amis";
	char *s_sub = ft_substr(s_str, 5, 8);
	printf("Frase = %s\n\nSubstring = %s\n\n", s_str, s_sub);
	free(s_sub);

	//teste do strjoin
	printf("------------------------------ ft_strjoin ------------------------------\n\n");
	char	s1_join[] = "bom ";
	char	s2_join[] = "dia";
	char	*d_join = ft_strjoin(s1_join, s2_join);
	printf("Frase = %s\n\n", d_join);
	free(d_join);

	//teste do strtrim
	printf("------------------------------ ft_strtrim ------------------------------\n\n");
	char	s_trim[] = "  \t \t \n   \n\n\n\t";
	char	*dest = ft_strtrim(s_trim, " \n\t");
	printf("Frase original = |%s|\n\n", s_trim);
	printf("Frase cortada  = |%s|\n\n", dest);
	free(dest);

	//teste do split
	printf("------------------------------ ft_split ------------------------------\n\n");
	char	s_spt [] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. ";
	char	**r_spt = ft_split(s_spt, ' ');
	int		i = 0;

	printf("Frase = %s\n\n", s_spt);
	while(r_spt[i])
	{
			ft_putstr_fd(r_spt[i], 1);
			ft_putstr_fd("|", 1);
			i++;
	}
	printf("\n\n");
	free (r_spt);

	//teste do itoa
	printf("------------------------------ ft_itoa ------------------------------\n\n");
	int	n_itoa = 2147483647;
	char	*r_itoa = ft_itoa(n_itoa);
	printf("En el INT = %d\n\n", n_itoa);
	printf("En la STR = %s\n\n", r_itoa);
	free(r_itoa);

	//teste do STRMAPI
	printf("------------------------------ ft_strmapi ------------------------------\n\n");
	char *r_smapi = ft_strmapi("AAAA", ft_addindex); // cada letra 'A'- ASCII 65 - ganha +i
	printf("En la STR = AAAA\n\nReturn = %s - size = %zu\n\n", r_smapi, ft_strlen(r_smapi));
	free(r_smapi);

	//teste do STRITERI
	printf("------------------------------ ft_striteri ------------------------------\n\n");
	char	s_iteri[] = "abcdef";
	printf("En la STR = %s\n\n", s_iteri);
	ft_striteri(s_iteri, ft_changepair);
	printf("Return = %s\n\n", s_iteri);

	//teste do PUTCHAR_FD
	printf("------------------------------ ft_putchar_fd ------------------------------\n\n");
	//comentado para nao criar o arquivo sempre que testar
/*	int	fd = open("arq-putchar.txt", O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (fd < 0)
		return (1);
	ft_putchar_fd('O', fd);
	ft_putchar_fd('i', fd);
	close(fd);
*/	printf("ARQUIVO 'arq-putchar.txt' CRIADO NO DIRETORIO ATUAL\n\n");

	//teste do PUTSTR_FD
	printf("------------------------------ ft_putstr_fd ------------------------------\n\n");
/*	int	fd = open("arq-putstr.txt", O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (fd < 0)
		return (1);
	ft_putstr_fd("Oi mundo", fd);
	close(fd);
*/	printf("ARQUIVO 'arq-putstr.txt' CRIADO NO DIRETORIO ATUAL\n\n");

	//teste do PUTENDL_FD
	printf("------------------------------ ft_putendl_fd ------------------------------\n\n");
/*	int	fd = open("arq-putendl.txt", O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (fd < 0)
		return (1);
	ft_putendl_fd("Oi mundo", fd);
	close(fd);
*/	printf("ARQUIVO 'arq-putstr.txt' CRIADO NO DIRETORIO ATUAL\n\n");

	//teste do PUTNBR_FD
	printf("------------------------------ ft_putnbr_fd ------------------------------\n\n");
/*	int	fd = open("arq-putnbr.txt", O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (fd < 0)
		return (1);
	ft_putnbr_fd(-2147483648, fd);
	close(fd);
*/	printf("ARQUIVO 'arq-putnbr.txt' CRIADO NO DIRETORIO ATUAL\n\n");
	// fim dos testes

	printf("------------------------------------------------------------------------\n\n");
	return (0);
}
