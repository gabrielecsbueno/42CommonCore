/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 01:01:22 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/15 12:46:17 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*dest;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	if (ft_strlen(set) == 0)
	{
		dest = ft_substr(s1, start, end);
		if (dest == NULL)
			return (NULL);
		return (dest);
	}
	while (start <= end && (ft_isset(s1[start], set) || ft_isset(s1[end], set)))
	{
		i = 0;
		while (set[i])
		{
			if (s1[start] == set[i])
				start++;
			if (s1[end] == set[i])
				end--;
			i++;
		}
	}
	dest = ft_substr(s1, start, (end - start + 1));
	if (dest == NULL)
		return (NULL);
	return (dest);
}
