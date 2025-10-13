/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:05:31 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/10 17:21:48 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*byte_s1;
	const unsigned char	*byte_s2;

	byte_s1 = (const unsigned char *)s1;
	byte_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (byte_s1[i] < byte_s2[i])
			return (byte_s1[i] - byte_s2[i]);
		if (byte_s1[i] > byte_s2[i])
			return (byte_s1[i] - byte_s2[i]);
		i++;
	}
	return (0);
}
