/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:05:48 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/10 16:10:16 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*byte_s;
	unsigned char		*byte_d;

	byte_s = (const unsigned char *)src;
	byte_d = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		byte_d[i] = byte_s[i];
		i++;
	}
	return (dest);
}
