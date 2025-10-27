/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:29:42 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/23 13:03:49 by gabde-so         ###   ########.fr       */
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
		if (s[i])
		{
			cont++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cont);
}

static void	*ft_freealoc(int j, char **dest)
{
	while (j >= 0)
		free(dest[j--]);
	free(dest);
	return (NULL);
}

static char	**ft_destcpy(char const *s, char c, char **dest)
{
	int	j;
	int	i;
	int	start;

	j = 0;
	i = 0;
	while (s[i])
	{
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i != start)
		{
			dest[j] = ft_substr(s, start, (i - start));
			if (dest[j] == NULL)
				return (ft_freealoc(j, dest));
			j++;
		}
		if (s[i])
			i++;
	}
	dest[j] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = (char **) malloc (sizeof(char *) * (ft_contword(s, c) + 1));
	if (!dest)
		return (NULL);
	return (ft_destcpy(s, c, dest));
}
