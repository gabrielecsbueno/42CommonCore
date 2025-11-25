/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:26:16 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/25 10:45:02 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free_remainder(char **remainder);
static char	*ft_search_next_line(int fd, char **remainder);
static char	*ft_update_remainder(char *remainder, int index);

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	int			index;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_remainder(&remainder), NULL);
	if (!remainder)
		remainder = ft_strdup("");
	if (!remainder)
		return (NULL);
	remainder = ft_search_next_line(fd, &remainder);
	if (!remainder)
		return (NULL);
	index = ft_strindex(remainder, '\n');
	if (index != -1)
	{
		line = ft_substr(remainder, 0, index + 1);
		if (!line)
			return (ft_free_remainder(&remainder), NULL);
		remainder = ft_update_remainder(remainder, index);
		return (line);
	}
	line = ft_strdup(remainder);
	ft_free_remainder(&remainder);
	return (line);
}

static void	ft_free_remainder(char **remainder)
{
	if (remainder && *remainder)
	{
		free(*remainder);
		*remainder = NULL;
	}
}

static char	*ft_search_next_line(int fd, char **remainder)
{
	int			bytes_read;
	char		*temp;
	char		*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free_remainder(remainder), NULL);
	while (ft_strindex(*remainder, '\n') == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read == 0 && *remainder && (*remainder)[0] != '\0')
				return (free(buffer), *remainder);
			return (ft_free_remainder(remainder), free(buffer), NULL);
		}
		buffer[bytes_read] = '\0';
		temp = *remainder;
		*remainder = ft_strjoin(temp, buffer);
		free(temp);
		if (!*remainder)
			return (free(buffer), ft_free_remainder(remainder), NULL);
	}
	return (free(buffer), *remainder);
}

static char	*ft_update_remainder(char *remainder, int index)
{
	char	*temp;

	temp = remainder;
	remainder = ft_substr(temp, index + 1, ft_strlen(remainder) - index - 1);
	free(temp);
	return (remainder);
}
