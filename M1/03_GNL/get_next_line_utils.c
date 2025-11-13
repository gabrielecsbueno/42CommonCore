/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:27:32 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/13 13:01:59 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_len(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_join(char *str, char c)
{
	char	*dest;
	size_t	i;
	size_t	len;

	// calcula o tamanho da string existente (retorna 0 se for NULL)
	len = ft_len(str);

	// aloca string recebida + caractere + nulo
	dest = (char *) malloc(len + 2);
	if (!dest)
		return (NULL);

	// copia conteúdo anterior (se tiver neh)
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}

	// adiciona o novo caractere
	dest[i++] = c;
	dest[i] = '\0';

	// libera a string antiga pra nao dar merda
	if (str)
		free(str);

	return (dest);
}