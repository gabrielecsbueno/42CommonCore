/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:27:32 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/14 17:02:16 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//static size_t	ft_strlen(const char *s);

/*
char	*ft_join(char *str, char c)
{
	char	*dest;
	size_t	i;
	size_t	len;

	// calcula o tamanho da string existente (retorna 0 se for NULL)
	len = ft_strlen(str);
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
*/
void	*ft_realloc(void *str, size_t old_size, size_t new_size)
{
	void			*dest;
	unsigned char	*byte_s;
	unsigned char	*byte_d;
	size_t			i;

	if (!str)
	{
		dest = malloc(new_size);
		if (!dest)
			return (NULL);
		return (dest);
	}
	if (new_size == 0)
	{
		free(str);
		return (NULL);
	}
	dest = malloc(new_size);
	if (!dest)
		return (NULL);
	byte_s = (unsigned char *)str;
	byte_d = (unsigned char *)dest;
	i = 0;
	while (i < old_size && i < new_size)
	{
		byte_d[i] = byte_s[i];
		i++;
	}
	while (i < new_size)
		byte_d[i++] = 0;
	free(str);
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
