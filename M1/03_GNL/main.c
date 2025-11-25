/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:06:23 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/25 11:10:08 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //printf
#include <fcntl.h> //open
#include <unistd.h> //close

/*
ATENCAO AO QUERIDOS

Um teste interessante para fazer e verificar os leaks de memorias.
Para isso, no terminal compile:

cc -Wall -Wextra -Werror *.c -g
valgrind --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./a.out

OU (no meu caso):

clang -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 *.c && valgrind --tool=memcheck
-q --leak-check=full --show-leak-kinds=all -s --track-origins=yes
./a.out *.txt | cat -e

no mac

leaks --atExit -- ./a.out *.txt

*/

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	printf("FD = %d do arquivo = %d\n\n", fd, argc);
	printf("Conteudo do Arquivo:\n\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("	%s \n", line);
		free(line);
		line = get_next_line(fd);
	}
	line = get_next_line(fd);
	printf("%s \n", line);
	free(line);
	if (close(fd) == -1)
	{
		printf("Erro ao fechar o arquivo!");
		return (-1);
	}
	return (0);
}
