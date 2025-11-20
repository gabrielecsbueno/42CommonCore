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
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!resto)
		resto = ft_strdup("");
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
	}
	free(buffer);
	//talvez isso entao??
	if (!resto)
		return (NULL);

	index = ft_strindex(resto, '\n');
	temp = resto;
	line = ft_substr(resto, 0, index + 1);
	//aqui talvez
	if (!line)
	{
    	free(temp);
    	return (NULL);
	}
	// --
	resto = ft_substr(temp, index + 1, ft_strlen(temp) - index - 1);
	free(temp);
	return (line);
}