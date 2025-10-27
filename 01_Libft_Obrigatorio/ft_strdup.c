/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:45:46 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/14 11:50:08 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(s);
	dest = (char *) malloc (sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s, size);
	dest[size] = '\0';
	return (dest);
}
