/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:29:42 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/20 16:05:01 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contword(char const *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			cont++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cont);
}

static int	ft_freeonnull(char **dest, int j)
{
	if (dest[j] == NULL)
	{
		while (j >= 0)
			free(dest[j--]);
		free(dest);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		start;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	dest = (char **) malloc (sizeof(char *) * (ft_contword(s, c) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i != start)
		{
			dest[j] = ft_substr(s, start, (i - start));
			if (ft_freeonnull(dest, j) == 0)
				return (NULL);
			j++;
		}
		if (s[i])
			i++;
	}
	dest[j] = NULL;
	return (dest);
}
