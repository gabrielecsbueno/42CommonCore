/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:27:32 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/17 15:35:36 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//busca um \n em um str, retorna o indice se encontrar ou NULL se nao
int	ft_strindex(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*d;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (len > slen - start)
		len = slen - start;
	d = (char *) malloc (len + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	dest = (char *) malloc ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		dest[j++] = s2[i++];
	}
	dest[j] = '\0';
	return (dest);
}

//essa tem que tirar e juntar no de baixo
static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*byte_s;
	unsigned char		*byte_d;

	if (!dest && !src)
		return (NULL);
	byte_s = (const unsigned char *)src;
	byte_d = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		byte_d[i] = byte_s[i];
		i++;
	}
	return (dest);
}
// --------------
char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(s);
	dest = (char *) malloc (sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s, size);
	dest[size] = '\0';
	return (dest);
}

/*
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *) s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_isline(const char *s)
{
	while(*s)
	{
		if (*s == '\n')
			return (1);
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(s);
	dest = (char *) malloc (sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s, size);
	dest[size] = '\0';
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	dest = (char *) malloc ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		dest[j++] = s2[i++];
	}
	dest[j] = '\0';
	return (dest);
}

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



char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*d;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (len > slen - start)
		len = slen - start;
	d = (char *) malloc (len + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	free(s);
	return (d);
}
*/
