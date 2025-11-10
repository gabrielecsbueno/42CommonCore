#include "get_next_line.h"
#include <stdio.h> //printf
#include <fcntl.h> //open
#include <unistd.h> //close

int	main(int argc, char **argv)
{
	int		fd; //identificador do arquivo para manipulacao
	size_t	size_arq; //tamanho dos bites lidos
	char	*str; //onde ira guardar o arquivo lido
	int		i;

//--------------- essa parte aqui nao sera usada no reste oficial
	int buffer = 1024; // o BUFFER_SIZE vai ser passado pela flag
	str = (char *) malloc (buffer);

	printf("%s\n", argv[0]);//nome do executabel
	printf("%s\n", argv[1]);//nome do primeiro argumento depois no nome do executavel
	printf("%d\n", argc);//quantidade de argumentos contando com o executavel
//

	if (argc != 2)
	{
    	printf("É necessario um arquivo para leitura do programa!");
		free(str);
		return (-1);
    }

	// Abre o arquivo para leitura
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf ("Erro ao abrir o arquivo!");
		free(str);
		return (-1);
	}
	printf("Arquivo = %d\n", fd);

	// Lê até os bytes do arquivo, definido pelo BUFFER, ate encontrar um pula linha
	i = 0;
	while (str[i - 1] != '\n' && i <= buffer)
	{
		size_arq = read(fd, str + i, 1);
		i++;

		if (size_arq == -1)
		{
       		printf("Erro ao ler do arquivo!");
       		close(fd);
			free(str);
       		return (-1);
		}
	}

    // Adiciona um caractere nulo no final do buffer para criar uma string
    str[i] = '\0';

	// Imprimir o retorno do arquivo
	printf("%s", str);
	printf("Size = %d\n", i);

	// Precisa fazer o free
	free(str);

	// Fecha o arquivo
    if (close(fd) == -1)
	{
        printf("Erro ao fechar o arquivo!");
		return (-1);
    }
	return (0);
}