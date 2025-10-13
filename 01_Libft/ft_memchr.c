/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:41:58 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/10 18:25:05 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*byte_s;
	unsigned int		byte_c;
	size_t				i;

	byte_s = (const unsigned char *)s;
	byte_c = (unsigned int)c;
	i = 0;
	while (i < n)
	{
		if (byte_c == byte_s[i])
			return ((void *) (byte_s + i));
		i++;
	}
	return (NULL);
}
