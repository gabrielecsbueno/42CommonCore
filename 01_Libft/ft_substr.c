/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:31:05 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/13 12:19:37 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*d;

	d = ft_strdup(s);
	if (d == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		d[i] = start + i;
		i++;
	}
	d[i] = '\0';
	return (d);
}
