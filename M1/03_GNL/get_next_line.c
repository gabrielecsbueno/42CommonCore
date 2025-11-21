/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:26:16 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/20 20:20:02 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (resto)
		{
			free(resto);
			resto = NULL;
		}
		return (NULL);
	}
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		if (resto)
		{
			free(resto);
			resto = NULL;
		}
		return (NULL);
	}
	if (!resto)
	{
		resto = ft_strdup("");
		if (!resto)
		{
			free(buffer);
			return (NULL);
		}
	}
	while (ft_strindex(resto, '\n') == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(resto);
			resto = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
		{
			free(buffer);
			if (resto && resto[0] != '\0')
			{
				line = ft_strdup(resto);
				free(resto);
				resto = NULL;
				if (!line)
					return (NULL);
				return (line);
			}
			if (resto)
				free(resto);
			resto = NULL;
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
	if (!resto)
		return (NULL);

	index = ft_strindex(resto, '\n');
	line = ft_substr(resto, 0, index + 1);
	if (!line)
	{
		free(resto);
		resto = NULL;
		return (NULL);
	}
	temp = ft_substr(resto, index + 1, ft_strlen(resto) - index - 1);
	free(resto);
	if (!temp)
	{
		free(line);
		resto = NULL;
		return (NULL);
	}
	resto = temp;
	return (line);
}