#include "includes.h"
#include <stdio.h>

#include <limits.h>

// --- Define colors ---
#define GREEN   "\033[0;32m"
#define RED     "\033[0;31m"
#define RESET   "\033[0m"

int	main(void)
{
	printf("------------------------------------------------------------------------------------------------\n\n");
	printf("---------------------------------- TESTE DA FUNCAO FT_PRINTF -----------------------------------\n\n");

	int	ret_original;
	int	ret_criada;

	printf("---------------------------------- Teste apenas um texto  --------------------------------------\n\n");

	printf("- PRINTF\n\n");
	ret_original = printf("Esse aqui é apenas um texto\n\n");
	printf("Retorno da original = %d\n\n", ret_original);

	printf("- FT_PRINTF\n\n");
	ret_criada = ft_printf("Esse aqui é apenas um texto\n\n");
	printf("Retorno da criada   = %d\n\n", ret_criada);

	if (ret_original == ret_criada)
		printf(GREEN "TESTE = OK :)\n\n" RESET);
	else
		printf(RED "TESTE = KO :(\n\n" RESET);

	printf("---------------------------------------- Teste do %%  -------------------------------------------\n\n");

	printf("- PRINTF\n\n");
	ret_original = printf("Caractere = %%\n");
	printf("Retorno da original = %d\n\n", ret_original);

	printf("- FT_PRINTF\n\n");
	ret_criada = ft_printf("Caractere = %%\n");
	printf("Retorno da criada   = %d\n\n", ret_criada);

	if (ret_original == ret_criada)
		printf(GREEN "TESTE = OK :)\n\n" RESET);
	else
		printf(RED "TESTE = KO :(\n\n" RESET);

	printf("--------------------------------------- Teste do %%c  -------------------------------------------\n\n");

	char	c = 'a';

	printf("- PRINTF\n\n");
	ret_original = printf("Caractere = %c\n", c);
	printf("Retorno da original = %d\n\n", ret_original);

	printf("- FT_PRINTF\n\n");
	ret_criada = ft_printf("Caractere = %c\n", c);
	printf("Retorno da criada   = %d\n\n", ret_criada);

	if (ret_original == ret_criada)
		printf(GREEN "TESTE = OK :)\n\n" RESET);
	else
		printf(RED "TESTE = KO :(\n\n" RESET);

	printf("--------------------------------------- Teste do %%s  -------------------------------------------\n\n");

	char	*str = "Bom dia";

	printf("- PRINTF\n\n");
	ret_original = printf("String = %s\n", str);
	printf("Retorno da original = %d\n\n", ret_original);

	printf("- FT_PRINTF\n\n");
	ret_criada = ft_printf("String = %s\n", str);
	printf("Retorno da criada   = %d\n\n", ret_criada);

	if (ret_original == ret_criada)
		printf(GREEN "TESTE = OK :)\n\n" RESET);
	else
		printf(RED "TESTE = KO :(\n\n" RESET);

	printf("--------------------------------------- Teste do %%p  -------------------------------------------\n\n");

	char	*ptr_c = "Buenos dias meu povo bonito";
	int		ptr_i[] = {10, 20, 30, 40, 50, 60, 0};

	printf("- PRINTF\n\n");
	ret_original = printf("%p\n", ptr_i);
	printf("Retorno da original ponteiro int  = %d\n\n", ret_original);

	printf("- FT_PRINTF\n\n");
	ret_criada = ft_printf("%p\n", ptr_i);
	printf("Retorno da original ponteiro int  = %d\n\n", ret_criada);
	
	if (ret_original == ret_criada)
		printf(GREEN "TESTE = OK :)\n\n" RESET);
	else
		printf(RED "TESTE = KO :(\n\n" RESET);
	
	printf("- PRINTF\n\n");
	ret_original = printf("%p\n", ptr_c);
	printf("Retorno da original ponteiro char = %d\n\n", ret_original);
	
	printf("- FT_PRINTF\n\n");
	ret_criada = ft_printf("%p\n", ptr_c);
	printf("Retorno da original ponteiro char = %d\n\n", ret_criada);

	if (ret_original == ret_criada)
		printf(GREEN "TESTE = OK :)\n\n" RESET);
	else
		printf(RED "TESTE = KO :(\n\n" RESET);

	printf("--------------------------------------- Teste do %%d  -------------------------------------------\n\n");

	int	n = -10;

	printf("- PRINTF\n\n");
	ret_original = printf("Decimal = %d\n", n);
	printf("Retorno da original = %d\n\n", ret_original);

	printf("- FT_PRINTF\n\n");
	ret_criada = ft_printf("Decimal = %d\n", n);
	printf("Retorno da criada   = %d\n\n", ret_criada);

	if (ret_original == ret_criada)
		printf(GREEN "TESTE = OK :)\n\n" RESET);
	else
		printf(RED "TESTE = KO :(\n\n" RESET);

	printf("--------------------------------------- Teste do %%i  -------------------------------------------\n\n");

	int	i = 20;

	printf("- PRINTF\n\n");
	ret_original = printf("Inteiro em base 10 = %i\n", i);
	printf("Retorno da original = %d\n\n", ret_original);

	printf("- FT_PRINTF\n\n");
	ret_criada = ft_printf("Inteiro em base 10 = %i\n", i);
	printf("Retorno da criada   = %d\n\n", ret_criada);

	if (ret_original == ret_criada)
		printf(GREEN "TESTE = OK :)\n\n" RESET);
	else
		printf(RED "TESTE = KO :(\n\n" RESET);

	printf("--------------------------------------- Teste do %%u  -------------------------------------------\n\n");

	int	u = -20;

	printf("- PRINTF\n\n");
	ret_original = printf("Decimal sem sinal = %u\n", u);
	printf("Retorno da original = %d\n\n", ret_original);

	printf("- FT_PRINTF\n\n");
	ret_criada = ft_printf("Decimal sem sinal = %u\n", u);
	printf("Retorno da criada   = %d\n\n", ret_criada);

	if (ret_original == ret_criada)
		printf(GREEN "TESTE = OK :)\n\n" RESET);
	else
		printf(RED "TESTE = KO :(\n\n" RESET);
		
	printf("--------------------------------------- Teste do %%x  -------------------------------------------\n\n");

	int	x1 = 605;

	printf("- PRINTF\n\n");
	ret_original = printf("Hexadecimal de %d  = %x\n", x1, x1);
	printf("Retorno da original = %d\n\n", ret_original);
	
	printf("- FT_PRINTF\n\n");
	ret_criada = ft_printf("Hexadecimal de %d  = %x\n", x1, x1);
	printf("Retorno da original = %d\n\n", ret_criada);

	if (ret_original == ret_criada)
		printf(GREEN "TESTE = OK :)\n\n" RESET);
	else
		printf(RED "TESTE = KO :(\n\n" RESET);
	
	printf("--------------------------------------- Teste do %%X  -------------------------------------------\n\n");

	int	x2 = 605;

	printf("- PRINTF\n\n");
	ret_original = printf("Hexadecimal de %d  = %X\n", x2, x2);
	printf("Retorno da original = %d\n\n", ret_original);
	
	printf("- FT_PRINTF\n\n");
	ret_criada = ft_printf("Hexadecimal de %d  = %X\n", x1, x1);
	printf("Retorno da original = %d\n\n", ret_criada);

	if (ret_original == ret_criada)
		printf(GREEN "TESTE = OK :)\n\n" RESET);
	else
		printf(RED "TESTE = KO :(\n\n" RESET);
	
	printf("---------------------------------------- FIM DOS TESTES ----------------------------------------\n\n");

	return (0);
}
