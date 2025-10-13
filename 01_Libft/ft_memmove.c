/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:38:33 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/10 16:29:19 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*byte_s;
	unsigned char		*byte_d;

	byte_s = (const unsigned char *)src;
	byte_d = (unsigned char *)dest;
	if (byte_d == byte_s || n == 0)
		return (dest);
	if (byte_s > byte_d)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			n--;
			byte_d[n] = byte_s[n];
		}
	}
	return (dest);
}
