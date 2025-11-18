#include "get_next_line.h"
#include <stdio.h> //printf
#include <fcntl.h> //open
#include <unistd.h> //close

int	main(int argc, char **argv)
{
	int		fd; //identificador do arquivo para manipulacao
	char	*line; //onde ira guardar o arquivo lido

/*--------------- essa parte aqui nao sera usada no resto oficial
	printf("%s\n", argv[0]);//nome do executabel
	printf("%s\n", argv[1]);//nome do primeiro argumento depois no nome do executavel
	printf("%d\n", argc);//quantidade de argumentos contando com o executavel
*/

	if (argc != 2)
	{
    	printf("É necessario um arquivo para leitura do programa!");
		return (-1);
    }

	// Abre o arquivo para leitura
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf ("Erro ao abrir o arquivo!");
		return (-1);
	}
	printf("Arquivo guardado no fd = %d\n", fd);

	// Passa para a funcao que retorna a linha lida
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		// Precisa fazer o free antes de chamar a proxima linha
		free(line);
		line = get_next_line(fd);
	}
	// Fecha o arquivo
    if (close(fd) == -1)
	{
        printf("Erro ao fechar o arquivo!");
		return (-1);
    }
	return (0);
}
