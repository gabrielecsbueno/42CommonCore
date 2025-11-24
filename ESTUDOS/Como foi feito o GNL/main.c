#include "get_next_line.h"
#include <stdio.h> //printf
#include <fcntl.h> //open
#include <unistd.h> //close

/*
ATENCAO AO QUERIDOS

Um teste interessante para fazer e verificar os leaks de memorias. Para isso, no terminal compile:

cc -Wall -Wextra -Werror *.c -g
valgrind --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./a.out

OU (no meu caso):

clang -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 *.c && valgrind --tool=memcheck -q --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./a.out *.txt | cat -e
*/
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
    		printf("É necessario um arquivo para leitura do programa!");
		return (-1);
    	}
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
		printf(" --- %s \n", line);
		// Precisa fazer o free antes de chamar a proxima linha
		free(line);
		line = get_next_line(fd);
	}

	line = get_next_line(fd);
	printf(" --- %s \n", line);
	free(line);

	if (close(fd) == -1)
	{
		printf("Erro ao fechar o arquivo!");
		return (-1);
	}
	return (0);
}
