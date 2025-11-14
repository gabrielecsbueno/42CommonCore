/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:26:16 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/14 17:11:47 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//nao sei se realmente posso fazer isso
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif


char	*get_next_line(int fd)
{
	static char	*resto; //depois mudar o nome para ingles
	char		*line;
	int 		bytes_read;
	int			i;

	line = (char *) malloc(BUFFER_SIZE + 1);

    // ve se tem algo no 'resto' da última chamada
	i = 0;
	if (resto)
	{
		if (resto[i] == '\n' && ft_strlen(resto) == (i + 1))
		{
			line = ft_realloc(resto, BUFFER_SIZE + 1, i + 1);
			return (resto);
		}
		//ve se tem um \n
		//se tiver ele retorna ate o \n
	}
    // 2. Se não, lê BUFFER_SIZE bytes do arquivo
    // 3. Procura por \n no que foi lido
    // 4. Se encontrou: retorna linha + guarda o resto
    // 5. Se não encontrou: continua lendo
}