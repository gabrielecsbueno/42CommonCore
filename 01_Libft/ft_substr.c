/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:31:05 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/14 12:21:05 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*d;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		d = (char *) malloc (1);
		if (!d)
			return (NULL);
		d[0] = '\0';
		return (d);
	}
	if (len > slen - start)
		len = slen - start;
	d = (char *) malloc (len + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
