/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:26:16 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/18 10:20:16 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*resto = NULL;
	size_t		bytes_read;
	char		*buffer;
	size_t		index;
	char		*temp;
	char		*line;//vai esta em uma funcao

//antes de comecar o loop
	//verificacao inicial
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//iniciacao do buffer
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return(NULL);
	//iniciacao do resto se nao tiver iniciado
	if(!resto)
		resto = (char *)malloc(1);

//loop principal
	//ENQUANTO não encontrou uma linha completa
	while (!ft_strchr(resto, '\n') && bytes_read)
	{
		//le o arquivo nos proximos BUFFER_SIZE
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		//fecha ele para nao esta aberto
		buffer[bytes_read] = '\n';
		//usa um temporario para guardar o que foi pego no loop anterior
		temp = *resto;
		//aloca o novo valor de resto com o que foi lido no loop
		resto = ft_strjoin(temp, buffer);
		//libera o temporario para a proxima utilizacao
		free(temp);
	}
	free(buffer);
	//agora tem uma linha completa no 'resto'
	//procura onde esta o \n e retorna o indice
	index = ft_strindex(resto, '\n');
	//SE TEM \n (index)
	if (index)
	{
		//passa para o temporario
		temp = *resto;
		//copia o resto ate o \n para a linha
		line = ft_substr(resto, 0, index);
		//ESTOU AQUI
	}


	while (/*não encontrou uma linha completa */)
	{
		//SE tem conteúdo no 'resto'
		if (resto)
		{
			//PROCURA \n no resto
			//SE encontrou \n
			if (index != 0)
			{
				//RETORNA linha + ATUALIZA resto
				line = ft_substr(resto, 0, index);
				resto = ft_substr(resto, index + 1, ft_strlen(resto));
			}
		}
	}
//    SENÃO:
//        LÊ BUFFER_SIZE bytes
//        SE leu 0 bytes (EOF):
//            RETORNA o que tem no resto (se tiver)
//        SE leu -1 (erro):
//            RETORNA NULL
//        ADICIONA o lido ao resto

}

/*
char	*get_next_line(int fd)
{
	static char		*leftover; //depois mudar o nome para ingles
	char			*line;
	int 			bytes_read;
	size_t			i;

	line = (char *) malloc(BUFFER_SIZE + 1);

    // ve se tem algo no 'resto' da última chamada
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;


	if (i > 0) //se tiver \n
	{
		line = ft_substr(leftover, 0, i); //copia para line so ate o \n
		leftover = ft_substr(leftover, (i + 1), ft_strlen(leftover)); //guarda o resto no resto
		return (line); //retorna a line
	}

	while (leftover)
	{
		i++;
		//ve se tem um \n
		//se tiver ele retorna ate o \n
	}
    // se não, lê BUFFER_SIZE bytes do arquivo
    // procura por \n no que foi lido
    // se encontrou: retorna linha + guarda o resto
    // se não encontrou: continua lendo
}
*/