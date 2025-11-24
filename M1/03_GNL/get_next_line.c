/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:26:16 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/21 21:07:04 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free_resto(char **resto);
static char *ft_search_next_line(int fd, char *resto, char *buffer);

char	*get_next_line(int fd)
{
	static char	*resto = NULL;
	int			bytes_read;
	char		*buffer;
	int			index;
	char		*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		ft_free_resto(&resto);
		return (NULL);
	}
	if (!resto)
	{
		resto = ft_strdup("");
		if (!resto)
			return (NULL);
	}
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		ft_free_resto(&resto);
		return (NULL);
	}
	resto = ft_search_next_line(fd, resto, buffer);
	if (!resto)
			return (NULL);
	while (ft_strindex(resto, '\n') == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			ft_free_resto(&resto);
			return (NULL);
		}
		if (bytes_read == 0)
		{
			free(buffer);
			if (resto && resto[0] != '\0')
			{
				line = ft_strdup(resto);
				ft_free_resto(&resto);
				if (!line)
					return (NULL);
				return (line);
			}
			ft_free_resto(&resto);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = resto;
		resto = ft_strjoin(temp, buffer);
		free(temp);
		if (!resto)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	index = ft_strindex(resto, '\n');
	if (index)
	{
		line = ft_substr(resto, 0, index + 1);
		if (!line)
		{
			ft_free_resto(&resto);
			return (NULL);
		}
		temp = resto;
		resto = ft_substr(temp, index + 1, ft_strlen(resto) - index - 1);
		free(temp);
		if (!resto)
		{
			free(line);
			resto = NULL;
			return (NULL);
		}
		return (line);
	}
	line = ft_strdup(resto);
	ft_free_resto(&resto);
	if (!line)
		return (NULL);
	return (line);
}

static void	ft_free_resto(char **resto)
{
	if (resto && *resto)
	{
		free(*resto);
		*resto = NULL;
	}
}
/*
static char *ft_search_next_line(int fd, char *resto, char *buffer)
{
	int			bytes_read;
	char		*temp;

	while (ft_strindex(resto, '\n') == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			ft_free_resto(&resto);
			return (NULL);
		}
		if (bytes_read == 0)
		{
			free(buffer);
			if (resto && resto[0] != '\0')
				return (resto);
			ft_free_resto(&resto);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = resto;
		resto = ft_strjoin(temp, buffer);
		free(temp);
		if (!resto)
		{
			free(buffer);
			return (NULL);
		}
	}
	return (resto);
}
	*/