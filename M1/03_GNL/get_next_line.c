/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:26:16 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/13 13:02:03 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Lê até os bytes do arquivo, com o tamanho definido pelo BUFFER, ate encontrar um pula linha

char	*get_next_line(int fd)
{
	char	*str;
	int		i;
	size_t	size;
	int		buffer = 100;
	char 	c;

	// preciso alocar memoria para str. mas como? tenho recebendo o BUFFER

	size = read(fd, &c, 1);
	if (size <= 0) //se deu erro (-1), ou esta no fim do arquivo (0) arquivo nao tem nada
	{
		return(NULL);
	}

	//to alocando 2 por enquanto, porque é para o primeiro caractere mesmo que /n e o /0 no fim
	str = (char *) malloc (2);
	if (!str)
		return(NULL);

	//se chagar aqui é pq tem coisa no c
	i = 0;
	str[i++] = c; //coloca o primeiro carctere
	str[i] = '\0'; //e o fim dele, porque o primeiro pode ser um \n

	while(c != '\n' && (size = read(fd, &c, 1)) > 0 && i <= buffer)
	{
		str = ft_join(str, c);
		i++;
	}
	if (size == -1)
    	return (NULL);
	return (str);
}
