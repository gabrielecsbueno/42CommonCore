/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:29:42 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/16 10:29:47 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int	start;
	int	end;
	int	i;

	start = 0;
	end = ft_strlen(s) - 1;
	i = 0;
	while (s[i] != c)
		i++;
	dest = (char**)malloc(sizeof(s) + 2);
	dest[0] = (char*)malloc(sizeof(char) * (i + 1));
	if (dest[0] == NULL)
	{
		free(dest);
		return (NULL);
	}
	dest[0] = ft_substr(s, start, (i + 1));
	dest[1] = (char*)malloc(sizeof(char) * (end - i + 1));
	if (dest[1] == NULL)
	{
		free(dest[0]);
		free(dest);
		return (NULL);
	}
	dest[1] = ft_substr(s, (i + 1), (end - i + 1));
	return (dest);
}

